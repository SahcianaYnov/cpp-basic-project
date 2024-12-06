#include <print>
#include <string>

int main() {
    // Enum for air quality categories
    enum AirQualityCategory {
        Good = 0,
        Moderate = 1,
        Poor = 2,
        Hazardous = 3
    };

    // Table for air quality descriptions
    constexpr std::string_view airQualityDescriptions[4] = {
        "Bon",
        "Modéré",
        "Mauvais",
        "Dangereux"
    };

    double airQualityIndex = 310.0452f;

    constexpr float THRESHOLD_HAZARDOUS = 300.0f;

    // Determine the air quality category
    AirQualityCategory category = AirQualityCategory::Good;
    if (airQualityIndex > THRESHOLD_HAZARDOUS) {
        category = AirQualityCategory::Hazardous;
    } else if (airQualityIndex > 100.0) {
        category = AirQualityCategory::Poor;
    } else if (airQualityIndex > 50.0) {
        category = AirQualityCategory::Moderate;
    }

    std::println("Catégorie de qualité de l'air : {}", airQualityDescriptions[category]);

    return 0;
}
