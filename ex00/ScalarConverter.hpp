/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:21:51 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/05 19:15:07 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

class ScalarConverter {
    private:
        /*      [canonical form]       */
        ScalarConverter();
        ScalarConverter( ScalarConverter const &src );
        ~ScalarConverter();
        ScalarConverter &operator=( ScalarConverter const &src );
        /**********************************/
    public:
        static void convert( std::string input );
        class NonDisplayableException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class ImpossibleException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class CharException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class IntException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FloatException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class DoubleException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

bool validInput( std::string input );
