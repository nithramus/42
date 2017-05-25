# -*- coding: utf-8 -*-

'''
Created on 3 Jul 2013

@author: pigeau-a
'''

from client import Client
from common.constante import Constante

client = Client('127.0.0.1','8080')

#print(str(client.inscriptionPartie("Gerard")))
#
#print(str(client.getTailleFenetre()))
#print(str(client.getTailleCase()))
#print(str(client.getPositionBut()))
#print(str(client.getPositionBut()[0]))
#print(str(client.getPositionBut()[1]))
#print(str(client.getNombreCaseMax()))
#print(str(client.getNombreCaseMax()[0]))
#print(str(client.getNombreCaseMax()[1]))
#print(str(client.getListeMurs()))
#print(str(client.getListeMurs()[0]))
#print(str(client.getListeMurs()[1]))
# 
#print(client.deplacement("Gerard", 'N'))
#print(client.deplacement("Gerard", 'S'))

nomFonction = 'deplacement'
parametre =  [('direction', 'N'), ('joueur', 'Jean')]
client._query_generic(nomFonction, parametre)

#if __name__ == "__main__":
    #main()