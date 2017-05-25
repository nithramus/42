# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *

from Config import *

class Explosion(pygame.sprite.Sprite):
    """Classe permettant de gérer les explosions"""

    def __init__(self, carte, direction, x, y):
        pygame.sprite.Sprite.__init__(self)

        self.carte = carte
        self.direction = direction

        # On attribue l'image selon son orientation/type
        if(direction == 'centre'):          image_nom = IMG_explosionC
        elif(direction == 'horizontale'):   image_nom = IMG_explosionH
        elif(direction == 'verticale'):     image_nom = IMG_explosionV
        elif(direction == 'horizontaleG'):  image_nom = IMG_explosionHG
        elif(direction == 'horizontaleD'):  image_nom = IMG_explosionHD
        elif(direction == 'verticaleH'):    image_nom = IMG_explosionVH
        elif(direction == 'verticaleB'):    image_nom = IMG_explosionVB
        elif(direction == 'bloc'):          image_nom = IMG_bloc_destruction

        self.image = pygame.image.load(image_nom).convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

        # Durée d'explosion
        self.duree = 0.3

    def update(self):
        # On diminue la durée du minuteur
        self.duree -= (0.3333)

        # Si la durée est inférieur à 0, on supprime l'explosion
        if(self.duree <= 0):
            self.detruire()

    def detruire(self):
        # On supprime l'a supprime de la liste
        self.carte.liste_explosion.remove(self)
