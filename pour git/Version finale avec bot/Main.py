# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *

from Config import *
from Menu import *

pygame.init()

# Ouverture de la fenêtre Pygame
fenetre = pygame.display.set_mode(taille_fenetre)
pygame.display.set_caption(titre_fenetre)
pygame.display.set_icon(pygame.image.load(IMG_Bonus_nbBombeP).convert_alpha())

# On limite la répétiton des évenements de touche de clavier
pygame.key.set_repeat(400, 30)

# On lance le menu
Menu(fenetre)

# Lorsque le menu se ferme, le jeu se ferme
pygame.quit()