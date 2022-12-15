# splittodogu

![splittodogu1](../Images/Layout_Default.png)
![splittodogu2](../Images/Layout_Game.png)
![splittodogu3](../Images/Layout_FN.png)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Timo Strube](https://github.com/tstrube)
* Hardware Supported: [Custom PCB](https://github.com/tstrube/SplittoDogu)

Make example for this keyboard (after setting up your build environment):

    make splittodogu:default

Flashing example for this keyboard:

    make splittodogu:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

## BongoCat
Screens show animated Bongo Cat on keypress

Original from pedker:
https://github.com/pedker/OLED-BongoCat-Revision
