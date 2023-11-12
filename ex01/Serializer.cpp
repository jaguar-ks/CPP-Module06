/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:50:07 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 07:59:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <string>
#include <sys/_types/_uintptr_t.h>

Serializer::Serializer( void ){}

Serializer::Serializer( Serializer const &obj ){*this = obj;}

Serializer &Serializer::operator=( Serializer const &obj ){(void)obj; return *this;}

Serializer::~Serializer( void ){}

Data::Data( std::string const &name, int const id ){
    this->name = name;
    this->id = id;
}

uintptr_t Serializer::serialize( Data *ptr ){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize( uintptr_t raw ){
    return reinterpret_cast<Data *>(raw);
}
