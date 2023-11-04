/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:04:14 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/04 14:11:05 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av ) {
    if (ac != 2) {
        std::cerr << "Invalide number of argiment" << std ::endl << "\tUsage: ./convert [input]" << std::endl;
        return 1;
    }
    std::string input = av[1];
    input.erase(0, input.find_first_not_of(" \t\n\v\f\r"));
    input.erase(input.find_last_not_of(" \t\n\v\f\r") + 1);
    ScalarConverter sc(input);
    
}
