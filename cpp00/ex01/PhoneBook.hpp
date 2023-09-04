/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:45:44 by zarslan           #+#    #+#             */
/*   Updated: 2023/01/23 23:46:39 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstring>
# include <iostream>
# include <iomanip>

class PhoneBook
{
    private:
        Contact contacts[8];
        int currentIndex;
    public:
        PhoneBook();
        ~PhoneBook();
        int add_contact();
        int search_contact();
};

#endif