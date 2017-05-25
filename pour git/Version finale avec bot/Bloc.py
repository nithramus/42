# -*- coding: utf-8 -*-

import random
import pygame
from pygame.locals import *

from Config import *
from Bonus import *

class Bloc(pygame.sprite.Sprite):
    """Classe permettant de gérer les blocs"""

    def __init__(self, carte, image, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.image = image
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

        self.frequence_bonus = 8

        self.carte = carte


    def detruire(self):
        # On récupère la case du bloc
        case = self.carte.getCase((self.rect.x, self.rect.y))
        # On supprime le bloc de la carte (bloc remplacé en herbe)
        self.carte.carte[case[1] - 1][case[0] - 1] = '.'
        # On supprime le bloc de la liste des blocs
        self.carte.liste_bloc.remove(self)

        # On créer un nombre aléatoire
        r = random.randint(1,self.frequence_bonus)
        # Si le nombre aléatoire ets plus grand que 1, on créer un bonus
        if(r > 1):
            self.carte.liste_bonus.add(Bonus(self, self.carte))