/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:28:18 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 06:28:14 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <_ctype.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>

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

bool checkDot( std::string &input ){
    size_t found = input.find('.', 0);
    if (found == std::string::npos)
        return true;
    else if (found + 1 <= input.size() && input.find('.', found + 1) == std::string::npos)
        return true;
    return false;
}

bool validInput( std::string input ){
    if (input.empty())
        return false;
    if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
        return true;
    else {
        int dot=checkDot(input);
        if (!dot)
            return false;
        for (size_t i=(input[0] == '-' || input[1] == '+'); i < input.size(); i++){
            if (isdigit(input.at(i)))
                continue;
            if (input.at(i) == '.')
                continue;
            if (input.at(i) == 'f' && i+1 == input.size())
                    break;
            else
                return false;
        }
        return true;
    }
}

void ScalarConverter::convert( std::string input ){
    double x = atof(input.c_str());
    try {
        char c = static_cast<char>(x);
        if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
            throw ImpossibleException();
        if (isprint(c) == false)
            throw NonDisplayableException();
        std::cout << "char: '" << c << "'" << std::endl;
    } catch (std::exception &e) {
        std::cout << "char: " << e.what() << std::endl;
    }
    try {
        if (input == "nan" || input == "nanf" || input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
            throw ImpossibleException();
        int i = static_cast<int>(x);
        std::cout << "int: " << i << std::endl;
    } catch (std::exception &e) {
        std::cout << "int: " << e.what() << std::endl;
    }
    try {
        float f = static_cast<float>(x);
        std::cout << "float: " << f;
        (f - static_cast<int>(f) == 0)?std::cout << ".0f" << std::endl : std::cout << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << "float: " << e.what() << std::endl;
    }
    try {
        std::cout << "double: " << x;
        (x - static_cast<int>(x) == 0)?std::cout << ".0" << std::endl : std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << "double: " << e.what() << std::endl;
    }
}
