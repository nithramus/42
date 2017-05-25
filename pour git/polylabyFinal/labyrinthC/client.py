# -*- coding: utf-8 -*-

'''
Created on 3 Jul 2013

@author: pigeau-a
'''


import urllib
import ast
from common.constante import Constante

class Client: 
    
    """
    constructeur du client pour appeler le serveur
    @param url: url du serveur (par exemple 'www.google.com')
    @param port: port du serveur (par exemple '8080')  
    """
    def __init__(self, url, port):
        self.url = url
        self.port = port
        self.base_address = 'http://'+url+':'+str(port)+'/'
    
    """
    methode pour une demande de placement du joueur
    @param direction: la direction demande par le joueur. Valeurs possibles 'N', 'E', 'S' ou 'W' pour 
    respectivement Nord, Est, Sud, West. Exemple d'appel : deplacement('N')
    @return: Constante.SORTIE_OK si le deplacement est accepte, Constante.SORTIE_NOT_OK si le deplacement n'est pas accepte,
    Constante.SORTIE_ERROR sinon
    """
    def deplacement(self, nomJoueur, direction):
        function = Constante.QUERY_DEPLACEMENT
        paramEtArg = [(Constante.ARG_DEPLACEMENT_DIRECTION, direction), (Constante.ARG_JOUEUR_NOM, nomJoueur)]
        response = self._query_generic(function, paramEtArg)
        return response

    def poseBombe(self, nomJoueur):
        function = Constante.QUERY_POSE_BOMBE
        paramEtArg = [(Constante.ARG_JOUEUR_NOM, nomJoueur)]
        response = self._query_generic(function, paramEtArg)
        
    
    """
    methode retournant la liste des murs
    @return:  [(x1,y1), (x2, y2), ... (xn,yn)] de type [(int, int), ...(int, int)] 
    """
    def listeJoueur(self):
        function = Constante.QUERY_RECUPERER_LISTE_JOUEUR
        paramEtArg = []
        # recupere un flot d'octets
        (statut, liste) = self._query_generic(function, paramEtArg)
        
        if(statut == Constante.SORTIE_OK):
            return liste
        else:
            print("getListeMurs: statut["+ statut + "]")
            return 1
        
    """
  
    """
    def lancerPartie(self):
        function = Constante.QUERY_LANCER_PARTIE
        paramEtArg = []
        # recupere un flot d'octets
        (statut, taille) = self._query_generic(function, paramEtArg)
        
        if(statut == Constante.SORTIE_OK):
            return taille
        else:
            print("getTailleFenetre: statut["+ statut + "]")
            return (0,0)
    

    
    def getMap(self):
        function = Constante.QUERY_RECUPERER_MAP
        paramEtArg = []
        (statut, map) = self._query_generic(function, paramEtArg)
        if (statut == Constante.SORTIE_OK):
            return map
        else:
            print("getRecupererMap: statut["+ statut + "]")
            return (0,0)

    def getEtat(self,nomJoueur):
        function = Constante.QUERY_RECUPERER_ETAT
        paramEtArg = [(Constante.ARG_JOUEUR_NOM, nomJoueur)]
        (statut, etat) = self._query_generic(function, paramEtArg)
        return (statut, etat)
    
    """
    
    """
    def debutPartie(self):
        function = Constante.QUERY_DEBUT_PARTIE
        paramEtArg = []
        # recupere un flot d'octets
        (statut, debut) = self._query_generic(function, paramEtArg)
       
        if (statut == Constante.SORTIE_OK):
            return debut 
        else:
            print("getTailleCase: statut["+ statut + "]")
            return (0,0)
    
    """
    methode pour s'inscrire
    @return: Constante.SORTIE_OK pour dire que l'ajout est fait, Constante.SORTIE_NOT_OK sinon
    """
    def inscriptionPartie(self, nomJoueur):
        function = Constante.QUERY_INSCRIPTION_PARTIE
        paramEtArg = [(Constante.ARG_JOUEUR_NOM, nomJoueur)]
        # recupere un flot d'octets
        (statut, reponse) = self._query_generic(function, paramEtArg)
        return (statut, reponse) 
    
    """
    methode demandant au serveur de s'arreter
    @return: rien 
    """
    def arretServeur(self):
        function = Constante.QUERY_ARRET_SERVEUR
        paramEtArg = []
        # recupere un flot d'octets
        (statut, reponse) = self._query_generic(function, paramEtArg)
        return statut
    
    """
    Methode generique pour faire une requete http. Le client ne l'appelle pas directement.
    Par exemple function="deplacement" et paramEtArg=('direction', 'N') entraine la requete suivante:
    "http://www.google.com/deplacement?direction=N"
    @param function: la fonction appelee en http 
    @param paramEtArg: liste de (parametre, argument)
    @return le resultat de la requete realisee
    """
    def _query_generic(self, function, paramEtArg):
        nbrParam = 0;
        q = ""
        for (param, arg) in paramEtArg:
            q = q + param+'='+arg
            if nbrParam != len(paramEtArg)-1:
                nbrParam = nbrParam+1
                q = q + "&"
        
        
        f = urllib.urlopen(self.base_address+function+'?'+q)
        
        #print("result of the query:"+f.read())
        
        # la reponse est un flot d'octets
        return ast.literal_eval(f.read())
