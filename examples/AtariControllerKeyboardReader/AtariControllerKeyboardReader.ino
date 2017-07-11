//
// AtariControllerKeyboardReader.ino
//
// Author:
//       Jon Thysell <thysell@gmail.com>
//
// Copyright (c) 2017 Jon Thysell <http://jonthysell.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <Keyboard.h>
#include <AtariController.h>

typedef struct
{
    byte button;
    char key;
} output;

// Controller button to keyboard mapping
output outputMap[] = {
    { AC_BTN_UP,    KEY_UP_ARROW },
    { AC_BTN_DOWN,  KEY_DOWN_ARROW },
    { AC_BTN_LEFT,  KEY_LEFT_ARROW },
    { AC_BTN_RIGHT, KEY_RIGHT_ARROW },
    { AC_BTN_FIRE,  ' ' },
};

const byte BUTTONS = 5;

// Specify the Arduino pins that are connected to
// DB9 Pin 1, DB9 Pin 2, DB9 Pin 3, DB9 Pin 4, DB9 Pin 6
AtariController controller(2, 3, 4, 5, 6);

// Controller states
byte currentState = 0;
byte lastState = 0;

void setup()
{
    Keyboard.begin();
}

void loop()
{
    currentState = controller.getState();
    sendStates();
}

void sendStates()
{
    for (byte i = 0; i < BUTTONS; i++)
    {
        byte last = (lastState & outputMap[i].button);
        byte current = (currentState & outputMap[i].button);

        if (last != current)
        {
            if (current)
            {
                Keyboard.press(outputMap[i].key);
            }
            else
            {
                Keyboard.release(outputMap[i].key);
            }
        }
    }

    lastState = currentState;
}