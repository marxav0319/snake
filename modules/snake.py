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

    def update(self, x_velocity, y_velocity):
        """
        """

        for segment in self.body:
            segment.update(x_velocity, y_velocity)

    def draw(self, surface):
        """
        """

        for segment in self.body:
            segment.draw(surface)
