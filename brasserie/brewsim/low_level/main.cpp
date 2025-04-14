#include <iostream>
#include <string>
#include <memory>
#include <cpr/cpr.h>

class Departement {
    int numero;
    int prix;
    int id;

public:
    Departement(int numero, int prix) : numero(numero), prix(prix) {}

    Departement(std::string numero_str, std::string prix_str, int id)
        : numero(std::stoi(numero_str)), prix(std::stoi(prix_str)), id(id) {}

    void afficher() const {
        std::cout << "Département " << numero << " Prix : " << prix << std::endl;
    }

    void afficherR() const {
        std::cout << "Département " << numero << " Prix : " << prix << " ID : " << id << std::endl;
    }

    void Requete(int id = 1) const {
        std::string url = "http://localhost:8000/departement/" + std::to_string(id);
        auto reponse = cpr::Get(cpr::Url{url});

        std::cout << "\nHTTP " << reponse.status_code << "\n" << reponse.text << "\n";

        if (reponse.status_code == 200) {
            // parsing simple
            std::string text = reponse.text;
            std::size_t pos_num = text.find("\"numero\":");
            std::size_t pos_prix = text.find("\"prix\":");

            if (pos_num != std::string::npos && pos_prix != std::string::npos) {
                std::string numero = text.substr(pos_num + 9, text.find(",", pos_num) - pos_num - 9);
                std::string prix = text.substr(pos_prix + 7, text.find("}", pos_prix) - pos_prix - 7);

                Departement d(numero, prix, id);
                d.afficherR();
            } else {
                std::cerr << "Réponse JSON invalide\n";
            }
        } else {
            std::cerr << "Erreur HTTP\n";
        }
    }
};

class Ingredient {
public:
    std::string nom;

    Ingredient(std::string nom) : nom(nom) {}

    void afficherIngredient() const {
        std::cout << "Nom de l'ingrédient : " << nom << std::endl;
    }
};

class Machine {
public:
    std::string nom;
    int prix;

    Machine(std::string nom, int prix) : nom(nom), prix(prix) {}

    void afficherMachine() const {
        std::cout << "Nom de la machine : " << nom << " — Prix : " << prix << std::endl;
    }
};

class QuantiteIngredient {
public:
    std::unique_ptr<Ingredient> ingredient;
    int quantite;

    QuantiteIngredient(std::unique_ptr<Ingredient> ingr, int quantite)
        : ingredient(std::move(ingr)), quantite(quantite) {}

    void afficherQuantiteIngredient() const {
        std::cout << "Quantité : " << quantite << " de ";
        if (ingredient) {
            ingredient->afficherIngredient();
        }
    }
};

int main() {
    int id = 1;

    Departement departement1(1, 1000);
    departement1.afficher();

    // Tester la requête HTTP
    departement1.Requete(id);

    // Autres entités
    Ingredient ingredient1("Orge");
    ingredient1.afficherIngredient();

    Machine machine1("Fermenteur", 1500);
    machine1.afficherMachine();

    auto ingr = std::make_unique<Ingredient>("Houblon");
    QuantiteIngredient qi(std::move(ingr), 100);
    qi.afficherQuantiteIngredient();

    return 0;
}
