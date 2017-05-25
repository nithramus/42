import time
import random
import pygame
import math

class Asteroide(pygame.sprite.Sprite):

    def __init__(self, vitesse, angleDeg, etat, screenWidth, screenHeight):
        self.screenWidth = screenWidth
        self.screenHeight = screenHeight

        #Affichage
        pygame.sprite.Sprite.__init__(self)
        self.image=pygame.image.load("asteroide.png").convert()
        self.rect=self.image.get_rect()

        #Constantes classe
        self.vitesse=vitesse  
        self.etat=etat
        self.position=self.randPosition()
        self.angleDeg=angleDeg
        self.angleRad=self.angleDeg*math.pi/180 
        self.spriteWidth = self.rect.width
        self.spriteHeight = self.rect.height

        self.rect.x=self.position[0]
        self.rect.y=self.position[1]

        #Temps
        self.spawnMillis = int(round(time.time() * 1000))
        self.currentMillis = int(round(time.time() * 1000))

    # == (currentMillis-spawn
    def spawn(self):
        if ((int(round(time.time()*1000)) - self.spawnMillis) > 1000) :
            return False
        else :
            return True

    def randAngle(self):
        a=random.randint(0,360)
        return (a)

    def randPosition(self):
        x=random.randint(0,800)
        y=random.randint(0,600)
        return [x,y]

    def deplacement(self):
        ##Calcul de dT
        newMillis = int(round(time.time() * 1000))
        deltaMillis = self.currentMillis - newMillis
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
        return

    def destruction(self):
        if (True) :
            if(True) :
                asteroide1 = None
                asteroide2 = None
                if (self.etat-1 > 0) :
                    asteroide1 = Asteroide(self.vitesse, (self.angleDeg +90)%360, self.etat-1, self.screenWidth, self.screenHeight)
                    asteroide2 = Asteroide(self.vitesse, (self.angleDeg -90)%360, self.etat-1, self.screenWidth, self.screenHeight)
                asteroideMere = self
                del self
                return (asteroideMere, asteroide1, asteroide2)
    
