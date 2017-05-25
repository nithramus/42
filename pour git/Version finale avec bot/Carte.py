# -*- coding: utf-8 -*-

import pygame
import copy
from pygame.locals import *
from Config import *
from Mur import *
from Bloc import *

class Carte:
    """Classe permettant de gérer la carte"""

    def __init__(self, nomCarte):
        self.fichier = DIR_cartes+'/'+nomCarte+'.txt'
        self.carte = 0

        self.taille = ()
        self.liste_mur = pygame.sprite.Group()
        self.liste_bloc = pygame.sprite.Group()
        self.liste_perso = pygame.sprite.Group()
        self.liste_bombe = pygame.sprite.Group()
        self.liste_explosion = pygame.sprite.Group()
        self.liste_bonus = pygame.sprite.Group()
        self.liste_bot = pygame.sprite.Group()

    def charger(self):
        imgMurLoaded = pygame.image.load(IMG_mur).convert()
        imgBlocLoaded = pygame.image.load(IMG_bloc).convert()
        with open(self.fichier, "r") as fichier:
            carteChargee = []
            num_ligne = 0
            for ligne in fichier:
                num_case = 0
                ligneCaractere = []
                for caractere in ligne:
                    # On change de ligne à chaque retour a la ligne
                    if caractere != '\n':
                        x = num_case * taille_sprite + origine_gameX
                        y = num_ligne * taille_sprite + origine_gameY

                        if caractere == SPRITE_mur:
                            self.liste_mur.add(Mur(imgMurLoaded, x, y))
                        elif caractere == SPRITE_bloc:
                            self.liste_bloc.add(Bloc(self, imgBlocLoaded, x, y))

                        ligneCaractere.append(caractere)
                        num_case += 1
                carteChargee.append(ligneCaractere)
                num_ligne += 1
        self.carte = carteChargee
        self.taille = (num_case, num_ligne)


    def afficher(self, fenetre):
        # On remplit l'herbe
        imgSolLoaded = pygame.image.load(IMG_sol).convert()
        num_ligne = 0
        for ligne in self.carte:
            num_case = 0
            for sprite in ligne:
                x = num_case * taille_sprite + origine_gameX
                y = num_ligne * taille_sprite + origine_gameY
##                if sprite == SPRITE_sol:     # Sol
##                    fenetre.blit(imgSolLoaded, (x,y))
                fenetre.blit(imgSolLoaded, (x,y))
                num_case += 1
            num_ligne += 1

        # On affiche chaques sprites
        self.liste_mur.draw(fenetre)
        self.liste_bonus.draw(fenetre)
        self.liste_bloc.draw(fenetre)
        self.liste_bombe.draw(fenetre)
        self.liste_explosion.draw(fenetre)
        self.liste_perso.draw(fenetre)
        self.liste_bot.draw(fenetre)

    def getCase(self, coordonnees):
        return ((coordonnees[0]//taille_sprite), (coordonnees[1]//taille_sprite))

    def perso_emplacementInitial(self, perso):
        if(perso.id_local == 1):
            return (origine_gameX + ((taille_sprite - perso.rect[2]) / 2), origine_gameY + ((taille_sprite - perso.rect[3]) / 2))
        elif(perso.id_local == 2):
            return (self.taille[0]*taille_sprite + ((taille_sprite - perso.rect[2]) / 2), self.taille[1]*taille_sprite + ((taille_sprite - perso.rect[3]) / 2))
        elif(perso.id_local == 3):
            return (self.taille[0]*taille_sprite + ((taille_sprite - perso.rect[2]) / 2), origine_gameY + ((taille_sprite - perso.rect[3]) / 2))
        elif(perso.id_local == 4):
            return (origine_gameX + ((taille_sprite - perso.rect[2]) / 2), self.taille[1]*taille_sprite + ((taille_sprite - perso.rect[3]) / 2))

    def bot_emplacementInitial(self, bot):
        if(bot.id_local == 2):
            return (self.taille[0]*taille_sprite, self.taille[1]*taille_sprite)
        elif(bot.id_local == 3):
            return (self.taille[0]*taille_sprite, origine_gameY )
        elif(bot.id_local == 4):
            return (origine_gameX , self.taille[1]*taille_sprite)




    def tableau(self):
        with open(self.fichier, "r") as fichier:
            self.Y=0
            for ligne in fichier:
                self.Y+=1
                self.X=0
                for caractere in ligne:
                    self.X+=1
        with open(self.fichier, "r") as fichier:
            num_ligne = 0
            self.tableau=[0]*self.Y
            for i in range (0, self.Y):
                self.tableau[i]= [0]*self.X

            for ligne in fichier:
                num_case = 0
                for caractere in ligne:
                    if caractere != '\n':
                        if caractere == SPRITE_mur:
                            self.tableau[num_ligne][num_case] = 1
                        elif caractere == SPRITE_bloc:
                            self.tableau[num_ligne][num_case] = 1
                    num_case += 1
                num_ligne += 1


    def TableauAJour(self):
        self.tableauAct = copy.deepcopy(self.tableau)
        for bombe in self.liste_bombe:
            self.i = int((bombe.rect.y)/32)-1
            self.j = int((bombe.rect.x)/32)-1
            self.I1 = self.i-(bombe.perso.bombe_portee)
            while self.I1<0:
                self.I1 +=1
            self.I2 =  self.i+(bombe.perso.bombe_portee)
            while self.I2 >= self.Y:
                self.I2 -=1

            for i in range (self.I1, self.I2 ):
                self.tableauAct[i][self.j-1]=1

            self.J1 = self.j-(bombe.perso.bombe_portee)
            while self.J1<0:
                self.J1 +=1
            self.J2 =  self.j+(bombe.perso.bombe_portee) -1
            while self.J2 >= self.X:
                self.J2 -=1

            for j in range (self.J1, self.J2):
                self.tableauAct[self.i-1][j]=1
        for i in range (0,self.Y):
            print (self.tableauAct[i])

        print ("")
        return self.tableauAct



