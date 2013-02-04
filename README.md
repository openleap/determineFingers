###An <a href="openleap.org">OpenLeap</a> project started by @AlexOpalka.

determineFingers
================

This is a program written in C++ to determine which finger is which on the Leap.

In order to for the device to "capture" and get your fingers you need to hold all 10 fingers above the device.
Then you can use the values in later code and instead of using the default call you can compare a detected finger with all 
saved values. An example use of this is to track the right thumb and record and perform an action if it moves up and down in the y direction.

