/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:36:09 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 09:59:48 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base::~Base( void ) {}

Base *generate( void ) {
    Base *ptr;
    srand(time(NULL));
    int r = rand();
    if (r % 2 == 0)
        ptr = new A;
    else if (r % 3 == 0)
        ptr = new B;
    else
        ptr = new C;
    return ptr;
}

void identify( Base *p ){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "The pointer is of type [A]" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "The pointer is of type [B]" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "The pointer is of type [C]" << std::endl;
}

void identify( Base &p ){
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
    }
    catch (std::bad_cast){
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
        }
        catch (std::bad_cast){
            std::cout << "The reference is of type [C]" << std::endl;
            return ;
        }
        std::cout << "The reference is of type [B]" << std::endl;
        return ;
    }
    std::cout << "The reference is of type [A]" << std::endl;
    return ;
}
