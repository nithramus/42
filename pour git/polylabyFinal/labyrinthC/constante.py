# -*- coding: utf-8 -*-

class Constante:
    
    SERVER_BASE = ''
    SERVER_PORT = 8080
    
    TAILLE_FENETRE = (800, 480)
    TAILLE_CASE = 80
    
    QUERY_RECUPERER_TAILLE_PLATEAU = "recupererTaillePlateau"
    QUERY_RECUPERER_TAILLE_CASE = "recupererTailleCase"
    QUERY_RECUPERER_POSITION_BUT = "recupererPositionBut"
    QUERY_RECUPERER_NOMBRE_CASE_MAX = "recupererNombreCaseMax"
    QUERY_RECUPERER_LISTE_MURS = "recupererListeMurs"
    QUERY_RECUPERER_MAP = "recupererMap"
    QUERY_RECUPERER_LISTE_JOUEUR = "recupererListeJoueur"
    QUERY_ARRET_SERVEUR = "arretServeur"

    QUERY_PARTIE_CREER = "partieCreer"
    QUERY_PARTIE_CHANGER_ETAT = "partieChangerEtat"
    ARG_PARTIE_NOM = "nomPartie"
    ARG_PARTIE_ETAT = "etat"

    QUERY_INSCRIPTION_PARTIE = "inscriptionPartie"
    ARG_JOUEUR_NOM = "nomJoueur"
    
    QUERY_DEPLACEMENT = "deplacement"
    QUERY_POSE_BOMBE = "poseBombe"
    ARG_DEPLACEMENT_DIRECTION = "direction"
    
    SORTIE_OK = "O"
    SORTIE_NOT_OK = "N"
    SORTIE_ERROR = "E"
    SORTIE_PARTIE_PERDUE = "L"
    SORTIE_PARTIE_GAGNE = "Y"
    
    ETAT_INSCRIPTION_OUVERTE = 0
    ETAT_INSCRIPTION_FERMEE = 1
    ETAT_PARTIE_COMMENCEE = 2
    ETAT_PARTIE_FINIE = 3 
    
    MAP_VIDE = "0"
    MAP_MUR = "Y"
    MAP_BLOC = "C"
    MAP_BOMBE = "B"
    MAP_EXPLOSION = "E"
    MAP_BONUS = "O"
    MAP_J1 = "1"
    MAP_J2 = "2"
    MAP_J3 = "3"
    MAP_J4 = "4"
