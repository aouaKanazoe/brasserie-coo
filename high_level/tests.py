from django.test import TestCase

# Create your tests here.
from .models import Machine
from .models import Departement
from .models import Ingredient
from .models import QuantiteIngredient
from .models import Prix
from .models import Usine

class MachineModelTests(TestCase):
    def test_usine_creation(self):
        self.assertEqual(Machine.objects.count(), 0)
        Machine.objects.create(nom="fermenteur", prix=1_000)
        self.assertEqual(Machine.objects.count(), 1)

class CostsModelTests(TestCase):
    def test_costs(self):

        fermenteur = Machine.objects.create(nom="fermenteur", prix=1_000)
        brasseur = Machine.objects.create(nom="brasseur", prix=2_000)

        departements= Departement.objects.create(numero=31, prix=2_000)


        houblon = Ingredient.objects.create(nom="houblon")

        orge = Ingredient.objects.create(nom="orge")

        quantiteHoublon = QuantiteIngredient.objects.create(ingredient=houblon,quantite=50)

        quantiteOrge = QuantiteIngredient.objects.create(ingredient=orge,quantite=100)

        Prix.objects.create(ingredient=houblon,departement=departements,prix=20)

        Prix.objects.create(ingredient=orge,departement=departements,prix=10)

        usine = Usine.objects.create(departement=departements, taille='50')
        usine.machines.add(fermenteur)
        usine.machines.add(brasseur)
        usine.stocks.add(quantiteHoublon)
        usine.stocks.add(quantiteOrge)

        result = usine.costs()
        self.assertEqual(result, 105000)
#------------------------------

# Créez un département
#departement = Departement.objects.create(numero=31, prix=2000)

# Créez une usine avec les caractéristiques du scénario de test
#usine = Usine.objects.create(departement=departement, taille='50', machines=2, recettes='...', stocks=50)

# Assurez-vous que les ingrédients nécessaires existent avec les bons prix
#Ingredient.objects.create(nom='houblon')
#Ingredient.objects.create(nom='orge')
#Prix.objects.create(ingredient=Ingredient.objects.get(nom='houblon'), departement=departement, prix=20)
#Prix.objects.create(ingredient=Ingredient.objects.get(nom='orge'), departement=departement, prix=10)

# Créez des machines avec les coûts spécifiés
#Machine.objects.create(nom='Machine1', prix=1000)
#Machine.objects.create(nom='Machine2', prix=2000)

# Appelez la méthode costs() et vérifiez le résultat
#result = usine.costs()
#print(result)  # Devrait afficher 105000€
