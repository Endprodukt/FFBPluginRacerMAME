local log = io.open("CalSpeedRawOutputs.log", "w")
if not log then
    emu.print_error("CalSpeedRawOutputs: could not open CalSpeedRawOutputs.log")
    return
end

_G.calspeed_raw_log = log

local frame = 0
local sequence = 0
local last_values = {}
local discovered = {}
local marker_codes = {}

local function signed8(value)
    local byte = value % 256
    if byte >= 128 then
        return byte - 256
    end
    return byte
end

local function safe_code(token)
    local ok, code = pcall(function()
        return manager.machine.input:code_from_token(token)
    end)
    if ok then
        return code
    end
    return nil
end

marker_codes = {
    { token = "KEYCODE_M", label = "DROP_GENERIC", code = safe_code("KEYCODE_M") },
    { token = "KEYCODE_L", label = "LEFT_ONLY_LOST", code = safe_code("KEYCODE_L") },
    { token = "KEYCODE_R", label = "RIGHT_ONLY_LOST", code = safe_code("KEYCODE_R") },
    { token = "KEYCODE_B", label = "BOTH_DIRECTIONS_LOST", code = safe_code("KEYCODE_B") }
}

local function write_output_snapshot(prefix, machine)
    for tag, device in pairs(machine.devices) do
        for key_name, proxy in pairs(device.outputs) do
            if proxy:exists() then
                local name = proxy:name() or key_name
                local value = proxy:get()
                log:write(string.format(
                    "%s emu_s=%.6f frame=%d device=%s name=%s value=%d hex=%02X signed8=%d\n",
                    prefix,
                    machine.time:as_double(),
                    frame,
                    tostring(tag),
                    tostring(name),
                    value,
                    value % 256,
                    signed8(value)))
            end
        end
    end
end

local function root_output(root, name)
    if not root then
        return nil
    end
    local proxy = root:output(name)
    if proxy and proxy:exists() then
        return proxy:get()
    end
    return nil
end

log:write("# California Speed raw MAME output logger\n")
log:write("# Passive diagnostic only. No output values are modified.\n")
log:write("# Marker keys: M=generic drop, L=left only lost, R=right only lost, B=both directions lost\n")
log:write("# CHANGE columns include raw decimal, low-byte hex, signed-8 view, previous value, and frame/time gap.\n")
log:flush()

_G.calspeed_raw_frame_sub = emu.add_machine_frame_notifier(function()
    local machine = manager.machine
    frame = frame + 1
    local emu_s = machine.time:as_double()

    -- Discover every output exposed by every device and log every value change.
    for tag, device in pairs(machine.devices) do
        for key_name, proxy in pairs(device.outputs) do
            if proxy:exists() then
                local name = proxy:name() or key_name
                local key = tostring(tag) .. "|" .. tostring(name)
                local value = proxy:get()

                if not discovered[key] then
                    discovered[key] = true
                    last_values[key] = {
                        value = value,
                        frame = frame,
                        time = emu_s
                    }
                    log:write(string.format(
                        "DISCOVER emu_s=%.6f frame=%d device=%s name=%s value=%d hex=%02X signed8=%d\n",
                        emu_s,
                        frame,
                        tostring(tag),
                        tostring(name),
                        value,
                        value % 256,
                        signed8(value)))
                else
                    local previous = last_values[key]
                    if previous.value ~= value then
                        sequence = sequence + 1
                        log:write(string.format(
                            "CHANGE seq=%d emu_s=%.6f frame=%d device=%s name=%s value=%d hex=%02X signed8=%d prev=%d prevHex=%02X delta=%d framesSince=%d msSince=%.3f\n",
                            sequence,
                            emu_s,
                            frame,
                            tostring(tag),
                            tostring(name),
                            value,
                            value % 256,
                            signed8(value),
                            previous.value,
                            previous.value % 256,
                            value - previous.value,
                            frame - previous.frame,
                            (emu_s - previous.time) * 1000.0))

                        last_values[key] = {
                            value = value,
                            frame = frame,
                            time = emu_s
                        }
                    end
                end
            end
        end
    end

    -- One frame-by-frame line for the known steering-related outputs. This
    -- preserves the time dimension even when an output does not change.
    local root = machine.devices[":"]
    local wheel_motor = root_output(root, "wheel_motor")
    local wheel = root_output(root, "wheel")
    local m_wheel_motor = root_output(root, "m_wheel_motor")
    log:write(string.format(
        "FRAME emu_s=%.6f frame=%d wheel_motor=%s wheel_motor_signed8=%s wheel=%s m_wheel_motor=%s\n",
        emu_s,
        frame,
        wheel_motor == nil and "NA" or tostring(wheel_motor),
        wheel_motor == nil and "NA" or tostring(signed8(wheel_motor)),
        wheel == nil and "NA" or tostring(wheel),
        m_wheel_motor == nil and "NA" or tostring(m_wheel_motor)))

    -- Manual markers for the exact moment a physical FFB failure is felt.
    for _, marker in ipairs(marker_codes) do
        if marker.code then
            local ok, pressed = pcall(function()
                return machine.input:code_pressed_once(marker.code)
            end)
            if ok and pressed then
                log:write(string.format(
                    "MARKER label=%s emu_s=%.6f frame=%d wheel_motor=%s wheel_motor_signed8=%s wheel=%s m_wheel_motor=%s\n",
                    marker.label,
                    emu_s,
                    frame,
                    wheel_motor == nil and "NA" or tostring(wheel_motor),
                    wheel_motor == nil and "NA" or tostring(signed8(wheel_motor)),
                    wheel == nil and "NA" or tostring(wheel),
                    m_wheel_motor == nil and "NA" or tostring(m_wheel_motor)))
                write_output_snapshot("MARKER_OUTPUT", machine)
                log:flush()
            end
        end
    end

    if frame % 60 == 0 then
        log:flush()
    end
end)

_G.calspeed_raw_stop_sub = emu.add_machine_stop_notifier(function()
    if _G.calspeed_raw_log then
        _G.calspeed_raw_log:write(string.format("# STOP frame=%d changes=%d\n", frame, sequence))
        _G.calspeed_raw_log:flush()
        _G.calspeed_raw_log:close()
        _G.calspeed_raw_log = nil
    end
end)
