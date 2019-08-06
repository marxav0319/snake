import sys

import modules.game as game

def play_game():
    """
    """

    snake_game = game.Game(500, 20)
    snake_game.game_loop()


if __name__ == '__main__':
    play_game()
