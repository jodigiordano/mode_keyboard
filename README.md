# MODE keyboard

An hand-wired RGB mechanical keyboard.

[Imgur album](http://imgur.com/gallery/g5kuz)

## Hardware

* The case design can be found in the folder `case`. It is composed of layers of 3mm acrylic sheets. This is typically how homemade keyboard cases are made and I tried to [follow the recipe](https://www.reddit.com/r/MechanicalKeyboards/comments/4l0p41/guide_detailed_guide_to_making_a_custom_keyboard/) as closely as possible, using [tools from the community](http://builder.swillkb.com).
* The LibreOffice Draw file  `case.odg` is a conceptual view of the case and is easier to read.
* The electronic circuitry can be found in `mk.fzz`, which is a [Fritzing](http://fritzing.org) file.

### Parts

* Switches & LEDs: Purple Zealio + mountable RGB LEDs from ZealPC
* Case: custom made with 3mm acrylic sheets, M2 screws and M2 spacers
* Micro-controller: Teensy 3.2
* LED drivers: TLC5940
* Connectors LED drivers <-> LEDs: 30AWG wires and machine screws pin headers
* Connectors Teensy 3.2 <-> LED drivers <-> LED drivers: 24AWG wires
* Others: cheapest double-sided perfboards (the green boards) from eBay, 100pF capacitors (as stated in the TLC5940 datasheets) and a 2SD734 transistor.

## The firmware

* The code is developped for the [Teensy 3.2](https://www.pjrc.com/store/teensy32.html) using the [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) software addon for Arduino. It can be found in the folder `code`.
* In the folder `code`, type `./make.sh` to compile and send the firmware to the Teensy.

## What's next?

In an ideal V2, I want:

* [hardware] PCB with surface-mounted components.
* [hardware] Wireless over Bluetooth.
* [hardware] Additional USB port to plug my mouse.
* [hardware] Add underglow, maybe a backlit logo.
* [hardware] Another kind of switches, maybe Matias Quiet Click switches.
* [firmware] Programmable layout over wireless.
* [firmware] Animation system for lightning effects.
* [firmware] I want my window manager in Linux (i3) to send context information to the keyboard so I can load contextual layouts.
