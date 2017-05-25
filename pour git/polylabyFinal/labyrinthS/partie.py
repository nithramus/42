# -*- coding: utf-8 -*-

'''
Created on 3 Jul 2013

@author: pigeau-a
'''
from common.constante import Constante
from joueur import Joueur
import pygame.display
import random
import time
from bombe import Bombe

# STRUCTURE DE DONNEES POUR REPRESENTER L'ETAT DU JEU A UN INSTANT DONNE.

class Partie:

    # FONCTION D'INITIALISATION       
    def __init__(self):
        self.joueurs={}
        self.joueur=[]
        self.nbBombepose = [0,0,0,0]
        self.tailleCase=Constante.TAILLE_CASE
        self.taillePlateauX=Constante.TAILLE_FENETRE[0]
        self.taillePlateauY=Constante.TAILLE_FENETRE[1]
        self.nbCasesX=self.taillePlateauX/self.tailleCase
        self.nbCasesY=self.taillePlateauY/self.tailleCase
        self.etat=Constante.ETAT_INSCRIPTION_OUVERTE
        self.map=self.readMap("labyrinthS/bucarest01.txt")
        self.bonus=self.readMap("labyrinthS/bucarest_bonus01.txt")
        self.listeBombe = []
        self.listeExplosion = []
        self.etat = 0
               
    def readMap(self,filename):
        f=open(filename,"r")
        listeColonne=[]
        for line in f:
            listeLigne=[]
            for i in line:
                if i!='\n':
                    listeLigne.append(i)
            listeColonne.append(listeLigne)
        f.close()
        return listeColonne

    def ajouterJoueur(self, joueur):
        print("user ", joueur.nom)
        self.joueurs[joueur.nom] = joueur        
        
    def recupererJoueur(self, nom):
        return self.joueurs[nom]    

    def estDejaAjouter(self, joueur):
        return joueur.nom in self.joueurs

    # FONCTIONS DE GESTION DES DEPLACEMENTS
    
        """
    fonction testant si le deplacement est possible ou non
    @param direction: la direction demande par le joueur Q:quitter, N:Nord, S:South, W:West, E:Est, G:Gagne
    @param joueur: le joueur qui demande le deplacement   
    @return: SORTIE_NOT_OK si deplacement non possible, SORTIE_OK si deplacement possible, SORTIE_PARTIE_FINIE si la partie est deja finie
    """
    def deplacement(self, direction, joueur):
        print("deplacement: ", direction, " ", joueur.nom)
        reponse = (Constante.SORTIE_NOT_OK, 0)    
        (dx,dy) = self.direction(direction) # recupere le deplacement
        (x, y)  = joueur.positionJoueur       
        new_pos = (x+dx, y+dy)        
        if not self.collision(new_pos):
            if not self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]==Constante.MAP_BOMBE:
                self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]=Constante.MAP_VIDE
            joueur.positionJoueur = new_pos
            if self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]==Constante.MAP_BONUS_RANGE:
                joueur.bombeRange=joueur.bombeRange+1
            elif self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]==Constante.MAP_BONUS_SPEED:
                joueur.vitesse=joueur.vitesse+1
            elif self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]==Constante.MAP_BONUS_MAX_BOMBE:
                joueur.nbBombeMax=joueur.nbBombeMax+1
            if joueur.numJoueur==1:
                self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]=Constante.MAP_J1
            elif joueur.numJoueur==2:
                self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]=Constante.MAP_J2
            elif joueur.numJoueur==3:
                self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]=Constante.MAP_J3
            elif joueur.numJoueur==4:
                self.map[joueur.positionJoueur[1]][joueur.positionJoueur[0]]=Constante.MAP_J4
            reponse = (Constante.SORTIE_OK, new_pos)       
        else:
            reponse = (Constante.SORTIE_NOT_OK, joueur.positionJoueur)                  
        return reponse

    """
    conversion d'une demande de deplacement en deplacement reelle sur le plateau.
    Par exemple, un deplacement au nord entraine de rester sur la meme colonne et de descendre de 1 pour la ligne: (0,-1)
    (pour rappel, (0,0) est situe en haut a gauche du plateau, l'axe y est croissant vers le bas et l'axe x est croissant vers la droite
    """
    def direction(self, direction):
        if direction == "S":
            return (0,1)
        if direction == "N":
            return (0,-1)
        if direction == "W":
            return (-1,0)
        if direction == "E":
            return (1,0)
        else:
            return (0,0)
    
    """
    Fonction testant si un deplacement est empeche par un mur ou par une sortie du plateau
    @return: True si pas de collision, False sinon
    """
    def collision(self, position):
        x = position[0]
        y = position[1]
        return (((x>=self.nbCasesX or x<0) or (y>=self.nbCasesY or y<0)) or (self.map[y][x]==Constante.MAP_MUR or self.map[y][x]==Constante.MAP_BLOC or self.map[y][x]==Constante.MAP_BOMBE)) 
    
    def destructionMur(self,posMur):
        self.map[posMur[1]][posMur[0]]=self.bonus[posMur[1]][posMur[0]]
        
    def tuerJoueur(self,numJoueur):
        for joueur in self.joueurs:
            if self.joueurs[joueur].numJoueur==numJoueur:
                self.joueurs[joueur].vivant = False
        
    def explosionBombe(self,bombe):
        self.map[bombe.positionBombe[1]][bombe.positionBombe[0]]= Constante.MAP_EXPLOSION
        listePositionExplosion =[bombe.positionBombe]
        self.nbBombepose[bombe.numJoueur-1] -=1
        self.listeBombe.remove(bombe)
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        for j in range(0,4):
            for i in range(bombe.rangeBombe+1):
                direction=(directions[j][0]*i,directions[j][1]*i)
                positionExplosion = (bombe.positionBombe[0]+direction[0],bombe.positionBombe[1]+direction[1])
                if ((positionExplosion[0]<self.nbCasesX and positionExplosion[0]>=0) and (positionExplosion[1]<self.nbCasesY and positionExplosion[1]>=0)) :
                    if self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_MUR:
                        self.destructionMur(positionExplosion)
                        
                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_BONUS_RANGE or self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_BONUS_SPEED or self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_BONUS_MAX_BOMBE:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)

                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_J1:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)
                        self.tuerJoueur(1)
                        
                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_J2:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)
                        self.tuerJoueur(2)
                       
                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_J3:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)
                        self.tuerJoueur(3)
                        
                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_J4:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)
                        self.tuerJoueur(4)
                        
                    elif self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_VIDE:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        listePositionExplosion.append(positionExplosion)
                        
                    elif i!=0 and self.map[positionExplosion[1]][positionExplosion[0]]==Constante.MAP_BOMBE:
                        self.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_EXPLOSION
                        self.explosionBombe(self.chercheBombe(positionExplosion))
        return listePositionExplosion
            
    def chercheBombe(self,positionExplosion):
        for bombe in self.listeBombe:
            if bombe.positionBombe==positionExplosion :
                return bombe
