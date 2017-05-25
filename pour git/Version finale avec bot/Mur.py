# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *
from Config import *

class Mur(pygame.sprite.Sprite):
    """Classe permettant de gérer les murs"""

    def __init__(self, image, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y