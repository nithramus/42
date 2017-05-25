'''
Created on 17 nov. 2015

@author: E145746U
'''

import time

class Bombe:
    
    def __init__(self,posBombe,rangeBombe, numJoueur):
        self.positionBombe=posBombe
        self.rangeBombe=rangeBombe
        self.datePose=time.time()
        self.numJoueur = numJoueur

        
