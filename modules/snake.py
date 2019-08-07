from .cube import Cube

class Snake(object):
    """
    """

    def __init__(self, width, rows):
        """
        """

        self.body = []
        self.head = Cube(0, 0, width, rows)
        self.body.append(self.head)
        self.x_velocity = 1
        self.y_velocity = 0

    def update(self, x_velocity, y_velocity):
        """
        """

        self.x_velocity = x_velocity
        self.y_velocity = y_velocity
        for segment in self.body:
            segment.update(x_velocity, y_velocity)

    def draw(self, surface):
        """
        """

        for segment in self.body:
            segment.draw(surface)
