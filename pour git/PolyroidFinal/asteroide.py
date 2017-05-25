import time
import random
import pygame
import math

class Asteroide(pygame.sprite.Sprite):

    def __init__(self, vitesse, angleDeg, etat, screenWidth, screenHeight, xpos, ypos):
        #Constantes
        self.screenWidth = screenWidth
        self.screenHeight = screenHeight
        self.vitesse=vitesse
        self.etat=etat
        if (xpos == None or ypos == None) :
            self.position=self.randPosition()
        else :
            self.position= [xpos, ypos]       
        self.angleDeg=angleDeg
        self.angleRad=self.angleDeg*math.pi/180

        #Variables
	if etat >=3 :
        	self.invulnerable = True
	else :
		self.invulnerable = False

        #Temps
        self.spawnMillis = int(round(time.time() * 1000))
        self.currentMillis = int(round(time.time() * 1000))

        #Affichage
        pygame.sprite.Sprite.__init__(self)
        
        if (self.etat >=3):
            self.image=pygame.image.load("asteroideE3Spawn.xcf").convert()
        if (self.etat ==2):
            self.image=pygame.image.load("asteroideE2.xcf").convert()
        if (self.etat <=1):
            self.image=pygame.image.load("asteroideE1.xcf").convert()
            
        self.rect=self.image.get_rect()
        self.spriteWidth = self.rect.width
        self.spriteHeight = self.rect.height
        self.rect.x=self.position[0]
        self.rect.y=self.position[1]
     

    def spawn(self): ##Check SpawnTime
        if ((int(round(time.time()*1000)) - self.spawnMillis) > 1000) :
            return False
        else :
            return True

    def randAngle(self):
        a=random.randint(0,360)
        return (a)

    def randPosition(self):
        x=random.randint(0,640)
        y=random.randint(0,480)
        return [x,y]

    def deplacement(self): #Update aussi l'invulnerabilite
        ##Calcul de dT
        newMillis = int(round(time.time() * 1000))
        deltaMillis = -self.currentMillis + newMillis
        ##Calcul de la nouvelle position
        self.position[0] += (self.vitesse * math.cos(self.angleRad) * deltaMillis)/5
        self.position[1] += (self.vitesse * math.sin(self.angleRad) * deltaMillis)/5
        ##Sortie ecran                
        if ((self.position[0] + self.spriteWidth) < 0):
            self.position[0] = self.screenWidth
        elif(self.position[0] > self.screenWidth):
            self.position[0] = -self.spriteWidth
        elif((self.position[1] + self.spriteHeight) < 0):
            self.position[1] = self.screenHeight
        elif(self.position[1] > self.screenHeight):
            self.position[1] = -self.spriteHeight
        ##Application de la nouvelle position
        self.rect.x=self.position[0]
        self.rect.y=self.position[1]
        ##Mise a jour du temps
        self.currentMillis = newMillis

        #Update d'invulnerabilite
        if (self.invulnerable) :
            deltaMillis = newMillis - self.spawnMillis
            if (deltaMillis > 2000) :
                self.invulnerable = False
                if (self.etat >=3):
                    self.image=pygame.image.load("asteroideE3.xcf").convert()
                if (self.etat ==2):
                    self.image=pygame.image.load("asteroideE2.xcf").convert()
                if (self.etat <=1):
                    self.image=pygame.image.load("asteroideE1.xcf").convert()
        
        return
        
    def destruction(self):
        asteroide1 = None
        asteroide2 = None
        asteroideMere = self
        if (self.etat > 1) :
            asteroide1 = Asteroide(self.vitesse, (self.angleDeg +90)%360, self.etat-1, self.screenWidth, self.screenHeight, asteroideMere.position[0], asteroideMere.position[1])
            asteroide2 = Asteroide(self.vitesse, (self.angleDeg -90)%360, self.etat-1, self.screenWidth, self.screenHeight, asteroideMere.position[0], asteroideMere.position[1])
        del self
        return (asteroideMere, asteroide1, asteroide2)
