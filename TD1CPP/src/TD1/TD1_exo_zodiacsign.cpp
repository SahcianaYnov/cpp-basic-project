#include <print>
#include <string>
#include <stdexcept>

enum class ZodiacSign : uint8_t {
    Capricorn = 1, // January
    Aquarius = 2,  // February
    Pisces = 3,    // March
    Aries = 4,     // April
    Taurus = 5,    // May
    Gemini = 6,    // June
    Cancer = 7,    // July
    Leo = 8,       // August
    Virgo = 9,     // September
    Libra = 10,     // October
    Scorpio = 11,   // November
    Sagittarius = 12 // December
};

int main(int argc, char* argv[])
{
    uint8_t birthMonth = 1u;

    try {
        if (argc != 2)
            throw std::invalid_argument("");

        birthMonth = std::stoi(argv[1]);
        if (birthMonth < static_cast<uint8_t>(ZodiacSign::Capricorn)
            || birthMonth > static_cast<uint8_t>(ZodiacSign::Sagittarius))
            throw std::invalid_argument("");
    } catch (...) {
        std::println("Usage : Veuillez fournir un numéro pour votre mois de naissance en paramètre.");
        return 1;
    }

    // Map the birth month to the zodiac sign
    ZodiacSign sign = static_cast<ZodiacSign>(birthMonth);

    // Use a switch statement to print the prediction
    switch (sign) {
        case ZodiacSign::Capricorn:
            std::println("Une opportunité inattendue se présentera à vous aujourd'hui."); break;
        case ZodiacSign::Aquarius:
            std::println("Un ami vous apportera de bonnes nouvelles."); break;
        case ZodiacSign::Pisces:
            std::println("Une surprise vous attend au détour du chemin."); break;
        case ZodiacSign::Aries:
            std::println("Votre énergie sera contagieuse aujourd'hui."); break;
        case ZodiacSign::Taurus:
            std::println("Vous trouverez enfin la chaussette perdue depuis longtemps !"); break;
        case ZodiacSign::Gemini:
            std::println("Un moment de réflexion vous apportera une idée brillante."); break;
        case ZodiacSign::Cancer:
            std::println("Le hasard fera bien les choses pour vous aujourd'hui."); break;
        case ZodiacSign::Leo:
            std::println("Votre charisme ne passera pas inaperçu."); break;
        case ZodiacSign::Virgo:
            std::println("Une tâche que vous redoutiez sera accomplie sans effort."); break;
        case ZodiacSign::Libra:
            std::println("L'équilibre sera le maître-mot de votre journée."); break;
        case ZodiacSign::Scorpio:
            std::println("Un mystère sera résolu grâce à votre perspicacité."); break;
        case ZodiacSign::Sagittarius:
            std::println("Une aventure excitante vous attend."); break;
    }

    return 0;
}
