#include "Interface.h"
#include <iostream>

#define MAX_BUFFER_LENGTH 15

Interface::Interface()
    : decimal {0.0}, binary_ptr{std::make_shared<std::string>()}, hexadecimal_ptr {std::make_shared<std::string>()} {
}

void Interface::menu() {
    std::cout << "DEC BIN HEX ==== CONVERTER" << std::endl << std::endl;
    std::cout << "From?" << std::endl;
    std::cout << "1. Decimal" << std::endl;
    std::cout << "2. Binary" << std::endl;
    std::cout << "3. Hexadecimal" << std::endl;
    while(true) {
        int user_input = get_input(1, 3);
        std::cout << std::endl;
        std::cout << "ENTER VALUE: ";
        switch (user_input)
        {
        case 1: {
            const double decimal = get_input(0, 10000);
            Interface::set_decimal(decimal);
            break;
        } case 2: {
            std::shared_ptr<std::string> binary_ptr = get_str_input();
            Interface::set_binary_ptr(binary_ptr);
            break;
        } case 3: {
            std::shared_ptr<std::string> hexadecimal_ptr = get_str_input();
            Interface::set_hexadecimal_ptr(hexadecimal_ptr);
            break;
        } default:
            std::cout << "NOT VALID INPUT" << std::endl;
            break;
        }
        break;
    }
    std::cout << std::endl;
    std::cout << "To?" << std::endl;
    std::cout << "1. Decimal" << std::endl;
    std::cout << "2. Binary" << std::endl;
    std::cout << "3. Hexadecimal" << std::endl;
    int user_input = get_input(1, 3);
    switch (user_input)
    {
    case 1:
        if(get_binary_ptr() != "") {
           std::cout << Converter::convert_binary_to_decimal(get_binary_ptr()) << std::endl;
        } else if(get_hexadecimal_ptr() != "") {
            std::cout << Converter::convert_hexadecimal_to_decimal(get_hexadecimal_ptr()) << std::endl;
        } else if (get_decimal() != 0.0) {
            std::cout << get_decimal() << std::endl;
        }
        break;
    case 2:
        if(get_decimal() != 0.0) {
            std::cout << Converter::convert_decimal_to_binary(get_decimal()) << std::endl;
        } else if(get_binary_ptr() != "") {
            std::cout << get_binary_ptr() << std::endl;
        } else if(get_hexadecimal_ptr() != "") {
            std::cout << Converter::convert_hexadecimal_to_binary(get_hexadecimal_ptr()) << std::endl;
        }
        break;
    case 3:
        if(get_hexadecimal_ptr() != "") {
            std::cout << get_hexadecimal_ptr() << std::endl;
        } else if(get_binary_ptr() != "") {
            std::cout << Converter::convert_binary_to_hexadecimal(get_binary_ptr()) << std::endl;
        } else if(get_decimal() != 0.0) {
            std::cout << Converter::convert_decimal_to_hexadecimal(get_decimal()) << std::endl;
        }
        break;
    
    default:
        std::cout << "ERROR IN CONVERSION" <<std::endl;
        break;
    }
}

int Interface::get_input(const int min, const int max) {
    int input;
    while(true) {
        char buffer[MAX_BUFFER_LENGTH+1];
        fgets(buffer, MAX_BUFFER_LENGTH, stdin);
        if(sscanf(buffer, "%d", &input) != 1) {
            continue;
        }
        if(input < min || input > max) {
            std::cout << "INVALID INPUT" << std::endl;
            continue;
        }
        break;
    }
    return input;
}

std::shared_ptr<std::string> Interface::get_str_input() {
    std::string buffer;
    std::cin >> buffer;
    std::shared_ptr<std::string> str_pointer = std::make_shared<std::string>(buffer);
    return str_pointer;
}