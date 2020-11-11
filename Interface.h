#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "Converter.h"

#include <memory>
#include <string>

class Interface : public Converter {
    private:
        //CLASS ATTRIBUTES
        double decimal;
        std::shared_ptr<std::string> binary_ptr;
        std::shared_ptr<std::string> hexadecimal_ptr;
    public:
        //CONSTRUCTORS AND DESTRUCTORS
        Interface();
        ~Interface() = default;

        //GETTERS AND SETTERS
        void set_decimal(const double decimal) {this->decimal = decimal;}
        const double get_decimal() const {return decimal;}
        void set_binary_ptr(const std::shared_ptr<std::string> binary_ptr) {this->binary_ptr = binary_ptr;}
        const std::string get_binary_ptr() const {return *binary_ptr;}
        void set_hexadecimal_ptr(const std::shared_ptr<std::string> hexadecimal_ptr) {this->hexadecimal_ptr = hexadecimal_ptr;}
        const std::string get_hexadecimal_ptr() const {return *hexadecimal_ptr;}

        //OTHER FUNCTIONS
        void menu();
        int get_input(const int min, const int max);
        std::shared_ptr<std::string> get_str_input();
};

#endif