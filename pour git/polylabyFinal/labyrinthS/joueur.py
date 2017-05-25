'''
classe representant un utilisateur
Un utilisateur est defini par:
  un nom, utile pour dire au serveur qui joue
  une position sur le plateau de jeu

'''
class Joueur:
    
    # Constructeur
    def __init__(self, nom, pos_joueur, numJoueur):
        self.nom = nom
        self.positionJoueur = pos_joueur
        self.numJoueur=numJoueur
        self.bombeRange=1
        self.vitesse=3
        self.nbBombeMax=1
        self.nbBombepose = 0
        self.vivant=True
    
    def modifierPosition(self, x, y):
        self.positionJoueur = (x, y)
        
    def recupererPosition(self):
        return self.positionJoueur
        
    def retournerNom(self):
        return self.nom
    
    def modifierNom(self, nom):
        self.nom = nom
