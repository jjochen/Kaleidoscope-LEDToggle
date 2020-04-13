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

#include <Kaleidoscope-LEDToggle.h>
#include <Kaleidoscope-LEDControl.h>

namespace kaleidoscope {
namespace plugin {
namespace {

static int lastLedModeIndex = -1;
static bool wasShiftKeyActive(void);
static void nextLedModeSkippingOff();
static void previousLedModeSkippingOff();

} // namespace
} // namespace plugin
} // namespace kaleidoscope


namespace kaleidoscope {
namespace plugin {

EventHandlerResult LEDToggle::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t keyState) {
  if (mapped_key.getRaw() < LEDT_FIRST || mapped_key.getRaw() > LEDT_LAST) {
    return EventHandlerResult::OK;
  }

  if (!keyToggledOn(keyState)) {
    return EventHandlerResult::EVENT_CONSUMED;
  }

  switch (mapped_key.getRaw()) {
  case LEDT_ON_OFF:
    toggle();
    break;
  case LEDT_NEXT:
    next();
    break;
  }

  return EventHandlerResult::EVENT_CONSUMED;
}

void LEDToggle::toggle() {
  if (wasShiftKeyActive()) {
    nextLedModeSkippingOff();
  } else if (LEDControl::get_mode() != &::LEDOff) {
    lastLedModeIndex = LEDControl::get_mode_index();
    ::LEDOff.activate();
  } else if (lastLedModeIndex >= 0) {
    LEDControl::set_mode(lastLedModeIndex);
  } else {
    nextLedModeSkippingOff();
  }
}

void LEDToggle::next() {
  if (wasShiftKeyActive()) {
    previousLedModeSkippingOff();
  } else {
    nextLedModeSkippingOff();
  }
}


namespace {

void nextLedModeSkippingOff() {
  do {
    LEDControl::next_mode();
  } while (LEDControl::get_mode() == &::LEDOff);
  lastLedModeIndex = LEDControl::get_mode_index();
}

void previousLedModeSkippingOff() {
  do {
    LEDControl::prev_mode();
  } while (LEDControl::get_mode() == &::LEDOff);
  lastLedModeIndex = LEDControl::get_mode_index();
}

bool wasShiftKeyActive(void) {
  // todo: support one shot
  return Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift) ||
         Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_RightShift);
}

} // namespace
} // namespace plugin
} // namespace kaleidoscope

kaleidoscope::plugin::LEDToggle LEDToggle;
