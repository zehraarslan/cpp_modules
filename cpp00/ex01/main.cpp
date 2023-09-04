/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:45:20 by zarslan           #+#    #+#             */
/*   Updated: 2023/01/24 00:24:02 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;

    std::cout << "Welcome to the Phone Book App" << std::endl;
    std::cout << "Please enter ADD, SEARCH OR EXIT : ";

    while (getline(std::cin, input))
    {
        if (input == "ADD")
        {
            if (phoneBook.add_contact())
            {
                std::cout << "An unexpected error has occurred. The application has been closed" << std::endl;
                return (EXIT_FAILURE);
            }
        }
        else if (input == "SEARCH")
        {
            phoneBook.search_contact();
        }

        else if (input == "EXIT")
        {
            break;
        }

        else
         std::cout << "Invalid input. Try again" << std::endl;
        std::cout << "Please enter ADD, SEARCH OR EXIT : ";
    }
    std::cout << "Good bye!" <<std::endl;
}