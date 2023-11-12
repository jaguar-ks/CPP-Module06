/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:32:32 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 09:56:22 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Base {
    public:
        virtual ~Base( void );
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate( void );

void identify( Base *p );

void identify( Base &p );
