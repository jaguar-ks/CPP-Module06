/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:56:08 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 08:19:38 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <sys/_types/_uintptr_t.h>

int main( void ) {
    Data *ptr = new Data("person", 155);
    std::cout << "addr of ptr[" << ptr << ']' << std::endl;
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << raw << std::endl;
    Data *ptr1 = Serializer::deserialize(raw);
    std::cout << "The name is:[" << ptr1->name << "]\nThe id is[" << ptr1->id << "]\nThe addr is [" << ptr1 << ']' <<std::endl;
    std::string *n = reinterpret_cast<std::string *>(ptr1);
    std::cout << "N value -> " << *n << "\t N addr -> " << n << std::endl;
    n++;
    int *i = reinterpret_cast<int *>(n);
    std::cout << "I value -> " << *i << "\t I addr -> " << i << std::endl;
    n = reinterpret_cast<std::string *>(i);
    n--;
    std::cout << "N value -> " << *n << "\t N addr -> " << n << std::endl;
    ptr1 = reinterpret_cast<Data *>(n);
    std::cout << "The name is:[" << ptr1->name << "]\nThe id is[" << ptr1->id << "]\nThe addr is [" << ptr1 << ']' <<std::endl;
}
