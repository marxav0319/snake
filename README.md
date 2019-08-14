# snake

An implementation of the classic game "Snake" in C++ with SDL2.  This is a little personal project
of mine to keep my C++ skills relatively sharp and learn the SDL2 library.

## Progress

The first draft of this is done!  Although this is very much what would be called an `alpha` release,
there are a few bugs and a number of things that could be fixed/improved.  However, for the most
part, the game is now playable.

## Building

This has been tested only on Windows 10 so far, but I'll be testing on my Linux machine soon.  To
build, you'll need to get the SDL2 libraries for your operating system.  For windows, that means
you'll need to download the development libraries [here](https://www.libsdl.org/download-2.0.php),
and then properly link them.  

I have a makefile with a recipe I used, you may use the same.  I used `mingw g++` and the SDL2
**32 bit libraries**, so to run this please do the same.  I renamed the 32-bit SDL2 directory
SDL2, then followed the linking process noted in the makefile.  You should also create a `bin`
directory in the root of this repository, then store the dynamic library `SDL2.dll` in that bin
directory.  Running `make` will generate the output file `snake.exe`, which you may then run.

## Bugs

These are bugs I've found so far, I'm sure there are more but this is from my cursory look.

1. In certain cases, the snake's body separates, (usually into two pieces) that act independantly
  and do not respond to user input.

## Enhancements

These are great add-ons to have when the bugs are gone.

1. It would be great if you could choose the colors of the snake.  Some presets would be great too.
2. Use different shapes for the snake and the food - even better maybe use sprites.
3. Make the background more interesting than a black screen.
4. Add an intro screen and a restart screen.
