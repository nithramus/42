# -*- coding: utf-8 -*-

######################################################################
# Fichier contenant plusieurs variables de configuration des touches #
######################################################################


from pygame.locals import *


KEY_perso = {}

# Perso 1
KEY_perso[1] = {}
KEY_perso[1]['haut'] = K_UP
KEY_perso[1]['bas'] = K_DOWN
KEY_perso[1]['gauche'] = K_LEFT
KEY_perso[1]['droite'] = K_RIGHT
KEY_perso[1]['bombe'] = K_KP0

# Perso 2
KEY_perso[2] = {}
KEY_perso[2]['haut'] = K_w
KEY_perso[2]['bas'] = K_s
KEY_perso[2]['gauche'] = K_a
KEY_perso[2]['droite'] = K_d
KEY_perso[2]['bombe'] = K_SPACE


#Perso 3
KEY_perso[3] = {}
KEY_perso[3]['haut'] = K_t
KEY_perso[3]['bas'] = K_g
KEY_perso[3]['gauche'] = K_f
KEY_perso[3]['droite'] = K_h
KEY_perso[3]['bombe'] = K_b


# Perso 4
KEY_perso[4] = {}
KEY_perso[4]['haut'] = K_o
KEY_perso[4]['bas'] = K_l
KEY_perso[4]['gauche'] = K_k
KEY_perso[4]['droite'] = K_SEMICOLON
KEY_perso[4]['bombe'] = K_COMMA