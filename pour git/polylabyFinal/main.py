# -*- coding: utf-8 -*-

"""
@author: +**+ xX-DarkBouriNator2000-Xx +**+
"""

import labyrinthC.start
import pygame
from common.constante import Constante
import socket
import string
import threading
import labyrinthS.start
from labyrinthC.client import Client
import time


try:
    import android
except ImportError:
    android = None

def executerServeur():
    processServer = threading.Thread(target=labyrinthS.start.lancerServeur)
    processServer.start()
    return processServer

"""
fonction appelee par 
"""
def afficherDialog(screen, message):
    "Affichage d'un message dans une boite au milieu de l'ecran"
    fontobject = pygame.font.Font(None,18)
    pygame.draw.rect(screen, (0,0,0), ((screen.get_width() / 2) - 100, (screen.get_height() / 2) - 10,400,20), 0)
    pygame.draw.rect(screen, (255,255,255), ((screen.get_width() / 2) - 102, (screen.get_height() / 2) - 12, 404,24), 1)
    if len(message) != 0:
        screen.blit(fontobject.render(message, 1, (255,255,255)),((screen.get_width() / 2) - 100, (screen.get_height() / 2) - 10))
    
    pygame.display.flip()

def demandeUtilisateur(screen, question, answer=None):
    "ask(screen, question) -> answer"
    if android:
        android.init()
        android.show_keyboard()
        
    entryAnswer = False
    pygame.font.init()
    
    current_string = []
    
    if not answer == None:
        for i in answer:
            current_string.append(i)
            
    question = question + " : "
    afficherDialog(screen, question + string.join(current_string,""))
    while entryAnswer == False:
        
        event = pygame.event.wait()
            
        if event.type == pygame.KEYDOWN:
            
            inkey = event.key
                
            if inkey == pygame.K_BACKSPACE:
                current_string = current_string[0:-1]
            elif inkey == pygame.K_RETURN:
                entryAnswer = True
            elif inkey == pygame.K_MINUS:
                current_string.append("_")
            elif inkey <= 127:
                current_string.append(chr(inkey))
                    
            afficherDialog(screen, question + " " + string.join(current_string,""))
    
    if android:
        android.hide_keyboard()
    
    return string.join(current_string,"")
    
def lancerServeur(screen):
    continuer =True
    while continuer:
        font = pygame.font.Font(None, 32)
        texte = "cliquez ici pour heberger la partie"
        text = font.render(texte, 1, (255, 255, 255))
        screen.blit(text, (100, 100))
        texte2 = "cliquez ici pour rejoindre une partie"
        text = font.render(texte2, 1, (255, 255, 255))
        screen.blit(text, (100, 400))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.pos[0]>100 and event.pos[0]<300 and event.pos[1]>100 and event.pos[0]<350:
                    continuer = False
                    rep = "y"
                if event.pos[0]>100 and event.pos[0]<300 and event.pos[1]>350 and event.pos[0]<500:
                    continuer = False
                    rep="n"
        pygame.display.flip()
    screen.fill((0,0,0))
    pygame.display.flip()
    return rep

def main():
    pygame.init()
    
    fenetre = pygame.display.set_mode(Constante.TAILLE_FENETRE)
    
    if android:
        android.init();
    
    serverIsKnown = False
   
    if android:
        android.vibrate(10)
        
    print "Labyrinth - android is set "+str(android)
    
    reponse = lancerServeur(fenetre)
    serverLaunch = (reponse == 'y')
    
    print "server launch: " + str(serverLaunch)
    
    if(serverLaunch):
        print "server = "+str(socket.gethostname())
        executerServeur()
        ip = socket.gethostbyname(socket.gethostname()) 
        ip2 = str(socket.gethostbyname_ex(socket.gethostname())[2])
        demandeUtilisateur(fenetre, "l'adresse du serveur est " + ip2 + " [y] ")
        serverIsKnown = True
    else:
        ip = demandeUtilisateur(fenetre, "rentrez adresse ip (puis entree)", answer="192.168.1.")
        serverIsKnown = True
    
    print "ip "+ip
    
    if(serverIsKnown ==  True):
        client = Client(ip, Constante.SERVER_PORT)
        nomJoueur = demandeUtilisateur(fenetre, "Nom du joueur (puis entree)")
        labyrinthC.start.start(client, nomJoueur, fenetre, ip)
    
    if(serverLaunch):
        demandeUtilisateur(fenetre, "Arret du serveur [entree]")
        reponse = client.arretServeur()
        print "arret du serveur reponse: "+ str(reponse)
     
    pygame.quit()


if __name__ == "__main__":
    main()
