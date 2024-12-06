#include <print>

int main() {
    constexpr double FAHRENHEIT_FREEZING_POINT = 32.0f;
    constexpr double CELSIUS_FAHRENHEIT_TRANSLATION_FACTOR = 9.0f / 5.0f;

    // Déclaration de la variable pour la température en Celsius
    uint32_t temperatureCelsius = 25u;

    // Conversion de la température en Fahrenheit
    // double temperatureFahrenheit = static_cast<double>(temperatureCelsius) * 9.0f / 5.0f + 32.0f;
    double temperatureFahrenheit = static_cast<double>(temperatureCelsius) * CELSIUS_FAHRENHEIT_TRANSLATION_FACTOR + FAHRENHEIT_FREEZING_POINT;

    // Affichage du résultat
    std::println("Température en Celsius : {}°C", temperatureCelsius);
    std::println("Température en Fahrenheit : {:.2f}°F", temperatureFahrenheit);

    return 0;
}
