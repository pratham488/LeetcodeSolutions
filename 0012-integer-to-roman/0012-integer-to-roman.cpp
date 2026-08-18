#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Define values and symbols in descending order, including subtractive cases
        std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        
        // Iterate through the pairs
        for (const auto& [value, symbol] : roman) {
            // Append the symbol while the number is greater than or equal to the value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};