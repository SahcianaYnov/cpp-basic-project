#include <print>
#include <string>
#include <stdexcept>
#include <expected>

std::expected<double, std::string> parse_decimal(const std::string& input) {
    try {
        size_t pos;
        double value = std::stod(input, &pos);
        
        // Ensure the entire string was parsed
        if (pos != input.size())
            return std::unexpected("Error: Input contains extra characters after the number");

        return static_cast<float>(value);
    } catch (const std::invalid_argument&) {
        return std::unexpected("Error: Invalid input. Not a valid floating-point number");
    } catch (const std::out_of_range&) {
        return std::unexpected("Error: Input is out of range for a floating-point number");
    }
}

// Main function demonstrating the use of parse_decimal
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::println("Usage: {} <float_value>", argv[0]);
        return 1;
    }

    auto paramNumber = parse_decimal(argv[1]);
    if (paramNumber.has_value()) {
        std::println("Received parameter : {:.2f}", paramNumber.value());
    } else {
        std::println("{}", paramNumber.error());
        return 1;
    }

    return 0;
}
