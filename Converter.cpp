#include "Converter.h"


std::string Converter::convert_decimal_to_binary(double decimal) {
    std::string binary_value;
    while(decimal > 0) {
        if(static_cast<int>(decimal) % divider_to_binary == 0)
            binary_value += '0';
        else
            binary_value += '1';
        decimal = static_cast<int>(decimal) / divider_to_binary;
    }
    binary_value = Converter::reverse_str(binary_value);
    return binary_value;
}

const int Converter::convert_binary_to_decimal(std::string binary) {
    int decimal_value {0};
    int exponent {0}, i {0};
    for(i = binary.size()-1; i >= 0; i--) {
        int potency = pow(divider_to_binary, exponent);
        if(binary.at(i) == '1') {
            decimal_value += potency;
        }
        exponent++;
    }
    return decimal_value;
}

std::string Converter::convert_decimal_to_hexadecimal(double decimal) {
    std::string hexadecimal_value;
    while(decimal > 0) {
        decimal = decimal / divider_to_hexadecimal;
        int temp_value = static_cast<char>(divider_to_hexadecimal * (decimal - static_cast<int>(decimal)));
        if(temp_value > 9) {
            hexadecimal_value += convert_number_to_letter(temp_value);
        } else
            hexadecimal_value += static_cast<char>(temp_value)+48;
        decimal = decimal - (decimal - static_cast<int>(decimal));
    }
    if(hexadecimal_value.size() > 1)
        hexadecimal_value = reverse_str(hexadecimal_value);
    return hexadecimal_value;
}

const int Converter::convert_hexadecimal_to_decimal(std::string hexadecimal) {
    int decimal_value {0};
    int exponent {0};
    for(int i = hexadecimal.size()-1; i >= 0; i--) {
        int potency = pow(divider_to_hexadecimal, exponent);
        decimal_value += potency * Converter::convert_letter_to_number(hexadecimal.at(i));
        exponent++;
    }
    return decimal_value;
}

std::string Converter::convert_hexadecimal_to_binary(std::string hexadecimal) {
    //FIRST WE CONVERT LETTERS TO NUMBERS
    std::vector<int> hex_int;
    for(unsigned int i {0}; i < hexadecimal.size(); i++) {
        int number {0};
        if(hexadecimal.at(i) >= 65 && hexadecimal.at(i) <= 70) {
            number = Converter::convert_letter_to_number(hexadecimal.at(i));
        } else {
            number = static_cast<int>(hexadecimal.at(i)) - 48;
        }
        hex_int.push_back(number);
    }

    //WE GENERATE BINARY
    std::string binary;
    const std::vector<int> potency_results {8, 4, 2, 1};

    for(unsigned int i {0}; i < hex_int.size(); i++) {
        std::string temp_binary {"0000"};
        int sum {0};

        if(hex_int.at(i) == 0) {
            binary += temp_binary;
            break;
        }

        //DEFINING WHERE WE TAKE THE REMAINDER
        unsigned int j {0};
        for(; hex_int.at(i) < potency_results.at(j); j++);

        temp_binary.at(j) = '1';
        sum = potency_results.at(j);

        //TAKE THE REMAINDER
        int remainder = hex_int.at(i) % potency_results.at(j);
        if(remainder != 0) {
            for(; potency_results.at(j) > remainder; j++);
            while(j < potency_results.size()) {
                temp_binary.at(j) = '1';
                sum += potency_results.at(j);
                if(sum == hex_int.at(i))
                    break;
                else if(sum > hex_int.at(i)) {
                    temp_binary.at(j) = '0';
                    sum -= potency_results.at(j);
                }
                j++;
            }
        }
        binary += temp_binary;
    }
    
    return binary;
}

std::string Converter::convert_binary_to_hexadecimal(std::string binary) {
    std::string hexadecimal_value;
    std::string temp;

    int amount_of_zeros = 4 - (binary.size() % 4);
    if(amount_of_zeros != 4) {
        binary = Converter::reverse_str(binary);
        while(amount_of_zeros > 0) {
            binary.push_back('0');
            amount_of_zeros--;
        }
        binary = Converter::reverse_str(binary);
    }
    int i = binary.size()-1;

    while(i >= 0) {
        temp.push_back(binary.at(i));
        if(temp.size() == 4) {
            temp = Converter::reverse_str(temp);
            int exponent {0}, result {0};
            for(int j = temp.size()-1; j >= 0; j--) {
                int potency = pow(divider_to_binary, exponent);
                if(temp.at(j) == '1')
                    result += potency;
                exponent++;
            }
            if(result > 9)
                hexadecimal_value += Converter::convert_number_to_letter(result);
            else
                hexadecimal_value += static_cast<char>(result)+48;
            temp.clear();
        }
        i--;
    }
    if(hexadecimal_value.size() > 1)
        hexadecimal_value = Converter::reverse_str(hexadecimal_value);
    return hexadecimal_value;
}

const char Converter::convert_number_to_letter(const int number) {
    char converted_letter {65};
    for(int i {10}; i < number; i++) {
        converted_letter++;
    }
    return converted_letter;
}

int Converter::convert_letter_to_number(const char letter) {
    int number {10};
    if((letter - 48) > 9) {
        for(int i {65}; i < 70; i++) {
            if(letter == i) {
                break;
            }
            number++;
        }
    } else
        number = letter - 48;
    return number;
}

std::string Converter::reverse_str(std::string str) {
    size_t j = str.size()-1;
    for(size_t i {0}; i <= j; i++) {
        char temp = str.at(j);
        str.at(j) = str.at(i);
        str.at(i) = temp;
        j--;
    }
    return str;
}

std::string Converter::push_begining(std::string str, const int amount_to_add) {
    int end = str.size()-1;
    for(int i {0}; i < amount_to_add; i++) {
        str.at(end) = str.at(end-1);
        str.at(i) = '0';
        end--;
        str.pop_back();
    }
    return str;
}