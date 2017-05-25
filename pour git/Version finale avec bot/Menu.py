# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *

from Config import *
from Jeu import *

class Menu:
    """Classe permettant de gérer les menus"""

    def __init__(self, fenetre):
        self.fenetre = fenetre

        # Lancement de la musique du jeu
        pygame.mixer.music.load(SON_Menu)
        pygame.mixer.music.play(-1)

        # Couleur de fond des menu
        self.fond_couleur = (253, 171, 43)

        # Lancement du menu principal
        self.menu_principal()

    def menu_principal(self):

        # Liste contenant les boutons de ce menu
        liste_boutons = []

        # On initialise la variable servant à la boucle de ce menu
        self.continuer = 1

        # On importe l'image du menu
        Menu_logo=pygame.image.load(IMG_logo).convert_alpha()

        # On créer les boutons du menu qu'on ajoute à la liste
        liste_boutons.append(Bouton(self.fenetre, '2 joueurs', "self.menu_selection_carte('2','0')", (50, 160)))
        liste_boutons.append(Bouton(self.fenetre, '3 joueurs', "self.menu_selection_carte('3','0')", (296, 160)))
        liste_boutons.append(Bouton(self.fenetre, '4 joueurs', "self.menu_selection_carte('4','0')", (536, 160)))
        liste_boutons.append(Bouton(self.fenetre, 'Solo - 1 bots', "self.menu_selection_carte('1','1')", (50, 310)))
        liste_boutons.append(Bouton(self.fenetre, 'Solo - 2 bots', "self.menu_selection_carte('1','2')", (296, 310)))
        liste_boutons.append(Bouton(self.fenetre, 'Solo - 3 bots', "self.menu_selection_carte('1','3')", (536, 310)))

        liste_boutons.append(Bouton(self.fenetre, 'Options', "self.menu_options()", (50, 480)))
        liste_boutons.append(Bouton(self.fenetre, 'Quitter', "self.continuer = 0", (296, 480)))
        liste_boutons.append(Bouton(self.fenetre, 'Crédits', "self.menu_credits()", (536, 480)))

        # Boucle du menu
        while self.continuer:

            # Limite des FPS
            pygame.time.Clock().tick(fenetre_FPS)

            # Pour tout les bontons du menu ...
            for bouton in liste_boutons:
                # On remet son image initiale
                bouton.reset()

                if(bouton.detection() and pygame.mouse.get_pressed()[0]):   # Si on clique sur le bonton ...
                    bouton.clic()                                               # On met l'image du clic
                elif(bouton.detection()):                                   # Sinon si on met seulement la souris sans cliquer ...
                    bouton.survol()                                             # On met l'image du survol

            # Boucle des évenements
            for event in pygame.event.get():
                if event.type == QUIT:
                    self.continuer = 0 # On quitte la boucle du menu
                elif event.type == MOUSEBUTTONUP and event.button == 1: # Lorsqu'on relache le clic de la souris
                    for bouton in liste_boutons:
                        if(bouton.detection()): # Si le clic est sur le bouton ...
                            exec(bouton.action)     # On execute son action
                            break

            # On remplit l’arrière-plan avec la couleur choisie
            self.fenetre.fill(self.fond_couleur)

            # On affiche le logo
            self.fenetre.blit(Menu_logo,(157,5))

            # On affiche tout les boutons
            for bouton in liste_boutons:
                bouton.afficher()

            # Rafraichissement
            pygame.display.flip()

    def menu_selection_carte(self, nb_perso, nb_bot):

        # Liste contenant les boutons de ce menu
        liste_boutons = []

        # On initialise la variable servant à la boucle de ce menu
        self.continuer_menu = 1

        # On importe l'image du menu
        Menu_logo=pygame.image.load(IMG_logo).convert_alpha()

        # On créer les boutons du menu qu'on ajoute à la liste
        liste_boutons.append(Bouton(self.fenetre, 'Clair', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'petite')", (50, 160)))
        liste_boutons.append(Bouton(self.fenetre, 'Classique', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'classique')", (296, 160)))
        liste_boutons.append(Bouton(self.fenetre, 'Couloirs', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'couloirs')", (536, 160)))

        liste_boutons.append(Bouton(self.fenetre, 'Plaine', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'plaine')", (50, 310)))
        liste_boutons.append(Bouton(self.fenetre, 'Quartier', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'quartier')", (296, 310)))
        liste_boutons.append(Bouton(self.fenetre, 'Micro', "Jeu(self.fenetre, "+nb_perso+", "+nb_bot+", 'micro')", (536, 310)))

        liste_boutons.append(Bouton(self.fenetre, 'Retour', "self.continuer_menu = 0", (296, 480)))

        # Boucle du menu
        while self.continuer_menu:

            #Limite des FPS
            pygame.time.Clock().tick(fenetre_FPS)

            # On actualise l'image du bouton
            for bouton in liste_boutons:
                bouton.reset()

                if(bouton.detection() and pygame.mouse.get_pressed()[0]):
                    bouton.clic()
                elif(bouton.detection()):
                    bouton.survol()

            # Boucle des évenements
            for event in pygame.event.get():
                if event.type == QUIT:
                    self.continuer_menu = 0 # On quitte la boucle du menu
                elif event.type == MOUSEBUTTONUP and event.button == 1: # Lorsqu'on relache le clic de la souris
                    for bouton in liste_boutons:
                        if(bouton.detection()): # Si le clic est sur le bouton ...
                            exec(bouton.action)     # On execute son action
                            break

            # On remplit l’arrière-plan avec la couleur choisie
            self.fenetre.fill(self.fond_couleur)

            # On affiche le logo
            self.fenetre.blit(Menu_logo,(157,5))

            # On affiche tout les boutons
            for bouton in liste_boutons:
                bouton.afficher()

            # Rafraichissement
            pygame.display.flip()

    def menu_options(self):

        # Liste contenant les boutons de ce menu
        liste_boutons = []

        # On initialise la variable servant à la boucle de ce menu
        self.continuer_menu = 1

        # On importe l'image du menu
        Menu_logo=pygame.image.load(IMG_logo).convert_alpha()

        liste_boutons.append(Bouton(self.fenetre, 'Musique', "permutter_musique()", (296, 160)))
        liste_boutons.append(Bouton(self.fenetre, 'Retour', "self.continuer_menu = 0", (296, 480)))

        # Boucle du menu
        while self.continuer_menu:

            #Limite des FPS
            pygame.time.Clock().tick(fenetre_FPS)

            # On actualise l'image du bouton
            for bouton in liste_boutons:
                bouton.reset()

                if(bouton.detection() and pygame.mouse.get_pressed()[0]):
                    bouton.clic()
                elif(bouton.detection()):
                    bouton.survol()

            # Boucle des évenements
            for event in pygame.event.get():
                if event.type == QUIT:
                    self.continuer_menu = 0 # On quitte la boucle du menu
                elif event.type == MOUSEBUTTONUP and event.button == 1: # Lorsqu'on relache le clic de la souris
                    for bouton in liste_boutons:
                        if(bouton.detection()): # Si le clic est sur le bouton ...
                            exec(bouton.action)     # On execute son action
                            break

            # On remplit l’arrière-plan avec la couleur choisie
            self.fenetre.fill(self.fond_couleur)

            # On affiche le logo
            self.fenetre.blit(Menu_logo,(157,5))

            # On affiche tout les boutons
            for bouton in liste_boutons:
                bouton.afficher()

            # Rafraichissement
            pygame.display.flip()

    def menu_credits(self):

        # Liste contenant les boutons de ce menu
        liste_boutons = []

        # On initialise la variable servant à la boucle de ce menu
        self.continuer_menu = 1

        # On importe l'image du menu
        Menu_logo=pygame.image.load(IMG_logo).convert_alpha()

        liste_boutons.append(Bouton(self.fenetre, 'Retour', "self.continuer_menu = 0", (296, 480)))

        # Boucle du menu
        while self.continuer_menu:

            #Limite des FPS
            pygame.time.Clock().tick(fenetre_FPS)

            # On actualise l'image du bouton
            for bouton in liste_boutons:
                bouton.reset()

                if(bouton.detection() and pygame.mouse.get_pressed()[0]):
                    bouton.clic()
                elif(bouton.detection()):
                    bouton.survol()

            # Boucle des évenements
            for event in pygame.event.get():
                if event.type == QUIT:
                    self.continuer_menu = 0 # On quitte la boucle du menu
                elif event.type == MOUSEBUTTONUP and event.button == 1: # Lorsqu'on relache le clic de la souris
                    for bouton in liste_boutons:
                        if(bouton.detection()): # Si le clic est sur le bouton ...
                            exec(bouton.action)     # On execute son action
                            break

            # On remplit l’arrière-plan avec la couleur choisie
            self.fenetre.fill(self.fond_couleur)

            # On affiche le logo
            self.fenetre.blit(Menu_logo,(157,5))

            # On affiche les textes
            font = pygame.font.Font('Data/PoetsenOne.ttf', 32)
            texte = "Jeu créé par Tom Houdayer et Baptiste André"
            text = font.render(texte, 1, (40, 110, 20))
            self.fenetre.blit(text, (50, 160))

            texte = "dans le cadre de l'ISN."
            text = font.render(texte, 1, (40, 110, 20))
            self.fenetre.blit(text, (50, 160 + font.size(texte)[1] + 10))

            texte = "Encadré par Mr Tschaen et Mme Houdayer."
            text = font.render(texte, 1, (40, 110, 20))
            self.fenetre.blit(text, (50, 160 + (font.size(texte)[1] + 10) * 4))

            # On affiche tout les boutons
            for bouton in liste_boutons:
                bouton.afficher()

            # Rafraichissement
            pygame.display.flip()



class Bouton:
    """Classe permettant de gérer les boutons"""

    def __init__(self, fenetre, texte, action, position, couleur=(40, 110, 20), taille_police=64, police=None):
        self.fenetre = fenetre

        self.texte = texte
        self.action = action
        self.position = position
        self.couleur = couleur

        self.taille_police = taille_police
        self.police = police

        self.img_cadre_normal = pygame.image.load(IMG_Menu_bouton).convert_alpha()
        self.img_cadre_survol = pygame.image.load(IMG_Menu_bouton_survol).convert_alpha()
        self.img_cadre_clic = pygame.image.load(IMG_Menu_bouton_clic).convert_alpha()

        self.img_cadre = self.img_cadre_normal
        self.taille = self.img_cadre.get_size()

    def afficher(self):
        # On affiche l'image du cadre
        self.fenetre.blit(self.img_cadre, self.position)

        # On importe la police d'écriture
        font = pygame.font.Font('Data/PoetsenOne.ttf', 32)
        # On créer le rendu (texte vers image)
        text = font.render(self.texte, 1, self.couleur)

        # On calcule la position du texte (au milieu du bouton)
        texte_position = (self.position[0] + self.taille[0]/2 - font.size(self.texte)[0]/2, self.position[1] + self.taille[1]/2 - font.size(self.texte)[1]/2)

        # On affiche le texte
        self.fenetre.blit(text, texte_position)

    def detection(self):
        # On récupère la position de la souris
        souris_position = pygame.mouse.get_pos()
        # On vérifie que la position de la souris soit dans le bouton
        if(self.position[0]<souris_position[0]<self.position[0]+self.taille[0] and self.position[1]<souris_position[1]<self.position[1]+self.taille[1]):
            return True
        else:
            return False

    def reset(self):
        # On remet l'image normale
        self.img_cadre = self.img_cadre_normal

    def survol(self):
        # On met l'image de survol
        self.img_cadre = self.img_cadre_survol

    def clic(self):
        # On met l'image de clic
        self.img_cadre = self.img_cadre_clic

def permutter_musique():
    if(pygame.mixer.music.get_busy()):  # Si la musique est lancée ...
        pygame.mixer.music.stop()           # on l'arrête
    else:                               # Sinon ...
        pygame.mixer.music.play()           # on l'a lance