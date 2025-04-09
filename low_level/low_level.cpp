#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <string>
#include <vector>
#include <memory>
#include <optional>


using namespace std;

class Departement {
    int numero;
    int prix;
    int id;
  public:

  // le constructeur 1
	Departement(int numero, int prix): numero(numero), prix(prix) {}


  nlohmann::json json_response = nlohmann::json::parse(reponse.text);

	// le constructeur prenant un objet JSON et un ID
  Departement(const nlohmann::json& json_data, int id) : numero(json_data["numero"]), prix(json_data["prix"]), id(id) {}

  // creation d'un  constructeur int id
  Departement (int id)
  {
    std::string url= "http://localhost:8000/departement/1";
    auto reponse = cpr::Get(cpr::Url{url});

    // Affichage
    std::cout << r.url << std::endl;
    std::cout << r.status_code << std::endl;
    std::cout << r.header["content-type"] << std::endl;

    // Parser le texte json

    std::cout << r.text << std::endl;

    try {
        json_data = json::parse(r.text);
        _numero = data["numero"];
        _prix = data["prix"];

        afficher(std::cout);
        std::cout << std::endl;
    }
    catch (const json::parse_error & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    json j = json::parse(r.text,nullptr,false);

    if(j.is_discarded())
    {
     std::cout << "the input is invalid JSON" << std:endl;
    }
    else
    {
      std::cout << "the input is invalid JSON" << j << std:endl;
    }

}



	auto afficher() const {

        std::cout << "Département \n" << numero << " Prix : " << prix << std::endl;

	}

	auto afficherR() const {
		std::cout << "Département " << numero << " Prix : " << prix << " ID : " << id << std::endl;
	}
	auto Requete() const {

		//std::string url = "http://localhost:8000/departement/1";
		std::string url= "http://localhost:8000/departement/1";

		auto reponse = cpr::Get(cpr::Url{url});
		std::cout << "Code de réponse HTTP : " << reponse.status_code << std::endl;
		std::cout << "Contenu de la réponse : " << reponse.text << std::endl;


		 // Vérifiez si la requête a réussi (status code 200)
		if(reponse.status_code == 200) {
		    // Essayez de parser le texte JSON
		 try {
		        // Utilisez nlohmann/json pour analyser le texte JSON
		        nlohmann::json json_response = nlohmann::json::parse(reponse.text);

		        // Créez une nouvelle instance de la classe Département à partir de la réponse JSON et de l'ID
		        Departement departement_from_json(json_response, id);

		        // Affichez les informations de la nouvelle instance
		        departement_from_json.afficherR();
		    }
		    catch (const nlohmann::json::exception& e)
		    {
		        std::cerr << "Erreur de parsing JSON : " << e.what() << std::endl;
		    }
		}
		else
		{
		    std::cerr << "Erreur HTTP : " << reponse.status_code << std::endl;
		}
	    }    try {
		        // Utilisez nlohmann/json pour analyser le texte JSON
		        nlohmann::json json_response = nlohmann::json::parse(reponse.text);

		        // Créez une nouvelle instance de la classe Département à partir de la réponse JSON et de l'ID
		        Departement departement_from_json(json_response, id);

		        // Affichez les informations de la nouvelle instance
		        departement_from_json.afficherR();
		    }
		    catch (const nlohmann::json::exception& e)
		    {
		        std::cerr << "Erreur de parsing JSON : " << e.what() << std::endl;
		    }
		}
		else
		{
		    std::cerr << "Erreur HTTP : " << reponse.status_code << std::endl;
		}
	    }
};

class Ingredient {
public:
    std::string nom;

    Ingredient(string nom): nom(nom) {}

    void afficherIngredient() const {
        std::cout << "Nom de l'ingrédient : " << nom << std::endl;
    }
};

class Machine {
public:
    std::string nom;
    int prix;

    Machine(string nom, int prix): nom(nom), prix(prix) {}

    void afficherMachine() const {
        std::cout << "Nom \n" << nom << " Prix : " << prix << std::endl;
    }
};


class QuantiteIngredient {
public:
    std::unique_ptr<Ingredient> ingredient;
    int quantite;

    QuantiteIngredient(unique_ptr<Ingredient> ingredient , int quantite) {}

    //QuantiteIngredient() {};

    void afficherQuantiteIngredient() const {
        std::cout << "Ingredient \n" << ingredient << " quantite : " << quantite << std::endl;

    }

    // Fonction d'affichage
    /*void afficherIngredient() const {
        std::cout << "QuantiteIngredient - Quantite: " << quantite << std::endl;
        if (ingredient) {
            std::cout << "Ingrédient associé: ";
            ingredient->afficherIngredient();
        } else {
            std::cout << "Aucun ingrédient associé." << std::endl;
        }
    }*/
};

/*class Action {
public:
    std::optional<std::unique_ptr<Machine>> machine;
    char commande;Departement departement_from_json(json_data, QuantiteIngredientid);

    int duree;
    std::optional<std::unique_ptr<Ingredient>> ingredient;
    std::optional<Action> parent;
};

class Recette {
public:
    char nom;
    Action action;
};

class Usine {
public:
    std::unique_ptr<Departement> departement;
    char taille;
    std::vector<std::unique_ptr<Machine>> machines;
    std::vector<Recette> recettes;
    // Utilisez std::optional pour les attributs QuantiteIngredientnon requis
    std::optional<std::vector<std::unique_ptr<Prix>>> stocks;
};

class Prix {
public:
    std::unique_ptr<Ingredient> ingredient;
    std::unique_ptr<Departement> departement;
    int prix;
};
*/

int main(){

	int id = 50;Departement departement_from_json(json_data, QuantiteIngredientid);


    // Création d'une instance de la classe Département avec le constructeur 1
    Departement departement1(1, 1000); // departement numéro 1 avec un prix de 1000
    Ingredient ingredient1("orge");
    Machine machine1 ("fermenteur",1000);
Departement departement_from_json(json_data, QuantiteIngredientid);

    QuantiteIngredient quantiteIngredient1 ("orge" , 100);

    /*QuantiteIngredient qIngredient;
    qIngredient.quantite = 100;
    std::unique_ptr<Ingredient> ingr = std::make_unique<Ingredient>();
    ingr->nom = "orge";
    qIngredient.ingredient = std::move(ingr);*/



    // Affichage de l'instance
    departement1.afficher();

    // Effectuer une requête HTTP
    departement1.Requete();

    // Création d'une instance de la classe Département avec le constructeur prenant un paramètre json data et un id

    nlohmann::json json_data = {{"numero", 2}, {"prix", 2000}};

    Departement departement_from_json(json_data, id);

  //  Departement departement_from_json(json_data, QuantiteIngredient);

    // Affichage de l'instance créée à partir de JSON
    departement_from_json.afficherR();

    ingredient1.afficherIngredient();

    machine1.afficherMachine();

    quantiteIngredient1.afficherIngredient();


    /////////////////

    //qIngredient.afficherIngredient();


    return 0;}
