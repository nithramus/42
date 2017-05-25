# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *
from Carte import*
from Config import *
from Explosion import *

class Bombe(pygame.sprite.Sprite):
    """Classe permettant de gérer les bombes"""

    def __init__(self, perso, carte):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(IMG_bombe).convert_alpha()
        self.rect = self.image.get_rect()
        # Division entière pour poser les bombe au centre de la case où se trouve le centre du perso
        self.rect.x = ((perso.rect.x + (perso.rect[2] / 2)) // taille_sprite) * taille_sprite
        self.rect.y = ((perso.rect.y + (perso.rect[3] / 2)) // taille_sprite) * taille_sprite
        self.carte = carte
        self.perso = perso
        # On ajoute 1 bombe au nombre de bombe posée par le personnage
        self.perso.nb_bombePosee +=1
        # Durée de la bombe
        self.duree = 2

    def update(self):
        # On diminue la durée du minuteur
        self.duree -= (0.03333)

        # Si la durée est inférieur à 0, la bombe explose
        if(self.duree <= 0):
            self.explose()

    def explose(self):
        # On enlève 1 bombe au nombre de bombe posée par le personnage
        self.perso.nb_bombePosee -=1
        # On enlève la bombe de la liste des bombes
        self.carte.liste_bombe.remove(self)

        # Coordonnées de la bombe
        x = self.rect.x
        y = self.rect.y

        # On affiche l'explosion à la place de la bombe
        self.carte.liste_explosion.add(Explosion(self.carte, 'centre', x, y))

        explosion_interrompueH = False
        explosion_interrompueB = False
        explosion_interrompueG = False
        explosion_interrompueD = False

        # Pour toutes les cases entre la bombe et sa portee maximum dans les 4 directions
        for portee in range(1, (self.perso.bombe_portee + 1)):
            # Direction : Haut
            if not(explosion_interrompueH): # On vérifie si l'explosion de la bombe n'est pas intérompue
                # On vérifie si l'explosion est possible
                verifExplosion = self.verifierExplosion(self.carte.getCase((x, y-(portee*taille_sprite))))
                # Si elle n'est pas possible, l'explosion est intérompue dans cette direction
                if not(verifExplosion):
                    explosion_interrompueH = True
                else:
                    # Si c'est un bloc, l'explosion sera différente que dans le vide
                    if(verifExplosion == 'bloc'):
                        self.carte.liste_explosion.add(Explosion(self.carte, 'bloc', x, y-(portee*taille_sprite)))
                        # l'explosion est intérompue dans cette direction
                        explosion_interrompueH = True
                    # Sinon on affiche la bombe
                    else:
                        # On vérifie si l'explosion est bout de sa portée
                        if(portee == self.perso.bombe_portee):
                            self.carte.liste_explosion.add(Explosion(self.carte, 'verticaleH', x, y-(portee*taille_sprite)))
                        else:
                            self.carte.liste_explosion.add(Explosion(self.carte, 'verticale', x, y-(portee*taille_sprite)))

            # Direction : Bas
            if not(explosion_interrompueB):
                verifExplosion = self.verifierExplosion(self.carte.getCase((x, y+(portee*taille_sprite))))
                if not(verifExplosion):
                    explosion_interrompueB = True
                else:
                    if(verifExplosion == 'bloc'):
                        self.carte.liste_explosion.add(Explosion(self.carte, 'bloc', x, y+(portee*taille_sprite)))
                        explosion_interrompueB = True
                    else:
                        if(portee == self.perso.bombe_portee):
                            self.carte.liste_explosion.add(Explosion(self.carte, 'verticaleB', x, y+(portee*taille_sprite)))
                        else:
                            self.carte.liste_explosion.add(Explosion(self.carte, 'verticale', x, y+(portee*taille_sprite)))

            # Direction : Gauche
            if not(explosion_interrompueG):
                verifExplosion = self.verifierExplosion(self.carte.getCase((x-(portee*taille_sprite), y)))
                if not(verifExplosion):
                    explosion_interrompueG = True
                else:
                    if(verifExplosion == 'bloc'):
                        self.carte.liste_explosion.add(Explosion(self.carte, 'bloc', x-(portee*taille_sprite), y))
                        explosion_interrompueG = True
                    else:
                        if(portee == self.perso.bombe_portee):
                            self.carte.liste_explosion.add(Explosion(self.carte, 'horizontaleG', x-(portee*taille_sprite), y))
                        else:
                            self.carte.liste_explosion.add(Explosion(self.carte, 'horizontale', x-(portee*taille_sprite), y))

            # Direction : Droite
            if not(explosion_interrompueD):
                verifExplosion = self.verifierExplosion(self.carte.getCase((x+(portee*taille_sprite), y)))
                if not(verifExplosion):
                    explosion_interrompueD = True
                else:
                    if(verifExplosion == 'bloc'):
                        self.carte.liste_explosion.add(Explosion(self.carte, 'bloc', x+(portee*taille_sprite), y))
                        explosion_interrompueD = True
                    else:
                        if(portee == self.perso.bombe_portee):
                            self.carte.liste_explosion.add(Explosion(self.carte, 'horizontaleD', x+(portee*taille_sprite), y))
                        else:
                            self.carte.liste_explosion.add(Explosion(self.carte, 'horizontale', x+(portee*taille_sprite), y))

        # Les bonus touchés par l'explosion disparaissent
        bonus_touche = pygame.sprite.groupcollide(self.carte.liste_bonus, self.carte.liste_explosion, False, False)
        for bonus in bonus_touche:
            bonus.disparaitre()

        # Les blocs touchés par l'explosion sont détruient
        bloc_touche = pygame.sprite.groupcollide(self.carte.liste_bloc, self.carte.liste_explosion, False, False)
        for bloc in bloc_touche:
            bloc.detruire()

        # Les bombe touchées par l'explosion explosent
        bombe_touche = pygame.sprite.groupcollide(self.carte.liste_bombe, self.carte.liste_explosion, False, False)
        for bombe in bombe_touche:
            bombe.explose()

        # Les personnages touchés par l'explosion meurent
        perso_touche = pygame.sprite.groupcollide(self.carte.liste_perso, self.carte.liste_explosion, False, False)
        for perso in perso_touche:
            perso.mourir()

        # Les bots touchés par l'explosion meurtent
        bot_touche = pygame.sprite.groupcollide(self.carte.liste_bot, self.carte.liste_explosion, False, False)
        for bot in bot_touche:
            bot.mourir()


    def verifierExplosion(self, coordonnee):
        "Vérifie si l'explosion est possible"

        # On vérifie qu'elle est dans la carte
        if((coordonnee[0] <= 0) or (coordonnee[0] > self.carte.taille[0]) or (coordonnee[1] <= 0) or (coordonnee[1] > self.carte.taille[1])):
            return False
        # On vérifie qu'il n'y a pas de mur
        elif((self.carte.carte[coordonnee[1]-1][coordonnee[0]-1]) == SPRITE_mur):
            return False
        # On vérifie s'il y a un bloc
        elif((self.carte.carte[coordonnee[1]-1][coordonnee[0]-1]) == SPRITE_bloc):
            return 'bloc'   # On signal qu'il y a un bloc
        else: # Sinon l'explosion est possible normalement
            return True
