import sys
import pygame

from .snake import Snake

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
            pass
        elif keys[pygame.K_RIGHT]:
            pass
        elif keys[pygame.K_UP]:
            pass
        elif keys[pygame.K_DOWN]:
            pass

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
            pygame.time.delay(50)
            self.clock.tick(10)

            for event in pygame.event.get():
                # Check if the user wants to quit
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit(0)

                self.update()

            self.draw()
