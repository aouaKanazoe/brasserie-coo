from django.db import models
from json import dumps
# Create your models here.
class Departement(models.Model):
    numero = models.IntegerField()
    prix = models.IntegerField()

    def __str__(self):
        return f"Departement{self.numero}"
    def json(self):
        return {"numero":self.numero,"prix":self.prix}

class Machine(models.Model):
    nom = models.CharField(max_length=200)
    prix =models.IntegerField()

    def __str__(self):
        return self.nom
    def costs(self):
        return self.prix
    def json(self):
        return {"nom":self.nom,"prix":self.prix}

class Ingredient(models.Model):
    nom = models.CharField(max_length=200)

    def __str__(self):
     return self.nom

    def json(self):
         return {"nom":self.nom}

class QuantiteIngredient(models.Model):
    ingredient = models.ForeignKey(Ingredient, on_delete=models.CASCADE)
    quantite = models.IntegerField()

    def __str__(self):
        return f"{self.quantite} {self.ingredient.nom}"

    def costs(self,departement):#Cette methode calcul le cout de la quantite d'ingredient en fonction du departement
        return self.ingredient.prix_set.get(departement__numero=departement).prix*self.quantite  # cout = prix de l'ingredient dans le departement donné * par la quantite d'ingredient
    def json(self):
        return {"ingredient":self.ingredient,"quantite":self.quantite}

class Action(models.Model):
    machine = models.ForeignKey(Machine, on_delete=models.CASCADE)
    commande = models.CharField(max_length=200)
    duree = models.IntegerField()
    ingredient = models.ManyToManyField(QuantiteIngredient)
    action_parent = models.ForeignKey("self", on_delete=models.CASCADE, blank=True, null=True, related_name="actions_children")

    def __str__(self):
        return f"Action {self.commande} sur la machine {self.machine.nom}"
    def json(self):
        return {"machine":self.machine,"commande":self.commande,"duree":self.duree,"ingredient":self.ingredient,"action_parent":self.action_parent}

class Recette(models.Model):
    nom = models.CharField(max_length=200)
    action = models.ForeignKey(Action, on_delete=models.CASCADE)

    def __str__(self):
        return self.nom
    def json(self):
        return {"nom":self.nom,"action":self.action}

class Usine(models.Model):
    departement = models.ForeignKey(Departement, on_delete=models.CASCADE)
    taille = models.CharField(max_length=200)
    machines = models.ManyToManyField(Machine)
    recettes = models.ManyToManyField(Recette)
    stocks = models.ManyToManyField(QuantiteIngredient)

    def __str__(self):
        return f"Usine dans le département{self.departement.numero}"
    def costs(self):#Cette methode calcul le cout d'une usine
        total =0
        for machine in self.machines.all():
            total+=machine.costs()
        for stock in self.stocks.all():
            total+=stock.costs(self.departement.numero)
        return int(self.taille)*self.departement.prix+total  #
    def json(self):
        return {"departement":self.departement,"taille":self.taille,"machines":self.machines,"recettes":self.recettes,"stocks":self.stocks}

class Prix(models.Model):
    ingredient = models.ForeignKey(Ingredient, on_delete=models.CASCADE)
    departement = models.ForeignKey(Departement, on_delete=models.CASCADE,related_name="+")
    prix = models.IntegerField()

    def __str__(self):
        return f"Prix pour les ingrédients {self.ingredient} dans le département {self.departement.numero}"
    def json(self):
        return {"ingredient":self.ingredient,"departement":self.departement,"prix":self.prix}
