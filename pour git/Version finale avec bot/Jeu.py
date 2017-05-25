# -*- coding: utf-8 -*-

import time

import pygame
from pygame.locals import *

from Config import *
from Config_joueur import *
from Carte import *
from Perso import *
from Bot import*
from Bombe import*
from random import*
class Jeu:
    """Classe permettant de gérer le jeu"""

    def __init__(self, fenetre, nb_perso, nb_bots, nomCarte):
        self.fenetre = fenetre
        self.duree = 3 * 60

        # On affiche la carte
        self.carte = Carte(nomCarte)
        self.carte.charger()
        self.carte.tableau()
        self.tableau = self.carte.tableau
        self.carte.afficher(self.fenetre)



        # On créer les personnage

        # On créer les personnages

        for perso in range(nb_perso):
            Perso(self.carte)
        # On créer les bots
        for bot in range(nb_bots):
            Bot(self.carte)

        self.partieEnCours = True

        # Boucle du jeu
        while self.partieEnCours:
            self.carte.TableauAJour()
            #Limite des FPS
            pygame.time.Clock().tick(fenetre_FPS)

            # On verifie si la partie est finie
            if(self.verif_finPartie()):
                # On arrete la partie
                self.partieEnCours = False

                # On affiche un fond transparant sur la carte
                fond_transparant = pygame.Surface((self.carte.taille[0] * taille_sprite, self.carte.taille[1] * taille_sprite), pygame.SRCALPHA)
                fond_transparant.fill((255,255,255,64))
                self.fenetre.blit(fond_transparant, (origine_gameX, origine_gameY))
                pygame.display.flip()

                # On attend 3 secondes
                pygame.time.delay(3000)
                break

            # On remplie l'écran en noir
            self.fenetre.fill((0, 0, 0))

            for event in pygame.event.get():

                if event.type == QUIT:
                    self.partieEnCours = False
                elif event.type == KEYDOWN:
                    # On vérifie pour tout les personnages vivant si la touche bombe est pressée
                    for perso in self.carte.liste_perso:
                        if(perso.vivant):
                            if event.key == KEY_perso[perso.id_local]['bombe']:
                                # Le personnage pose une bombe
                                perso.poserBombe()

            # On vérifie pour tout les personnages vivant


            for perso in self.carte.liste_perso:
                if(perso.vivant):
                    # Si une touche de déplacement est préssée, alors le personnage se déplace
                    touchePressee = pygame.key.get_pressed()
                    if(touchePressee[KEY_perso[perso.id_local]['haut']]):
                        perso.deplacer('HAUT')
                    elif(touchePressee[KEY_perso[perso.id_local]['bas']]):
                        perso.deplacer('BAS')
                    elif(touchePressee[KEY_perso[perso.id_local]['gauche']]):
                        perso.deplacer('GAUCHE')
                    elif(touchePressee[KEY_perso[perso.id_local]['droite']]):
                        perso.deplacer('DROITE')

            for bot in self.carte.liste_bot:
                if (bot.vivant):
                    bot.deplacer(self.carte, self.tableau)
                    r = randint(1,15)
                    if r >= 12 :
                        bot.poserBombe()

            # On met a jour les chronomètres
            self.carte.liste_bombe.update()
            self.carte.liste_explosion.update()
            self.duree -= (-0.0333)

            # On met à jour la carte
            self.carte.afficher(self.fenetre)

            # On affiche le chronomètre de la partie
            self.afficherTemps()

            #Rafraichissement
            pygame.display.flip()

    def verif_finPartie(self):
        "Vérifie si une partie est finie"
        # S'il ne reste qu'un adversaire, il a gagné
        if(len(self.carte.liste_perso)) + (len(self.carte.liste_bot)) == 1:
            self.finPartie_victoire()
            return True
        # Si tout le monde est mort, ça fait égalité
        elif(len(self.carte.liste_perso))+ (len(self.carte.liste_bot)) == 0:
            self.finPartie_egualite()
            return True

        # Si le chronomètre de la partie est terminé, ça fait égalité
        if(self.duree <= 0):
            self.finPartie_egualite()
            return True

    def finPartie_victoire(self):
        "Affiche le texte de victoire au milieu de l'écran"
        font = pygame.font.Font(None, 96)

        if(len(self.carte.liste_perso) != 0):
            for perso in self.carte.liste_perso:
                vainqueur = "Joueur {0}".format(perso.id_local)
        else:
            vainqueur = "Bot"

        texte = "Victoire du {0}".format(vainqueur)
        text = font.render(texte, 1, (250, 250, 250))
        self.fenetre.blit(text, ((taille_fenetre[0]/2)-(font.size(texte)[0]/2), ((taille_fenetre[1]/2)-(font.size(texte)[1]/2))))

    def finPartie_egualite(self):
        "Affiche le texte d'égalité au milieu de l'écran"
        font = pygame.font.Font(None, 96)
        texte = "Égalité"
        text = font.render(texte, 1, (250, 250, 250))
        self.fenetre.blit(text, ((taille_fenetre[0]/2)-(font.size(texte)[0]/2), ((taille_fenetre[1]/2)-(font.size(texte)[1]/2))))

    def afficherTemps(self):
        "Affiche le chronomètre de la partie"
        font = pygame.font.Font(None, 32)
        texte = "{:02.0f}:{:02.0f}".format(self.duree//60, self.duree%60)
        text = font.render(texte, 1, (250, 250, 250))
        self.fenetre.blit(text, ((taille_fenetre[0]/2)-(font.size(texte)[0]/2), ((origine_gameY/2)-(font.size(texte)[1]/2))))
