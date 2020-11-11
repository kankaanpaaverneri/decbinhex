#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <memory>
#include <string>
#include <cmath>
#include <vector>

class Converter {
    private:
	//CONST ATTRIBUTES
        static constexpr int divider_to_binary = 2;
        static constexpr int divider_to_hexadecimal = 16;
    public:
	//CONSTRUCTOR AND DESTRUCTOR
        Converter() = default;
        ~Converter() = default;

	//FUNCTIONS
        std::string convert_decimal_to_binary(double decimal);
        const int convert_binary_to_decimal(std::string binary);
        std::string convert_decimal_to_hexadecimal(double decimal);
        const int convert_hexadecimal_to_decimal(std::string hexadecimal);
        std::string convert_hexadecimal_to_binary(std::string hexadecimal);
        std::string convert_binary_to_hexadecimal(std::string binary);
        const char convert_number_to_letter(const int number);
        int convert_letter_to_number(const char letter);
        std::string reverse_str(std::string str);
        std::string push_begining(std::string str, const int amount_to_add);
};
#endif
