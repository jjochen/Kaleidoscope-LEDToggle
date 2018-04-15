# Kaleidoscope-LEDToggle
LED On/Off Key for Kaleidoscope

![status][st:experimental]

 [st:stable]: https://img.shields.io/badge/stable-✔-black.svg?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.svg?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.svg?style=flat&colorA=dfb317&colorB=494e52


## Installation

Install this plugin as you would any other 3rd-party plugin.  Specifically:

1. __Find your plugin directory.__  This is wherever you normally put plugins; it
should be `$SKETCHBOOK_DIR/hardware/keyboardio/avr/libraries`, or at least
accessible from there via symlink. `$SKETCHBOOK_DIR` is your Arduino sketchbook directory, 
perhaps `$HOME/Arduino` or `$HOME/Documents/Arduino`.
2. __Install this plugin into your plugin directory__ using one of the below options.
* __(Option 1 - using Git)__ Clone this Git repo into your plugin directory.  This can
be done from the command line - just navigate to your plugin directory and type
`git clone https://github.com/jjochen/Kaleidoscope-LEDControlAdditions`.
* __(Option 2 - no Git or command-line required)__ Click the green "Clone or download"
button at the top right of this page, and select "Download ZIP".  Then, unzip the
folder in your plugin directory.

You're done!

## Adding the plugin to your sketch

To activate the plugin, you need to include the header, tell Kaleidoscope to `use`
the plugin, and place the `Key_LEDToggle` key in your keymap.

### Setup operations in the firmware sketch (example):

```c++
#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDToggle.h>

void setup (){
  Kaleidoscope.use(&LEDOff, &LEDToggle);
  Kaleidoscope.setup();
}
```

## Dependencies

* [Kaleidoscope-LEDControl](https://github.com/keyboardio/Kaleidoscope-LEDControl)

## Further reading

The [example][plugin:example] is a working sketch using Kaleidoscope-LEDToggle.

 [plugin:example]: https://github.com/jjochen/Kaleidoscope-LEDControlAdditions/blob/master/examples/LEDToggle/LEDToggle.ino
