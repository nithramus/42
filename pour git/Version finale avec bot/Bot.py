# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *
from Bombe import *
from Config import *
from Carte import*
from random import*
class Bot(pygame.sprite.Sprite):
    """Classe permettant de gérer un personnage"""

    def __init__(self, carte):
        pygame.sprite.Sprite.__init__(self)

        self.carte = carte

        self.carte.liste_bot.add(self)

        self.haut = pygame.image.load(IMG_persoH).convert_alpha()
        self.bas = pygame.image.load(IMG_persoB).convert_alpha()
        self.gauche = pygame.image.load(IMG_persoG).convert_alpha()
        self.droite = pygame.image.load(IMG_persoD).convert_alpha()
        self.direction = self.bas
        self.id_local = len(self.carte.liste_bot) + len(self.carte.liste_perso)

        self.aide_mouvement = 10
        self.vivant = True
        self.vitesse = 4
        self.vitesseMax = 10
        self.nb_bombe = 1
        self.nb_bombeMax = 15
        self.nb_bombePosee = 0
        self.bombe_portee = 3
        self.bombe_porteeMax = 15

        self.image = self.direction
        self.rect = self.image.get_rect()
        self.rect.x =  self.carte.bot_emplacementInitial(self)[0]
        self.rect.y = self.carte.bot_emplacementInitial(self)[1]
        self.objectifx = 24*32
        self.objectify = 15*32
        self.positionAvantX = self.rect.x
        self.positionAvantY = self.rect.y
        self.avanty = 2
        self.avantx = 2
        self.ancienX = 2
        self.ancienY = 2



    def mourir(self):
        self.carte.liste_bot.remove(self)
        self.vivant = False


    def objectif(self, tableau):
        self.i = int((self.rect.y)/32)-1
        self.j = int((self.rect.x)/32)-1
        if tableau[self.i][self.j] == 1:
            print(1)
            if tableau[self.i -1][self.j] == 1:
                if tableau[self.i ][self.j-1] == 1:
                    if tableau[self.i ][self.j+1]==1:
                        self.objectify -=32
                    else:
                        self.objectifx -=32
                else:
                    self.objectifx +=32
            else:
                self.objectify +=32
        else:
            while self.rect.x == self.objectifx and self.rect.y == self.objectify:
                r = randint(1,4)
                if r==1:
                    if tableau[self.i][self.j+1] != 1:
                        self.objectifx +=32
                if tableau[self.i][self.j-1] != 1:
                    if r == 2:
                        self.objectifx -=32
                if tableau[self.i-1][self.j] != 1:
                    if r == 3:
                        self.objectify -=32
                if tableau[self.i+1][self.j-1] != 1:
                    if r == 4:
                        self.objectify +=32







    def deplacer(self, carte, tableau):
        if self.rect.y == self.avanty and self.avantx == self.rect.x:
            self.objectifx =self.ancienX
            self.objectify = self.ancienY


        if self.objectify == self.rect.y and self.objectifx == self.rect.x :
            self.ancienX = self.objectifx
            self.ancienY = self.objectify
            self.objectif (tableau)
        if self.objectifx != self.rect.x or self.objectify != self.rect.y:
            if self.objectifx < self.rect.x:
                self.direction = 'GAUCHE'
            elif self.objectifx > self.rect.x:
                self.direction = 'DROITE'
            elif self.objectify < self.rect.y:
                self.direction = 'HAUT'
            elif self.objectify > self.rect.y:
                self.direction = 'BAS'
        self.avantx=self.rect.x
        self.avanty=self.rect.y
        aide = self.aide_mouvement
        # On teste le déplacement avec la vitesse du personnage, et on la réduit au contact d'un obstacle
        for vitesse_actuelle in range(self.vitesse, 0, -1):
            collision = self.testerCollision(vitesse_actuelle, 0)
            # On quitte la boucle si le personnage s'est déplacé
            if not(collision):
                break
            else:
                for aide_actuelle in range(1, aide+1):
                    collision = self.testerCollision(vitesse_actuelle, aide_actuelle)
                    if not(collision):
                        break
                    collision = self.testerCollision(vitesse_actuelle, -aide_actuelle)
                    if not(collision):
                        break




    def testerCollision(self, vitesse, aide):
        x = self.rect.x
        y = self.rect.y
        bombe_touche_avant = pygame.sprite.spritecollide(self, self.carte.liste_bombe, False)

        if self.direction == 'HAUT':
            self.rect.y -= vitesse
            self.rect.x += aide
            self.image = self.haut

        elif self.direction == 'BAS':
            self.rect.y += vitesse
            self.rect.x += aide
            self.image = self.bas

        elif self.direction == 'GAUCHE':
            self.rect.x -= vitesse
            self.rect.y += aide
            self.image = self.gauche

        elif self.direction == 'DROITE':
            self.rect.x += vitesse
            self.rect.y += aide
            self.image = self.droite

        if not((origine_gameX <= self.rect.x) and ((self.rect.x - (taille_sprite - self.rect[2])) <= ((self.carte.taille[0] * taille_sprite)))
           and (origine_gameY <= self.rect.y) and ((self.rect.y - (taille_sprite - self.rect[3])) <= ((self.carte.taille[1] * taille_sprite)))):
            self.rect.x = x
            self.rect.y = y

        mur_touche = pygame.sprite.spritecollide(self, self.carte.liste_mur, False)
        bloc_touche = pygame.sprite.spritecollide(self, self.carte.liste_bloc, False)
        if(mur_touche or bloc_touche):
            self.rect.x = x
            self.rect.y = y

        bombe_touche = pygame.sprite.spritecollide(self, self.carte.liste_bombe, False)
        for bombe in bombe_touche:
            if not(bombe in bombe_touche_avant):
                self.rect.x = x
                self.rect.y = y

        bonus_touche = pygame.sprite.spritecollide(self, self.carte.liste_bonus, False)
        for bonus in bonus_touche:
            if(bonus.nom == 'vitesse+'):
                if(self.vitesse < self.vitesseMax):
                    self.vitesse += 1
            elif(bonus.nom == 'nbBombe+'):
                if(self.nb_bombe < self.nb_bombeMax):
                    self.nb_bombe += 1
            elif(bonus.nom == 'porteeBombe+'):
                if(self.bombe_portee < self.bombe_porteeMax):
                    self.bombe_portee += 1

            bonus.disparaitre()

        return ((x, y) == (self.rect.x, self.rect.y))

    def poserBombe(self):
        # On vérifie que le personnage à encore une bombe en réserve
        if(self.nb_bombePosee < self.nb_bombe):
            bombe = Bombe(self, self.carte)
            if not(pygame.sprite.spritecollide(bombe, self.carte.liste_bombe, False)):
                # Division entière pour poser les bombe au centre de la case où se trouve le centre du perso
                self.carte.liste_bombe.add(bombe)



    def bot_objectifInitial(self):
        if(self.id_local == 1):
            return self.rect.x +32

        elif(self.id_local == 2):
            return self.rect.x - 32

        elif(self.id_local == 3):
            return self.rect.x - 32

        elif(self.id_local == 4):
            return self.rect.x + 32