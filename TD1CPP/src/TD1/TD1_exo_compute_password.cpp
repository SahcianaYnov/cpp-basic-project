#include <print>
#include <string>
#include <sstream>
#include <random>

/// Calcule un char aléatoire dans la table ASCII entre ! et }
char compute_random_char() {
    // Il n'existe qu'une seule
    static constexpr int8_t min_char = '!';
    static constexpr int8_t max_char = '}';

    // Random generator
    static std::random_device rd;
    static std::mt19937 generator(rd());
    static std::uniform_int_distribution<> distribution(min_char, max_char);

    return distribution(generator);
}

std::string compute_password(int8_t pwdLength = 8) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < pwdLength; ++i) {
        ss << compute_random_char();
    }

    return ss.str();
}

int main() {
    // Générer un mot de passe avec la pwdLength par défaut
    std::println("Mot de passe généré (par défaut) : {}", compute_password());
    // Générer un mot de passe avec la pwdLength spécifiée
    std::println("Mot de passe généré (personnalisé 16 char) : {}", compute_password(16));

    return 0;
}
