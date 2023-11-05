/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:28:18 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/05 19:28:22 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}

ScalarConverter::ScalarConverter( ScalarConverter const &src ){*this = src;}

ScalarConverter::~ScalarConverter( void ){}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &src ){
    (void)src;
    return *this;
}

const char *ScalarConverter::NonDisplayableException::what() const throw(){
    return "Non displayable";
}

const char *ScalarConverter::ImpossibleException::what() const throw(){
    return "impossible";
}

const char *ScalarConverter::CharException::what() const throw(){
    return "impossible to convert to char";
}

const char *ScalarConverter::IntException::what() const throw(){
    return "impossible to convert to int";
}

const char *ScalarConverter::FloatException::what() const throw(){
    return "impossible to convert to float";
}

const char *ScalarConverter::DoubleException::what() const throw(){
    return "impossible to convert to double";
}

bool validInput( std::string input ){
    if (input.empty())
        return false;
    if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
        return true;
    else {
        if (input[0] == '-' || input[0] == '+')
            input.erase(0, 1);
        if (input.empty())
            return false;
        int dot = 0;
        for (int i = 0; i < (int)input.length(); i++) {
            if (input[i] == '.'){
                if (dot == 1)
                    return false;
                dot++;
            }
            else if (isdigit(input[i]) == false && input[i] != 'f')
                return false;
            else if (input[i] == 'f' && i != (int)input.length() - 1)
                return false;
        }
        return true;
    }
}

void ScalarConverter::convert( std::string input ){
    try {
        int i = atoi(input.c_str());
        if (isprint(i) == false)
            throw NonDisplayableException();
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    } catch (std::exception &e) {
        std::cout << "char: " << e.what() << std::endl;
    }
    try {
        int i = atoi(input.c_str());
        std::cout << "int: " << i << std::endl;
    } catch (std::exception &e) {
        std::cout << "int: " << e.what() << std::endl;
    }
    try {
        float f = atof(input.c_str());
        std::cout << "float: " << f;
        (f - static_cast<int>(f) == 0)?std::cout << ".0f" << std::endl : std::cout << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << "float: " << e.what() << std::endl;
    }
    try {
        double d = atof(input.c_str());
        std::cout << "double: " << d;
        (d - static_cast<int>(d) == 0)?std::cout << ".0" << std::endl : std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << "double: " << e.what() << std::endl;
    }
}
