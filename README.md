# AtariController #

The AtariController library enables your Arduino sketches to read Atari 2600 controllers.

## Installation ##

1. Download the latest source code zip from https://github.com/jonthysell/AtariController/releases/latest
2. Open the Arduino IDE
3. Open "Sketch > Include Library > Add .ZIP Library..."
4. Select the zip file you downloaded in step 1

## Getting Started ##

There are two example sketches included which make use of the AtariController library. See "File > Examples > AtariController" in the Arduino IDE after installation.

### AtariControllerSerialReader ###

This sketch reads the state of a single controller and reports it via the Serial interface. Note that it only reports when the state has changed (a button has been pressed or released). It's good for validating you've got your pins wired up properly.

### AtariControllerKeyboardReader ###

This sketch reads the state of a single controller and simulates key presses via the Keyboard interface. You can specify which buttons correspond to which keys in the sketch. This sketch requires a 32u4 based board (such as the Leonardo, Micro, or Due).

## More Info ##

TODO

Copyright (c) 2017 Jon Thysell
