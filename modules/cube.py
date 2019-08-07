import pygame

class Cube(object):
    """
    """

    def __init__(self, x_position, y_position, width, rows):
        """
        """

        self.x_position = x_position
        self.y_position = y_position
        self.color = (0, 255, 0)
        self.fill_area = width // rows

    def update(self, x_velocity, y_velocity):
        """
        """

        self.x_position += x_velocity
        self.y_position += y_velocity

    def draw(self, surface):
        """
        """

        current_x = (self.x_position * self.fill_area) + 1
        current_y = (self.y_position * self.fill_area) + 1
        rect_details = [current_x, current_y, self.fill_area, self.fill_area]
        pygame.draw.rect(surface, self.color, rect_details)
