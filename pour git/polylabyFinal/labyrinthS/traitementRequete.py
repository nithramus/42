#!/usr/bin/python
# -*- coding: utf-8 -*-


'''
Created on 3 Jul 2013

@author: pigeau-a
'''

from BaseHTTPServer import BaseHTTPRequestHandler
from urlparse import urlparse, parse_qs 
from joueur import Joueur
from bombe import Bombe
from explosion import Explosion
from common.constante import Constante
import time

#This class will handles any incoming request from
#the browser 
class TraitementRequete(BaseHTTPRequestHandler):
    
    def address_string(self):
        '''
        fonction à ajouter pour gérer le bug (temps de latence pour obtenir une réponse du serveur)
        '''
        host, port = self.client_address[:2]
        #return socket.getfqdn(host)
        return host
    
     #Handler for the GET requests
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        #Send the html message
        
        #print "serveur version "+self.server_version
        
        reponse = (Constante.SORTIE_OK, "le serveur fonctionne")
        error = False
        
        #parser la requete pour la diviser
        decoupageRequete = urlparse(self.path)
        
        #recuperer la requete
        nomFonction = decoupageRequete.path.rpartition('/')[2]
        
        #recuperer les parametres
        parametres = parse_qs(decoupageRequete.query)
        
        
        #print self.path
        #print "nom de la fonction: "+str(nomFonction)
        #print "parametres: "+str(parametres)
        if 'direction' in parametres:
            arg_direction = parametres.get('direction')
            print("arg_direction "+str(arg_direction))
            direction = arg_direction[0]
            print "direction "+str(direction)
            
        partie = self.server.partie
        for bombe in partie.listeBombe:
            newTime=time.time()
            if newTime-bombe.datePose>=2:
                explosion=Explosion(partie.explosionBombe(bombe))
                partie.listeExplosion.append(explosion)

        for explosion in partie.listeExplosion:
            newTime=time.time()
            if newTime-explosion.dateExplosion>=0.5:
                for positionExplosion in explosion.listePositionExplosion:
                    partie.map[positionExplosion[1]][positionExplosion[0]]=Constante.MAP_VIDE
                partie.listeExplosion.remove(explosion)

        if partie.etat==Constante.ETAT_PARTIE_COMMENCEE:
            nombreMorts=0
            for joueur in partie.joueurs:
                if not partie.joueurs[joueur].vivant:
                    if nombreMorts < 2:
                        nombreMorts += 2
                    else:
                        nombreMorts += 1
            if nombreMorts > len(partie.joueurs)-1:
                partie.etat=Constante.ETAT_PARTIE_FINIE

        
             
        """
        ####################################
        QUERY_DEPLACEMENT
        ####################################
        """
        if nomFonction == Constante.QUERY_DEPLACEMENT:        
            
            if Constante.ARG_DEPLACEMENT_DIRECTION in parametres:
                arg_direction = parametres[Constante.ARG_DEPLACEMENT_DIRECTION]
                direction = arg_direction[0]
            else:
                print(Constante.QUERY_DEPLACEMENT + " aucune direction")
                error = True
            
            if Constante.ARG_JOUEUR_NOM in parametres:
                arg_nom = parametres[Constante.ARG_JOUEUR_NOM]
                nomJoueur = arg_nom[0]
            else:
                print(Constante.QUERY_DEPLACEMENT + " aucun nom de joueur")
                error = True
            
            reponse = (Constante.SORTIE_ERROR, 0)
            
            if not error:
                print("requete deplacement - argument direction:", arg_direction[0])
                
                if partie.etat == Constante.ETAT_PARTIE_FINIE:
                    print(Constante.QUERY_DEPLACEMENT + " la partie est finie")
                    reponse = (Constante.SORTIE_PARTIE_PERDUE, 0)
                        
                if partie.etat == Constante.ETAT_PARTIE_COMMENCEE:
                    if nomJoueur in partie.joueurs:
                        joueur = partie.recupererJoueur(nomJoueur)
                        reponse = partie.deplacement(direction, joueur)
                        print(reponse)
                    else:
                        print(Constante.QUERY_DEPLACEMENT + " le joueur " + nomJoueur + " n'existe pas dans la partie ")
                
                
        """
        ####################################
        QUERY_INSCRIPTION_PARTIE
        ####################################
        """
        if nomFonction == Constante.QUERY_INSCRIPTION_PARTIE:        
                         
            if Constante.ARG_JOUEUR_NOM in parametres:
                arg_nom = parametres[Constante.ARG_JOUEUR_NOM]
                nomJoueur = arg_nom[0]
            else:
                error = True
                print(Constante.QUERY_INSCRIPTION_PARTIE + " aucun nom de joueur")
            
            reponse = (Constante.SORTIE_ERROR, 0)
            
            if not error:
                numJoueur=len(partie.joueurs)+1
                for i in range(partie.nbCasesX):
                    for j in range(partie.nbCasesY):
                        if partie.map[j][i]==str(numJoueur):
                            positionJoueur=(i,j)
                joueur = Joueur(nomJoueur, positionJoueur, len(partie.joueurs)+1)
                partie.joueur.append(nomJoueur)
                if not partie.estDejaAjouter(joueur):
                    partie.ajouterJoueur(joueur)
                    print(partie.joueurs)
                    reponse = (Constante.SORTIE_OK, 0)
                else:
                    print(Constante.QUERY_INSCRIPTION_PARTIE + " le joueur " + nomJoueur + " est deja present")
                    reponse = (Constante.SORTIE_NOT_OK, 0)       
                 

        """
        ####################################
        QUERY_ARRET_SERVEUR
        ####################################
        """
        if nomFonction == Constante.QUERY_ARRET_SERVEUR:
            self.server.mustStop = True
            reponse = (Constante.SORTIE_OK, 0)
        

        """
        ####################################
        QUERY_LANCER_PARTIE
        ####################################
        """
        if nomFonction == Constante.QUERY_LANCER_PARTIE:
            partie.etat = Constante.ETAT_PARTIE_COMMENCEE
            reponse = (Constante.SORTIE_OK, 0)
        
        """
        ####################################
        QUERY_RECUPERER_DEBUT_PARTIE
        ####################################
        """
        if nomFonction == Constante.QUERY_DEBUT_PARTIE:
            reponse = (Constante.SORTIE_OK, partie.etat)

        """
        ####################################
        QUERY_RECUPERER_ETAT
        ####################################
        """
        if nomFonction == Constante.QUERY_RECUPERER_ETAT:
            if Constante.ARG_JOUEUR_NOM in parametres:
                arg_nom = parametres[Constante.ARG_JOUEUR_NOM]
                nomJoueur = arg_nom[0]
            else:
                print(Constante.QUERY_DEPLACEMENT + " aucun nom de joueur")
                error = True
            reponse = (Constante.SORTIE_ERROR, 0)

            if not error:
                if partie.etat==Constante.ETAT_PARTIE_FINIE:
                    for nomJoueur in partie.joueurs:
                        if partie.joueurs[nomJoueur].vivant:
                            reponse = (Constante.SORTIE_PARTIE_GAGNE, partie.etat)
                        else :
                            reponse = (Constante.SORTIE_PARTIE_PERDUE, partie.etat)
                else :
                    reponse = (Constante.SORTIE_OK, partie.etat)
        
        """
        ####################################
        QUERY_RECUPERER_MAP
        ####################################
        """
        if nomFonction == Constante.QUERY_RECUPERER_MAP:
            reponse = (Constante.SORTIE_OK, partie.map)

        """
        ####################################
        QUERY_POSE_BOMBE
        ####################################
        """ 
        if nomFonction == Constante.QUERY_POSE_BOMBE:
            arg_nom = parametres[Constante.ARG_JOUEUR_NOM]
            for joueur in partie.joueurs:
                if joueur==arg_nom[0]:
                    numJoueur = partie.joueurs[joueur].numJoueur
                    if partie.nbBombepose[numJoueur-1]< partie.joueurs[joueur].nbBombeMax:
                        partie.nbBombepose[numJoueur-1]+=1
                        posJoueur=partie.joueurs[joueur].positionJoueur
                        rangeJoueur=partie.joueurs[joueur].bombeRange
                        bombe=Bombe(posJoueur,rangeJoueur,numJoueur)
                        partie.listeBombe.append(bombe)
                        partie.map[posJoueur[1]][posJoueur[0]]=Constante.MAP_BOMBE
                        reponse = (Constante.SORTIE_OK, 0)
                else:
                    reponse = (Constante.SORTIE_NOT_OK, 0)

        """
        ####################################
        QUERY_RECUPERER_LISTE_JOUEUR
        ####################################
        """ 
        if nomFonction == Constante.QUERY_RECUPERER_LISTE_JOUEUR:
            reponse = (Constante.SORTIE_OK, partie.joueur)
         
        """
        ####################################
        ####################################
        retour de la reponse - ne pas supprimer
        ####################################
        ###################################
        """
        self.wfile.write(unicode(reponse))    
        return
