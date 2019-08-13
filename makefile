CC = g++ -std=c++11
TARGET = bin/snake
SRC = src/*.cpp
LINKER_FLAGS = -lSDL2main -lSDL2
INCLUDE = -Iinclude/

WIN_SDL_INCLUDE = -ISDL2/include
WIN_SDL_LIBS = -LSDL2/lib
WIN_LINK_MINGW = -lmingw32
WIN_FLAGS = -w -Wl,-subsystem,windows

win:
	$(CC) $(SRC) $(WIN_SDL_INCLUDE) $(INCLUDE) $(WIN_SDL_LIBS) $(WIN_FLAGS) $(WIN_LINK_MINGW) $(LINKER_FLAGS) -o $(TARGET)

win_dev:
	$(CC) $(SRC) $(WIN_SDL_INCLUDE) $(INCLUDE) $(WIN_SDL_LIBS) $(WIN_LINK_MINGW) $(LINKER_FLAGS) -o $(TARGET)

nix:
	$(CC) $(SRC) $(INCLUDE) $(LINKER_FLAGS) -o $(TARGET)

clean:
	rm bin/snake
