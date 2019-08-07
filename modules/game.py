import sys
import random
import pygame

from .snake import Snake
from .cube import Cube

DELAY = 50
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
        self.food = None

        pygame.init()
        self.game_window = pygame.display.set_mode((width, width))
        self.clock = pygame.time.Clock()
        self.game_loop()

    def add_food(self):
        """
        """

        not_valid_position = True
        x_position = random.randrange(self.rows)
        y_position = random.randrange(self.rows)
        while not_valid_position:
            result = any(segment == (x_position, y_position) for segment in self.snake.body)
            if not result:
                not_valid_position = False
            else:
                x_position = random.randrange(self.rows)
                y_position = random.randrange(self.rows)
        self.food = Cube(x_position, y_position, self.width, self.rows)

    def update(self):
        """
        """

        keys = pygame.key.get_pressed()
        if keys[pygame.K_ESCAPE]:
            pygame.quit()
            sys.exit(0)
        elif keys[pygame.K_LEFT]:
            self.snake.update(-1, 0)
        elif keys[pygame.K_RIGHT]:
            self.snake.update(1, 0)
        elif keys[pygame.K_UP]:
            self.snake.update(0, -1)
        elif keys[pygame.K_DOWN]:
            self.snake.update(0, 1)
        else:
            self.snake.update(self.snake.x_velocity, self.snake.y_velocity)

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
