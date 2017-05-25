# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *
from Bombe import *
from Config import *

class Perso(pygame.sprite.Sprite):
    """Classe permettant de gérer un personnage"""

    def __init__(self, carte):
        pygame.sprite.Sprite.__init__(self)

        self.carte = carte

        self.carte.liste_perso.add(self)

        self.haut = pygame.image.load(IMG_persoH).convert_alpha()
        self.bas = pygame.image.load(IMG_persoB).convert_alpha()
        self.gauche = pygame.image.load(IMG_persoG).convert_alpha()
        self.droite = pygame.image.load(IMG_persoD).convert_alpha()
        self.direction = self.bas
        self.id_local = len(self.carte.liste_perso)

        self.aide_mouvement = 10    # Nombre de pixel de l'aide au mouvement (désactiver: False)
        self.vivant = True
        self.vitesse = 4            # Vitesse initiale du personnage
        self.vitesseMax = 10        # Vitesse maximum du personnage
        self.nb_bombe = 1           # Nombre de bombe initial du personnage
        self.nb_bombeMax = 15       # Nombre de bombe maximum du personnage
        self.nb_bombePosee = 0      # Nombre de bombe posée du personnage
        self.bombe_portee = 1       # Portée initiale des bombes du personnage
        self.bombe_porteeMax = 15   # Portée maximum des bombes du personnage

        self.image = self.direction
        self.rect = self.image.get_rect()
        # Position initiale du personnage
        self.rect.x = self.carte.perso_emplacementInitial(self)[0]
        self.rect.y = self.carte.perso_emplacementInitial(self)[1]
        print(self.rect.x)
        print(self.rect.y)

    def mourir(self):
        # On enlève le personnage de la liste des personnages
        self.carte.liste_perso.remove(self)
        # Le personnage n'est plus vivant
        self.vivant = False

    def poserBombe(self):
        # On vérifie que le personnage à encore une bombe en réserve
        if(self.nb_bombePosee < self.nb_bombe):
            # On créer une bombe temporaire
            bombe = Bombe(self, self.carte)
            # On vérifie qu'une bombe n'est pas déjà présente sur la case
            if not(pygame.sprite.spritecollide(bombe, self.carte.liste_bombe, False)):
                self.carte.liste_bombe.add(bombe)

    def deplacer(self, direction):

        aide = self.aide_mouvement
        if(aide == False): aide = 1

        # On teste le déplacement avec la vitesse du personnage, et on la réduit au contact d'un obstacle
        for vitesse_actuelle in range(self.vitesse, 0, -1):
            collision = self.testerCollision(direction, vitesse_actuelle, 0)
            # On quitte la boucle si le personnage s'est déplacé
            if not(collision):
                break
            # Sinon on essaie avec l'aide au mouvement
            else:
                # Pour toutes les aides possibles dans l'ordre croissant ...
                for aide_actuelle in range(1, aide+1):
                    # On vérifie si c'est possible dans les deux sens perpendiculaire à l'obstacle
                    collision = self.testerCollision(direction, vitesse_actuelle, aide_actuelle)
                    # Si le personnage s'est déplacé, on quitte la boucle
                    if not(collision):
                        break
                    # Si le personnage s'est déplacé, on quitte la boucle
                    collision = self.testerCollision(direction, vitesse_actuelle, -aide_actuelle)
                    if not(collision):
                        break

    def testerCollision(self, direction, vitesse, aide):
        "Teste si le déplacement est possible"

        # On garde en mémoire la position du personnage avant le déplacement
        x = self.rect.x
        y = self.rect.y

        # On garde en mémoire les bombes touchées par le personnage avant le déplacement
        bombe_touche_avant = pygame.sprite.spritecollide(self, self.carte.liste_bombe, False)

        # On déplace le personnage vers sa direction selon sa vitesse et l'aide au mouvement
        if direction == 'HAUT':
            self.rect.y -= vitesse
            self.rect.x += aide
            self.image = self.haut

        elif direction == 'BAS':
            self.rect.y += vitesse
            self.rect.x += aide
            self.image = self.bas

        elif direction == 'GAUCHE':
            self.rect.x -= vitesse
            self.rect.y += aide
            self.image = self.gauche

        elif direction == 'DROITE':
            self.rect.x += vitesse
            self.rect.y += aide
            self.image = self.droite

        # Si le personnage n'est plus dans la carte, on le remet à sa position précédente
        if not((origine_gameX <= self.rect.x) and ((self.rect.x - (taille_sprite - self.rect[2])) <= ((self.carte.taille[0] * taille_sprite)))
           and (origine_gameY <= self.rect.y) and ((self.rect.y - (taille_sprite - self.rect[3])) <= ((self.carte.taille[1] * taille_sprite)))):
            self.rect.x = x
            self.rect.y = y

        # Si le personnage touche un mur ou un bloc, on le remet à sa position précédente
        mur_touche = pygame.sprite.spritecollide(self, self.carte.liste_mur, False)
        bloc_touche = pygame.sprite.spritecollide(self, self.carte.liste_bloc, False)
        if(mur_touche or bloc_touche):
            self.rect.x = x
            self.rect.y = y

        # Si le personnage touche une bombe, on le remet à sa position précédente
        bombe_touche = pygame.sprite.spritecollide(self, self.carte.liste_bombe, False)
        for bombe in bombe_touche:
            # Vérifie qu'il n'était pas déjà sur cette bombe
            if not(bombe in bombe_touche_avant):
                self.rect.x = x
                self.rect.y = y

        # Si le personnage touche un bonus, il gagne son effet selon le type de bonus
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

            # Après utilisation, le bonus disparait
            bonus.disparaitre()

        # On retourne si le personnage s'est déplacé
        return ((x, y) == (self.rect.x, self.rect.y))