# -*- coding: utf-8 -*-

'''
Created on 4 Jul 2013

@author: cohen, pigeau
'''
import time

import pygame
from common.constante import Constante


# STRUCTURE DE DONNEES POUR REPRESENTER L'ETAT DU JEU A UN INSTANT DONNE.
      
class State : 
        
    def __init__(self, position, nomJoueur):
        self.positionJoueur = position
        self.nomJoueur = nomJoueur
        self.map = []
        self.partiePerdue = False
        self.partieGagne = False
        self.tailleCase = 0
        self.taillePlateau = (0,0)
        self.nbCasesX = 0
        self.nbCasesY = 0
        
        self.tempsDeplacement = 0
        self.tempsPasChange = False
               

# FONCTIONS POUR L'ARRET DU JEU

def contient_quit(event):
    #for event in ev_list:
    if( event != None):   
        if (event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE) ): 
            return True
    return False

def traite_fin_jeu(state):
    print ("Fin.\n")
    pygame.quit()
    


# FONCTIONS DE GESTION DES ACTIONS

def modifie_nom(state, nom):
    state.nom = nom


def traite_actions_joueur(client, state):
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                (statut, new_pos) = client.deplacement(state.nomJoueur, "N")
            if event.key == pygame.K_DOWN:
                (statut, new_pos)=client.deplacement(state.nomJoueur, "S")
            if event.key == pygame.K_LEFT:
                (statut, new_pos)=client.deplacement(state.nomJoueur, "W")
            if event.key == pygame.K_RIGHT:
                (statut, new_pos)=client.deplacement(state.nomJoueur, "E")
            if event.key == pygame.K_SPACE:
                client.poseBombe(state.nomJoueur)
    
def animationHaut(fenetre, state, newPos):
    temps = time.time()-state.tempsDeplacement
    tempsAnimation = 1
    for t in range (1,9):
        if temps < t*tempsAnimation :
            fenetre.blit(state.Face1, (state.positionJoueur[0]*32,state.positionJoueur[1]*32 - t*4))
            break
        else:
            state.positionJoueur = newPos
            state.tempsPasChange = True
        
def animationBas(fenetre, state, newPos):
    temps = time.time()-state.tempsDeplacement
    tempsAnimation = 1
    for t in range (1,9):
        if temps < t*tempsAnimation :
            fenetre.blit(state.Face1, (state.positionJoueur[0]*32,state.positionJoueur[1]*32 + t*4))
            break
        else:
            state.positionJoueur = newPos
            state.tempsPasChange = True
def animationDroite(fenetre, state, newPos):
    temps = time.time()-state.tempsDeplacement
    tempsAnimation = 1
    for t in range (1,9):
        if temps < t*tempsAnimation :
            fenetre.blit(state.Face1, (state.positionJoueur[0]*32+t*4,state.positionJoueur[1]*32))
            break
        else:
            state.positionJoueur = newPos
            state.tempsPasChange = True        
def animationGauche(fenetre, state, newPos):
    temps = time.time()-state.tempsDeplacement
    tempsAnimation = 1
    for t in range (1,9):
        if temps < t*tempsAnimation :
            fenetre.blit(state.Face1, (state.positionJoueur[0]*32-t*4,state.positionJoueur[1]*32))
            break
        else:
            state.positionJoueur = newPos
            state.tempsPasChange = True
#def collision (param, liste_murs, max_x, max_y):
#    x = param[0]
#    y = param[1]
#    return ( x >= max_x or
#           x < 0      or 
#           y >= max_y or 
#           y < 0      or 
#           ((x,y) in liste_murs) 
#           )
      
# BOUCLE PRINCIPALE
def gere_etat(client, fen, image_joueur, state, facteur):
    event = None
    continuer = 1
    tour=0
    while not (contient_quit(event)) and not state.partiePerdue and not state.partieGagne:
        tour+=1
        traite_actions_joueur(client, state) 
        state.map= client.getMap()
        dessine_map(fen, state, facteur)
        pygame.display.flip()

# FONCTION D'INITIALISATION
def init(client, state):
    surface_sprite = pygame.image.load("pac8.png").convert_alpha()
    state.tailleCase = client.getTailleCase()
    state.taillePlateau = client.getTaillePlateau()
    state.nbCasesX = state.taillePlateau[0]/state.tailleCase
    state.nbCasesY = state.taillePlateau[1]/state.tailleCase
    state.positionJoueur = (3,3)
    state.map = client.getMap()
    
    return surface_sprite

# FONCTION DE LANCEMENT DU JEU : INITIALISATION, BOUCLE PRINCIPALE, FIN DU JEU
def start(client, nomJoueur, fenetre, ip): 
    state = State((0,0), nomJoueur)
    client.inscriptionPartie(state.nomJoueur)
    state.bombe = pygame.image.load("Bombe.png").convert_alpha()
    state.extrabomb = pygame.image.load("ExtraBombe.png").convert_alpha()
    state.Face1 = pygame.image.load("Face1.png").convert_alpha()
    state.Mur_destructible = pygame.image.load("Mur_destructible.png").convert_alpha()
    state.Mur_indestructible = pygame.image.load("Mur_indestructible.png").convert_alpha()
    facteur = 32
    # INITIALISER
    surf = init(client, state)
    #On n'affiche qu'une seule fois les murs indestructibles
    for j in range(len(state.map)):
        for i in range(len(state.map[j])):
            if state.map[j][i]==Constante.MAP_MUR:
                fenetre.blit(state.Mur_indestructible, (i*facteur,j*facteur) )
    # BOUCLE PRINCIPALE
    gere_etat(client, fenetre, surf, state, facteur)
    # FERMER
    #traite_fin_jeu(s0)

# FONCTIONS POUR L'AFFICHAGE

def transpose (param, facteur) :
    x = param[0]
    y = param[1]
    return (x* facteur, y*facteur)

def dessine_joueur (fenetre, pos, facteur, image): 
    fenetre.blit(image, transpose(pos, facteur)) 


def dessine_map(fenetre, state, facteur): 
    
    for j in range(len(state.map)):
        for i in range(len(state.map[j])):
            if state.map[i][j]==Constante.MAP_VIDE:
                pygame.draw.rect(fenetre,(255,255,255),(i*facteur,j*facteur,32,32))
            elif state.map[i][j]==Constante.MAP_J1:
                if state.positionJoueur != (i,j):
                    pygame.draw.rect(fenetre,(255,255,255),(i*facteur,j*facteur,32,32))
                    if state.tempsPasChange:
                        state.tempsDeplacement = time.time()
                        state.tempsPasChange = False
                    if state.positionJoueur[0]>j:
                        animationHaut(fenetre, state,(i,j))
                    if state.positionJoueur[0]<j:
                        animationBas(fenetre,state,(i,j))
                    if state.positionJoueur[1]>i:
                        animationDroite(fenetre,state,(i,j))
                    if state.positionJoueur[1]<i:
                        animationGauche(fenetre,state,(i,j))
                else:
                    fenetre.blit(state.Face1, (i*facteur,j*facteur) )
                
            elif state.map[j][i]==Constante.MAP_J2:
                fenetre.blit(state.Face1, (i*facteur,j*facteur))
            elif state.map[j][i]==Constante.MAP_J3:
                fenetre.blit(state.Face1, (i*facteur,j*facteur))
            elif state.map[j][i]==Constante.MAP_J4:
                fenetre.blit(state.Face1, (i*facteur,j*facteur))
            elif state.map[j][i]==Constante.MAP_BOMBE:
                fenetre.blit(state.bombe, (i*facteur,j*facteur) )
            elif state.map[j][i]==Constante.MAP_BLOC:
                fenetre.blit(state.Mur_destructible, (i*facteur,j*facteur))
            elif state.map[j][i]==Constante.MAP_EXPLOSION:
                fenetre.blit(state.explosion, (i*facteur,j*facteur))
            
                
                
    pygame.display.flip()    
    
   

# LANCEMENT DU JEU
# This isn't run on Android.
if __name__ == "__main__":
    start()
