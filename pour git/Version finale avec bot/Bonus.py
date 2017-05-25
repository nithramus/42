# -*- coding: utf-8 -*-

import random
import pygame
from pygame.locals import *

from Config import *

class Bonus(pygame.sprite.Sprite):
    """Classe permettant de gérer les bonus"""

    def __init__(self, bloc, carte):
        pygame.sprite.Sprite.__init__(self)

        self.carte = carte

        bonusID = random.randint(1, 3)

        if(bonusID == 1):
            self.image = pygame.image.load(IMG_Bonus_vitesseP).convert_alpha()
            self.nom = "vitesse+"
        elif(bonusID == 2):
            self.image = pygame.image.load(IMG_Bonus_nbBombeP).convert_alpha()
            self.nom = "nbBombe+"
        elif(bonusID == 3):
            self.image = pygame.image.load(IMG_Bonus_porteeBombeP).convert_alpha()
            self.nom = "porteeBombe+"

        self.rect = self.image.get_rect()
        self.rect.x = bloc.rect.x
        self.rect.y = bloc.rect.y

    def disparaitre(self):
        self.carte.liste_bonus.remove(self)