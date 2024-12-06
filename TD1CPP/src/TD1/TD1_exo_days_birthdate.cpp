#include <print>

int main() {
    constexpr uint16_t DAYS_PER_YEAR = 365u;
    constexpr uint16_t DAYS_PER_MONTH = 30u;

    // Saisie de la date de naissance
    uint16_t birthDay = 18u, birthMonth = 11u, birthYear = 1988u;

    // Saisie de la date actuelle
    uint16_t currentDay = 5u, currentMonth = 12u, currentYear = 2024u;

    // Calcul du temps écoulé en jours
    uint32_t totalDaysElapsed = (currentYear - birthYear) * DAYS_PER_YEAR + 
                           (currentMonth - birthMonth) * DAYS_PER_MONTH + 
                           (currentDay - birthDay);

    // Conversion en années, mois, et jours
    uint16_t elapsedYears = totalDaysElapsed / DAYS_PER_YEAR;
    uint16_t remainingDays = totalDaysElapsed % DAYS_PER_YEAR;
    uint16_t elapsedMonths = remainingDays / DAYS_PER_MONTH;
    uint16_t elapsedDays = remainingDays % DAYS_PER_MONTH;

    // Affichage des résultats
    std::println("Depuis votre naissance, il s'est écoulé :");
    std::println("{} années, {} mois et {} jours.", elapsedYears, elapsedMonths, elapsedDays);

    return 0;
}
