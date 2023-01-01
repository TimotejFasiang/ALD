Created by Timotej Fašiang 1/1/2023

This is a world generating program using the C++ SFML library for graphical purposes.

The program creates a virtual 2D game board and then cycles from left to right, top to bottom through it.
During the cycle, it creates "pipe like" objects and puts them on the virtual board.
The "pipe" object connection directions are randomly selected, taking into account previous objects, and connecting them together when necessary.

Because of the left to right, top to bottom cycle, the current "pipe" object only has to check the object above and to the left of it to see whether a connection is necessary.
The random selection is done using the rand() command from stdlib.h and the __rdtsc() command from intrin.h which returns the processor tick count.

The program creates the "renderImage.png" file in the current directory, which depicts all the "pipe" objects on the virtual board.
