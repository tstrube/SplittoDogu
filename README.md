# SplittoDogu
QMK firmware for split keyboard with screens and encoders

This is a split keyboard with encoders for arrow keys, mouse wheels, page up/down, and undo/redo.
One of the two screens shows the active layer and status of Num and Caps.
The other screen is for Bongo Cat...

![Splitto Dogu with Caps](../Images/WithCaps.jpg)
![Splitto Dogu without Caps](../Images/NoCaps.jpg)

## Layouts
There are two nearly identical default layouts. One for Windows and the other for MAC.
The difference are key combinations for undo/redo and other hotkeys.

![Splitto Dogu Layout Default](../Images/Layout_Default.png)

Then there is a layer for gaming, which shifts most buttons to the right by one place.
This is done to get WASD to the optimal position.

![Splitto Dogu Layout Game](../Images/Layout_Game.png)

The last layer FN is for F1 to F12, arrow keys, and the keypad.

![Splitto Dogu Layout FN](../Images/Layout_FN.png)

## PCB
The PCB can be used for both sides. SImply bridge the jumper points under the OLED screen.
JP_L1 to JP_L6 for the left side, JP_Rx for the right.
The Elite-C must be flipped. (See images)

![Splitto Dogu PCB](../Images/PCB.jpg)
![Splitto Dogu Schematic](../Images/Schematic.jpg)
