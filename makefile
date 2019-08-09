CC = g++ -std=c++11
TARGET = bin/snake
SRC = src/*.cpp
LIBS = -lSDL2main -lSDL2
INCLUDE = -Iinclude/

WIN_SDL_INCLUDE = -ISDL2/include
WIN_SDL_LIBS = -LSDL2/lib
WIN_LINK_MINGW = -lmingw32

win:
	$(CC) $(SRC) $(WIN_SDL_INCLUDE) $(INCLUDE) $(WIN_SDL_LIBS) $(WIN_LINK_MINGW) $(LIBS) -o $(TARGET)

clean:
	rm bin/snake
