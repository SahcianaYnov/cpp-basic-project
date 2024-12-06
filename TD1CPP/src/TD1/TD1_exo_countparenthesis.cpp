#include <print>
#include <string>
#include <string_view>
#include <optional>

std::optional<uint32_t> count_parenthesis(std::string_view text, int32_t nbParenthesisOpened = 0) {
    if (bool tooManyClosedParenthesis = (nbParenthesisOpened < 0))
        return std::nullopt;      

    if (text.empty())
        return 0u;

    char nextChar = text.front();
    
    bool openedParenthesis = (nextChar == '(');
    if (openedParenthesis) ++nbParenthesisOpened;
    
    bool closedParenthesis = (nextChar == ')');
    if (closedParenthesis) --nbParenthesisOpened;
        
    auto remainingCount = count_parenthesis(text.substr(1), nbParenthesisOpened);
    if (!remainingCount.has_value())
        return std::nullopt;
    else
        return closedParenthesis + remainingCount.value();
}

int main() {
    // Vérification des parenthèses
    auto nbParenthesis = count_parenthesis("(c(ls(l)))");

    if (nbParenthesis.has_value()) {
        std::println("Le texte contient {} parenthèses.", nbParenthesis.value());
    } else {
        std::println("Les parenthèses ne sont pas valides.");
    }

    auto nbParenthesis2 = count_parenthesis("(cls(l)))");
    if (nbParenthesis2.has_value()) {
        std::println("Le texte contient {} parenthèses.", nbParenthesis.value());
    } else {
        std::println("Les parenthèses ne sont pas valides.");
    }

    return 0;
}
