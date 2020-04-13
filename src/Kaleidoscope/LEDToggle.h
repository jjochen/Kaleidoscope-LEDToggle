/* -*- mode: c++ -*-
* Kaleidoscope-LEDToggle -- On/Off Key for LED control.
*
* Copyright (c) 2018 Jochen Pfeiffer
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Ranges.h>

#define Key_LEDToggleOnOff (Key){ .raw = kaleidoscope::LEDT_ON_OFF } 
#define Key_LEDToggleNext (Key){ .raw = kaleidoscope::LEDT_NEXT }

namespace kaleidoscope {

enum {
  LEDT_FIRST = kaleidoscope::ranges::LEDT_FIRST,
  LEDT_ON_OFF = LEDT_FIRST,
  LEDT_NEXT,
  LEDT_LAST = LEDT_NEXT
};

namespace plugin {

class LEDToggle : public kaleidoscope::Plugin {
 public:
  LEDToggle(void) {};
  EventHandlerResult onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState);
  static void toggle();
  static void next();
};

} // plugin
} // kaleidoscope

extern kaleidoscope::plugin::LEDToggle LEDToggle;
