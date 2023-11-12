/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:56:24 by faksouss          #+#    #+#             */
/*   Updated: 2023/11/12 10:02:32 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

int main( void ) {
    Base *p = generate();
    identify(p);
    identify(*p);
    B k;
    Base &l = k;
    identify(l);
}
