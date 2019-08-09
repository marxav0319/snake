# snake

An implementation of the classic game "Snake" in C++ with SDL2.

## Progress

This is a work in progress and is not yet playable.

## Building

Again, this hasn't been finished yet, and therefore it is not thoroughly tested.  However, to build,
you'll need to get the 32-bit SDL2 libraries, store the `.dll` in the bin directory, and then
compile with the appropriate linker flags.  The makefile I use to build on Windows 10 is included
in this repository.  You may try to emulate the structure of my repository by grabbing the SDL2
32-bit directory and renaming it SDL2, ensuring the `include` and `lib` directories are included,
then storing that SDL2 directory in the root of this repository.  After that, simply running
`make win` should work.  I'll be testing on my linux machine as well at a later point in time.
