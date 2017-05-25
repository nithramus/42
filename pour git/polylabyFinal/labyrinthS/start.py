# -*- coding: utf-8 -*-

from traitementRequete import TraitementRequete
from serveur import Serveur
from common.constante import Constante
   
def lancerServeur():
    try:
        
        #creation du serveur
        # lien avec la classe instanciee pour chaque requete du client
        # - le client fait une requete http
        # - le serveur cree un objet de type TraitementRequete
        # - l'objet TraitementRequete execute sa fonction do_GET(self)
        # - l'objet TraitementRequete est detruit
      
        #creation du serveur
       
        serverMine = Serveur((Constante.SERVER_BASE, Constante.SERVER_PORT), TraitementRequete)
        
        
      
        #en attente des requetes du client
        #serverMine.serve_forever()
        
        
        while serverMine.mustStop != True:
            serverMine.handle_request()
        

    except KeyboardInterrupt:
        serverMine.server_close()
        print ('^C recu, arret du serveur')
