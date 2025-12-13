# FFB Arcade Plugin

Brought to you by Boomslangnz, Ducon2016, Spazzy, Adam_, jpb, Rocco & pinkimo and a bit of Endprodukt.

This is a plugin to provide Force Feedback and Rumble to various arcade games.


## Requirements

- Requires Visual Runtime Files https://www.techpowerup.com/download/visual-c-redistributable-runtime-package-all-in-one/

- GUI Requires Visual Runtime 2019 and has to be in same folder with metroframework.dll & SDL2.dll


## How to Use

Launch FFBPluginGUI.exe & Go to Setup Help Section. 

For more advanced information read below


## Advanced information

Alternative FFB is for certain wheels such as Thrustmaster wheels or PWM2M2 etc where rotation always goes only 1 direction, enable this to fix if your wheel does this

MinForce is the lowest force the wheel strength will be, if AlternativeFFB is enabled, use AlternativeFFB MinForce instead.

MaxForce is the maximum force the wheel strength will be, if AlternativeFFB is enabled, use AlternativeFFB MaxForce instead.

Feedback length is how long the force feedback effect will last for

Enable Rumble is to enable or disable Rumble for controllers

Reverse Rumble is to swap the motors around if it rumbles opposite to how you want

PowerMode is to raise the strength of low values to increase strength feel on certain games

Enable ConstantInf is an alternative way of providing effects to the wheel. Test it enabled and see if FFB becomes less erratic. 

## Output Support 

### For MAME

Create a ini file on root of MAME folder called Mame.ini and place inside it and save

```
#
# OSD OUTPUT OPTIONS
#
output                    windows
```

Ensure either MAME32.dll or MAME64.dll is with FFB Plugin files in MAME folder depending on 32bit or 64bit MAME

## SUPPORTED GAMES

### MAME ONLY:

- Ace Driver
- Ace Driver: Victory Lap
- California Speed
- Chase Bombers
- Cisco Heat
- Crusn'USA
- Crusn' World
- Daytona USA
- F-1 Grand Prix Star
- F-1 Grand Prix Star II
- GTI Club
- Hard Drivin'
- Hyperdrive
- Midnight Run
- Outrun
- OffRoad Challenge
- Outrunners
- Overrev (need to change output mode in service)
- Power Drift
- Race Drivin'
- Racing Jam
- Racing Jam 2
- Rave Racer (Feedback needs to be activated in the service menu)(you can invert the ffb effect in the gui for standard/deluxe mode)
- Roads Edge
- San Francisco Rush
- San Francisco Rush The Rock
- San Francisco Rush 2049
- Sega Rally Championship
- Sega Touring Car Championship
- Super GT 24h (output works but analog input is broken)
- Thrill Drive
- Turbo Outrun
- Vapor TRX
- Virtua Racing (CHANGE TO UPRIGHT CABINET)
- Winding Heat
- Xtreme Rally

