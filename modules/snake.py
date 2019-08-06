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

    def update(self):
        pass

    def draw(self, surface):
        for segment in self.body:
            segment.draw(surface)
