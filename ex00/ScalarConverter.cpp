/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:28:18 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/04 15:35:04 by faksouss         ###   ########.fr       */
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
        std::cout << "float: " << f << ".0f" << std::endl;
    } catch (std::exception &e) {
        std::cout << "float: " << e.what() << std::endl;
    }
    try {
        double d = atof(input.c_str());
        std::cout << "double: " << d << ".0" << std::endl;
    } catch (std::exception &e) {
        std::cout << "double: " << e.what() << std::endl;
    }
}
