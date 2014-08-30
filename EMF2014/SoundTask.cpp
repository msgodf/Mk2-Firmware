/*
 TiLDA Mk2
 
 SoundTask
 
 The MIT License (MIT)
 
 Copyright (c) 2014 Electromagnetic Field LTD
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include "SoundTask.h"

#include <FreeRTOS_ARM.h>
#include <debug.h>

SoundTask::SoundTask() {
}

void SoundTask::playTone(int tone, int duration) {
      
    pinMode(PIEZO, OUTPUT);
    
    for(int i = 0 ; i < duration; ++i) {
        digitalWrite(PIEZO, HIGH);
        delayMicroseconds(tone/2);
        digitalWrite(PIEZO, LOW);
        delayMicroseconds(tone/2);
    }
}

String SoundTask::getName() const {
    return "SoundTask";
}

void SoundTask::task() {
    while(true) {
        vTaskDelay((1000/portTICK_PERIOD_MS));
    }
}
