import pygame
import math
import time

class Missile(pygame.sprite.Sprite):

    def __init__(self,position,angle,vitesse,bonus,screenWidth,screenHeight):
        pygame.sprite.Sprite.__init__(self)
        self.angleDeg=angle+90
        self.angleRad=self.angleDeg*math.pi/180
        self.imageOrigine=pygame.image.load("missileCarre.png").convert()
        self.image=self.rot_center().convert()
        self.rect=self.image.get_rect()
        self.position=self.positionMissile(position)
        self.rect.x=self.position[0]
        self.rect.y=self.position[1]
        self.vitesse=vitesse
        self.bonus=bonus
        self.spriteWidth=self.rect.width
        self.spriteHeight=self.rect.height
        self.screenWidth=screenWidth
        self.screenHeight=screenHeight

        self.spawnMillis = int(round(time.time() * 1000))
        self.currentMillis = int(round(time.time() * 1000))
        self.invulnerable = False

    def deplacement(self):
        ##Calcul de dT
        newMillis = int(round(time.time() * 1000))
        deltaMillis = self.currentMillis - newMillis
        ##Calcul de la nouvelle position
        self.position[0] -= self.vitesse * math.cos(self.angleRad) * deltaMillis
        self.position[1] += self.vitesse * math.sin(self.angleRad) * deltaMillis
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
            deltaMillis = self.currentMillis - self.spawnMillis
            if (deltaMillis > 1000):
                self.invulnerable = False
                    
        return

    def rot_center(self):
        """rotate an image while keeping its center and size"""
        orig_rect = self.imageOrigine.get_rect()
        rot_image = pygame.transform.rotate(self.imageOrigine,self.angleDeg)
        rot_rect = orig_rect.copy()
        rot_rect.center = rot_image.get_rect().center
        rot_image = rot_image.subsurface(rot_rect).copy()
        return rot_image

    def positionMissile(self, position):
        centreMissile=[position[0]+self.rect.width/2,position[1]+self.rect.height/2]
        print(self.angleRad)
        print(centreMissile)
        centreMissile[0] += -5 + math.cos(self.angleRad)*65
        centreMissile[1] += -5 - math.sin(self.angleRad)*65
        print(centreMissile)
        return centreMissile
