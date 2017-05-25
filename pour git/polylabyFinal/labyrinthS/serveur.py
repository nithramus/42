# -*- coding: utf-8 -*-

# inclusion de bibliotheque
from BaseHTTPServer import HTTPServer
from partie import Partie

"""
Cette classe permet de lancer un serveur qui va gerer une partie.
Le serveur contient la partie en attribut. La partie est donc creee quand le serveur
est cree.
"""
class Serveur(HTTPServer):
    "the HTTP server"
   
    def __init__(self, adresseServeur, traiteRequete):
        HTTPServer.__init__(self, adresseServeur, traiteRequete)
        self.partie = Partie()
        self.mustStop = False
    