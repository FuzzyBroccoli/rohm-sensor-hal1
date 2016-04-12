/*   Copyright 2016 Rohm Semiconductor

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef ROHM_HAL_H
#define ROHM_HAL_H

/* This file is meant for making same code work on many platforms easier. */
#ifdef __MBED__
    /* Mbed Classic */
    #include "mbed.h"               //types
    #include "I2C.h"                //I2C

    #define USE_MBED_HARDWARE_I2C
    extern Serial pc;
    //Serial pc(USBTX, USBRX); done in main.cpp
    #define DEBUG_print(...)    pc.printf(__VA_ARGS__)
    #define DEBUG_printf(...)   pc.printf(__VA_ARGS__)
    #define DEBUG_println(...)  pc.printf(__VA_ARGS__);pc.printf("\r\n")
#elif defined(YOTTA_MODULE_NAME)
    /* Mbed OS */
    #include "mbed-drivers/mbed.h"  //types, Serial, I2C -type, ...
    #include "mbed-drivers/I2C.h"   //I2C

    #define USE_MBED_HARDWARE_I2C
    //get_stdio_serial().baud(115200); done in main.cpp

    #define DEBUG_print(...)    printf(__VA_ARGS__)
    #define DEBUG_printf(...)   printf(__VA_ARGS__)
    #define DEBUG_println(...)  printf(__VA_ARGS__);printf("\r\n")

#elif __ARDUINO__
    /* Arduino */
    #include <arduino.h>            //types, Serial

    //#define USE_ARDUINO_SOFTWARE_I2C
    #define USE_ARDUINO_HARDWARE_I2C

    #define DEBUG_printf(a)         Serial.print(a)
    #define DEBUG_printf(a, b)      Serial.print(a);Serial.print(b)
    #define DEBUG_printf(a, b, c)       Serial.print(a);Serial.print(b);Serial.print(c)
    #define DEBUG_printf(a, b, c, ...)  Serial.print(a);Serial.print(b);Serial.print(c)
    #define DEBUG_print()           Serial.print()
    #define DEBUG_println()         Serial.println()
#else
    #error "rohm_hal.h: Not valid target."
#endif

#if 0       //Enable/disable debug prints
    #define DEBUG_print()
    #define DEBUG_printf()
    #define DEBUG_println()
#endif

#endif /* ROHM_HAL_H */
