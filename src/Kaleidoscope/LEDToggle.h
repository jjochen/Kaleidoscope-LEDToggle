/* -*- mode: c++ -*-
 * Kaleidoscope-LEDToggle -- On/Off Key for LED control.
 *
 * Copyright (c) 2018 Jochen Pfeiffer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
.* in the Software without restriction, including without limitation the rights
.* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
.* copies of the Software, and to permit persons to whom the Software is
.* furnished to do so, subject to the following conditions:
.*
.* The above copyright notice and this permission notice shall be included in all
.* copies or substantial portions of the Software.
.*
.* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
.* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
.* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
.* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
.* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
.* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
.* SOFTWARE.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-Ranges.h>


enum {
  LEDT_FIRST = kaleidoscope::ranges::LEDT_FIRST,
  LEDT_TOGGLE = LEDT_FIRST,
  LEDT_LAST = LEDT_TOGGLE
};

#define Key_LEDToggle (Key){ .raw = LED_TOGGLE }

namespace kaleidoscope {

class LEDToggle : public KaleidoscopePlugin {  
 public:
  LEDToggle(void);

  void begin(void) final;

 private:
  static Key eventHandlerHook(Key mapped_key, byte row, byte col, uint8_t key_state);
};

}

extern kaleidoscope::LEDToggle LEDToggle;
