/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:42:59 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 08:01:05 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sys/_types/_uintptr_t.h>

typedef struct Data{
    std::string name;
    int id;
    Data( std::string const &name, int const id );
}Data;

class Serializer{
    private:
        Serializer( void );
        Serializer( Serializer const &obj );
        ~Serializer( void );
        Serializer &operator=( Serializer const &obj );
    public:
        static uintptr_t serialize( Data *ptr );
        static Data *deserialize( uintptr_t raw );
};
