# FFB Arcade Plugin

Brought to you by Boomslangnz, Ducon2016, Spazzy, Adam_, jpb, Rocco & pinkimo and a bit of Endprodukt.

This is a plugin to provide Force Feedback and Rumble to various arcade games.


## Requirements

- Requires Visual Runtime Files https://www.techpowerup.com/download/visual-c-redistributable-runtime-package-all-in-one/

- GUI Requires Visual Runtime 2019 and has to be in same folder with metroframework.dll & SDL2.dll


## How to Use

Launch FFBPluginGUI.exe & Go to Setup Help Section. 

All files should be copied to your Mame-Folder. 
The problem of remaining FFB effects after closing a game has been fixed but it can only detach when closing Mame entirely, not by going back to Mames UI! 

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
- Dirt Dash
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
- Side By Side* (READ INFO!)
- Side By Side 2* (READ INFO!)
- Super GT 24h (output works but analog input is broken)
- Thrill Drive
- Turbo Outrun
- Vapor TRX
- Virtua Racing (CHANGE TO UPRIGHT CABINET)
- Winding Heat
- Xtreme Rally

SIDE BY SIDE INFO: OVERCLOCK DOESN'T SEEM TO WORK AFTER .288 ANYMORE!

* Side By Side and Side By Side 2 information: 
Activate Cheats in Mame and press ^ in game to show sliders. Go to CPU Overclock. Mine is set at 240% for now as everything above that can't be handled by my CPU (13600k at 5.4ghz). It makes it very playable here but your outcome might vary.

Find the highest number you can set for your computer and restart the game. Immediately pause, set the CPU Overclock, close the slider and press shift+f6 for a quicksave. This will automaticaly set the overclock settings as they won't be saved by mame.

Make sure the sidebs.ini and sidebs2.ini are in the same location as the mame exe - this will automatically load the savestate.

We can only hope the driver will be improved in the future.
