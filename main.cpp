/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


 
#include "MAX14690.h"
#include "max32630fthr.h"

#include "mbed.h"
#include "platform/mbed_thread.h"



// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    500


// Initialise the digital pin LED1 as an output
DigitalOut led(LED2);


// Creating MAX32... class instance for managing pin logic levels.
MAX32630FTHR pegasus(MAX32630FTHR::VIO_1V8);

// Example pins
DigitalOut PIN3_0(P3_0); 
DigitalOut PIN3_1(P3_1);
DigitalOut PIN3_4(P3_4); 
DigitalOut PIN3_5(P3_5);

int main()
{

    
    pegasus.vddioh(P3_0, MAX32630FTHR::VIO_3V3);
    pegasus.vddioh(P3_1, MAX32630FTHR::VIO_3V3);

    // initialize power and I/O on MAX32630FTHR board
    //pegasus.init(MAX32630FTHR::VIO_1V8);

    PIN3_0 = 1;   // Now this should output 3.3V
    PIN3_1 = 1;   // Now this should output 3.3V
    PIN3_4 = 1;   // Now this should output 1.8v
    PIN3_5 = 1;   // Now this should output 1.8V

    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
