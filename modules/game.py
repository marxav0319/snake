import sys
import pygame

from .snake import Snake

DELAY = 10
TICK = 10

class Game(object):
    """
    """

    def __init__(self, width, rows):
        """
        """

        self.width = width
        self.rows = rows
        self.snake = Snake(width, rows)

        pygame.init()
        self.game_window = pygame.display.set_mode((width, width))
        self.clock = pygame.time.Clock()
        self.game_loop()

    def update(self):
        """
        """

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.snake.update(-1, 0)
        elif keys[pygame.K_RIGHT]:
            self.snake.update(1, 0)
        elif keys[pygame.K_UP]:
            self.snake.update(0, -1)
        elif keys[pygame.K_DOWN]:
            self.snake.update(0, 1)
        elif keys[pygame.K_ESCAPE]:
            pygame.quit()
            sys.exit(0)

    def draw(self):
        """
        """

        self.game_window.fill((0, 0, 0))
        self.snake.draw(self.game_window)
        pygame.display.update()

    def game_loop(self):
        """
        """

        game_is_active = True

        while game_is_active:
            pygame.time.delay(DELAY)
            self.clock.tick(TICK)

            for event in pygame.event.get():
                # Check if the user wants to quit
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit(0)

                self.update()

            self.draw()
