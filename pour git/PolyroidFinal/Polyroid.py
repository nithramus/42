# -*- coding: cp1252 -*-
import pygame
from pygame.locals import *
import math
from asteroide import Asteroide
import random
from missile import *
from Menu import *


class Mur(pygame.sprite.Sprite):
    """Classe permettant de gérer les murs"""

    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("trou-noir.jpg").convert()
        self.rect =  self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

class Vaisseau(pygame.sprite.Sprite):
    "class du vaisseau"

    def __init__(self, x, y,num_vaisseau):
        pygame.sprite.Sprite.__init__(self)
        if num_vaisseau == 1:
            self.image = pygame.image.load("vaisseauR.gif").convert()
            self.imageOrigine=pygame.image.load("vaisseauR.gif").convert()
        if num_vaisseau == 2:
            self.image = pygame.image.load("vaisseauB.gif").convert()
            self.imageOrigine=pygame.image.load("vaisseauB.gif").convert()
        self.rect =  self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        self.angle = 0
        self.vitesse = 0
        self.num_vaisseau = num_vaisseau
        self.vie = 3
        self.invulnerable = True
        self.temps = pygame.time.get_ticks()
        
    def deviensInvulnerable (self):
        self.invulnerable = True
        self.temps = pygame.time.get_ticks()

    def invulnerabilite(self):
        if (pygame.time.get_ticks() - self.temps) > 2000:
            self.invulnerable = False
        
    def deplacement(self):
        #vaisseau 1

        if pygame.key.get_pressed()[pygame.K_UP]:
                if self.num_vaisseau == 1:
                    if self.vitesse < 20:
                        self.vitesse += 1.3
                
       
        if self.num_vaisseau == 1:
            if self.vitesse >0:
                self.vitesse -= 0.3
                self.rect.x = self.rect.x - self.vitesse*math.sin((self.angle*math.pi)/180)
                self.rect.y = self.rect.y - self.vitesse*math.cos((self.angle*math.pi)/180)
        if pygame.key.get_pressed()[pygame.K_LEFT]:
            if self.num_vaisseau == 1:
                self.angle =(self.angle+15)%360
                self.image = rot_center(self.imageOrigine,self.angle)
                
        if pygame.key.get_pressed()[pygame.K_RIGHT]:
            if self.num_vaisseau == 1:
                self.angle=(self.angle-15)%360
                self.image = rot_center(self.imageOrigine,self.angle)
               

    #Vaisseau 2
        
        if pygame.key.get_pressed()[pygame.K_z]:
                if self.num_vaisseau == 2:
                    if self.vitesse <20:
                        self.vitesse += 1.3
                
        if self.num_vaisseau == 2:
            if self.vitesse >0:
                self.vitesse -= 0.3
                self.rect.x = self.rect.x - self.vitesse*math.sin((self.angle*math.pi)/180)
                self.rect.y = self.rect.y - self.vitesse*math.cos((self.angle*math.pi)/180)
        if pygame.key.get_pressed()[pygame.K_q]:
            if self.num_vaisseau == 2:
                self.angle +=15
                self.image = rot_center(self.imageOrigine,self.angle)
               
        if pygame.key.get_pressed()[pygame.K_d]:
            if self.num_vaisseau == 2:
                self.angle-=15
                self.image = rot_center(self.imageOrigine,self.angle)
               

        if ((self.rect.x + self.rect.width) < 0):
            self.rect.x = screenWidth
        elif(self.rect.x > screenWidth):
            self.rect.x = -self.rect.width
        elif((self.rect.y + self.rect.height) < 0):
            self.rect.y = screenHeight
        elif(self.rect.y > screenHeight):
            self.rect.y = -self.rect.height
        


def afficher():
    liste_missile.draw(fenetre)
    liste_mur.draw(fenetre)
    liste_vaisseau.draw(fenetre)
    listeAsteroide.draw(fenetre)
    
    "Affiche le chronomètre de la partie"
    font = pygame.font.Font(None, 32)
    texte = "{:02.0f}:{:02.0f}".format(duree//60, duree%60)
    text = font.render(texte, 1, (250, 250, 250))
    fenetre.blit(text, ((screenWidth/2)-(font.size(texte)[0]/2), (10-(font.size(texte)[1]/2))))
    for vaisseau in liste_vaisseau:
        if vaisseau.num_vaisseau==1:
            for i in range (0,vaisseau.vie):
                pygame.draw.rect(fenetre,(255,255,255),(30*i,10,15,15))

        if vaisseau.num_vaisseau==2:
            for i in range (0,vaisseau.vie):
                pygame.draw.rect(fenetre,(255,255,255),(800+30*i,10,15,15))
    pygame.display.flip()

def afficherfin():
    liste_vaisseau.draw(fenetre)
    for vaisseau in liste_vaisseau:
        if vaisseau.num_vaisseau==1:
            for i in range (0,vaisseau.vie):
                pygame.draw.rect(fenetre,(255,255,255),(30*i,10,15,15))

        if vaisseau.num_vaisseau==2:
            for i in range (0,vaisseau.vie):
                pygame.draw.rect(fenetre,(255,255,255),(800+30*i,10,15,15))
    pygame.display.flip()    

def rot_center(image, angle):
    """rotate an image while keeping its center and size"""
    orig_rect = image.get_rect()
    rot_image = pygame.transform.rotate(image, angle)
    rot_rect = orig_rect.copy()
    rot_rect.center = rot_image.get_rect().center
    rot_image = rot_image.subsurface(rot_rect).copy()
    return rot_image

def dashEtQuit():
     for event in pygame.event.get():
        if event.type == pygame.QUIT:
                pygame.quit()

        if event.type == KEYDOWN :
            for vaisseau in liste_vaisseau :
                if vaisseau.num_vaisseau == 1:
                    if event.key == K_KP1:
                        vaisseau.rect.x = vaisseau.rect.x - 40*math.sin(math.pi/2 + (vaisseau.angle*math.pi)/180)
                        vaisseau.rect.y = vaisseau.rect.y - 40*math.cos(math.pi/2 +(vaisseau.angle*math.pi)/180)
                    
                    if event.key == K_KP3:
                        vaisseau.rect.x = vaisseau.rect.x - 40*math.sin(-math.pi/2 + (vaisseau.angle*math.pi)/180)
                        vaisseau.rect.y = vaisseau.rect.y - 40*math.cos(-math.pi/2 +(vaisseau.angle*math.pi)/180)

                    if event.key == K_KP0:
                        posMissile1=positionMissile(vaisseau)
                        missile=Missile(posMissile1,vaisseau.angle,0.5,0,screenWidth,screenHeight)
                        liste_missile.add(missile)
                        pygame.mixer.music.load("tir-etienne.wav")
                        pygame.mixer.music.play()
                        
                if vaisseau.num_vaisseau == 2:
                    if event.key == pygame.K_g:
                        vaisseau.rect.x = vaisseau.rect.x - 40*math.sin(math.pi/2 + (vaisseau.angle*math.pi)/180)
                        vaisseau.rect.y = vaisseau.rect.y - 40*math.cos(math.pi/2 +(vaisseau.angle*math.pi)/180)
                        
                    if event.key == K_j:
                        vaisseau.rect.x = vaisseau.rect.x - 40*math.sin(-math.pi/2 + (vaisseau.angle*math.pi)/180)
                        vaisseau.rect.y = vaisseau.rect.y - 40*math.cos(-math.pi/2 +(vaisseau.angle*math.pi)/180)

                    if event.key == K_SPACE:
                        posMissile2=positionMissile(vaisseau)
                        missile=Missile(posMissile2,vaisseau.angle,0.5,0,screenWidth,screenHeight)
                        liste_missile.add(missile)
                        pygame.mixer.music.load("tir-etienne.wav")
                        pygame.mixer.music.play()


def positionMissile(vaisseau):
    centreVaisseau=[vaisseau.rect.x+vaisseau.rect.width/2,vaisseau.rect.y+vaisseau.rect.height/2]
    positionMissile = centreVaisseau    
    return positionMissile

def asteroideSpawn(listeasteroid, spawnCD, lastSpawnTime): #La fonction asteroideSpawn met aussi a jour la date du dernier spawn
  newTime = int(round(time.time()))
  deltaTime = newTime - lastSpawnTime
  if(deltaTime >= spawnCD) :
     Ashe = Asteroide(1, random.randint(0,360), 3, screenWidth, screenHeight, None, None)
     listeAsteroide.add(Ashe)
     return newTime
  return lastSpawnTime
    
pygame.init()

#Ouverture de la fenêtre Pygame
screenWidth = 1200
screenHeight = 700
fenetre = pygame.display.set_mode((screenWidth, screenHeight))


continuer = True
continuerMenu = True

while continuerMenu:
    menu = Menu(fenetre)
    #liste de sprites
    liste_mur = pygame.sprite.Group()
    liste_vaisseau = pygame.sprite.Group()
    liste_missile = pygame.sprite.Group()
    #initialisation du joueur
    joueur1 = Vaisseau(300,300,1)
    joueur2 = Vaisseau(900,300,2)
    liste_vaisseau.add(joueur1)
    liste_vaisseau.add(joueur2)

    #intialisation des astéroides
    listeAsteroide=pygame.sprite.Group()
    asteroide=Asteroide(0.5, random.randint(0,360), 3, screenWidth, screenHeight, None, None)
    listeAsteroide.add(asteroide)
    #spawndefou
    AsteroideSpawnCD = 5
    AsteroideLastSpawnTime = int(round(time.time()))

    #initialisation des murs
    mur = Mur(screenWidth/2,screenHeight/2)
    liste_mur.add (mur)

    #initialisation du temps
    duree = 0
    continuer = True
    #boucle principale
    while continuer :
        pygame.draw.rect(fenetre,(0,0,0),(0,0,screenWidth,screenHeight))
        #on limite le nombre de boucles
        pygame.time.Clock().tick(30)
        duree += 0.33
        
        #ON GERE LES DASH
        dashEtQuit()

        #Vaisseau 
        for vaisseau in liste_vaisseau:
            vaisseau.deplacement()
        #missiles
        for missile in liste_missile:
            missile.deplacement()
        #asteroides
        spawnParam = asteroideSpawn(listeAsteroide, AsteroideSpawnCD, AsteroideLastSpawnTime) #La fonction asteroideSpawn renvoi (DateDernierSpawn)
        AsteroideLastSpawnTime = spawnParam
        
        for asteroide in listeAsteroide:
            asteroide.deplacement()
        
        #GESTION DES COLLISION
        col_vaisseau_mur = pygame.sprite.groupcollide(liste_vaisseau, liste_mur, False, False)
        for vaisseau in col_vaisseau_mur:
            vaisseau.invulnerabilite()
            vaisseau.vitesse = 0
            vaisseau.rect.x -=15
            vaisseau.rect.y -=15

               
              
        col_vaisseau_asteroide = pygame.sprite.groupcollide(liste_vaisseau, listeAsteroide, False, False)
        for vaisseau in col_vaisseau_asteroide:
            vaisseau.invulnerabilite()
            if not vaisseau.invulnerable:
                vaisseau.vie -= 1
                vaisseau.deviensInvulnerable()
            if vaisseau.vie ==0:
                pygame.mixer.music.load("XAVIEREXPLOSION.wav")
                pygame.mixer.music.play()
                liste_vaisseau.remove(vaisseau)
                explosion = pygame.image.load("explosion.xcf").convert()
                fenetre.blit(explosion, (0,0))
                pygame.display.flip()
                afficherfin()
                pygame.time.wait(3000)
                continuer = False
          
               
        col_vaisseau_missile = pygame.sprite.groupcollide(liste_vaisseau, liste_missile, False, False)
        for vaisseau in col_vaisseau_missile:
            vaisseau.invulnerabilite()
            if not vaisseau.invulnerable:
                vaisseau.vie -= 1
                vaisseau.deviensInvulnerable()
            if vaisseau.vie ==0:
                pygame.mixer.music.load("XAVIEREXPLOSION.wav")
                pygame.mixer.music.play()
                liste_vaisseau.remove(vaisseau)
                explosion = pygame.image.load("explosion.xcf").convert()
                fenetre.blit(explosion, (0,0))
                pygame.display.flip()
                afficherfin()
                pygame.time.wait(3000)
                continuer = False

        missileDetruit=pygame.sprite.Group()

        asteroide_touche = pygame.sprite.groupcollide(liste_missile, listeAsteroide, False, False)
        for asteroide in asteroide_touche:
            missileDetruit.add(missile)

        col_asteroide_missile = pygame.sprite.groupcollide(listeAsteroide, liste_missile, False, False)
        for asteroide in col_asteroide_missile:
            if (not asteroide.invulnerable) :
                div = asteroide.destruction()
                listeAsteroide.remove(div[0])
                if (div[1] != None) :
                    listeAsteroide.add(div[1])
                if (div[2] != None) :
                    listeAsteroide.add(div[2])
                for missile in missileDetruit:
                    liste_missile.remove(missile)
            
        col_asteroide_vaisseau = pygame.sprite.groupcollide(listeAsteroide, liste_vaisseau, False, False)
        for asteroide in col_asteroide_vaisseau:
            if (not asteroide.invulnerable) :
                div = asteroide.destruction()
                listeAsteroide.remove(div[0])
                if (div[1] != None) :
                    listeAsteroide.add(div[1])
                if (div[2] != None) :
                    listeAsteroide.add(div[2])

        mur_touche = pygame.sprite.groupcollide(listeAsteroide, liste_mur, False, False)

        col_missile_vaisseau = pygame.sprite.groupcollide(liste_missile, liste_vaisseau, False, False)
        for missile in col_missile_vaisseau:
            if (not missile.invulnerable):
                liste_missile.remove(missile)

        mur_touche = pygame.sprite.groupcollide(liste_missile, liste_mur, False, False)
        for missile in mur_touche:
            liste_missile.remove(missile)


                
        afficher()
    


   
