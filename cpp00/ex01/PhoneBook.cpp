/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:45:28 by zarslan           #+#    #+#             */
/*   Updated: 2023/01/24 00:33:47 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
}

PhoneBook::~PhoneBook() {}

int input_control(std::string *input, std::string message)
{
    while (1)
    {
        if (!getline(std::cin, *input))
            return (1);
        if (input->empty() == false)
            return (0);
        else
        {
            std::cout << "Empty input. Try again." << std::endl;
            std::cout << message ;
        }
    }
}

bool number_control(std::string input)
{
    int i;

    i = 0;
    while(input[i])
    {
        if(!isdigit(input[i]))
            return (false);
        i++;
    }
    return (true);
}

int PhoneBook::add_contact()
{
    Contact _contact;
    std::string input;

    std::cout << "Enter the contact first name : ";
    if(input_control(&input, "Enter the contact first name : "))
        return (1);
    _contact.setFirstName(input);


    std::cout << "Enter the contact last name : ";
    if(input_control(&input, "Enter the contact last name : "))
        return (1);
    _contact.setLastName(input);

    std::cout << "Enter the contact nick name : ";
    if(input_control(&input, "Enter the contact nick name : "))
        return (1);
    _contact.setNickName(input);

    std::cout << "Enter the contact phone number : ";
    while (1)
    {
        if(input_control(&input, "Enter the contact phone number : "))
            return (1);
        if(number_control(input) == true)
            break ;
        std::cout << input << " is not a number. Try again" << std::endl;
        std::cout << "Enter the contact phone number : ";
    }
    _contact.setPhoneNumber(input);

    std::cout << "Enter the contact darkest secret : ";
    if(input_control(&input, "Enter the contact darkest secret : "))
        return (1);
    _contact.setDarkestSecret(input);

    contacts[currentIndex] = _contact;
    currentIndex = (currentIndex + 1) % 8;
    std::cout << std::endl;
    
    return (0);
}

std::string str_len_control(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    contact_print_line(Contact contact, int i)
{
    std::cout << std::setw(10) << i << "|";
    std::cout << std::setw(10) << str_len_control(contact.getFirstName()) << "|";
    std::cout << std::setw(10) << str_len_control(contact.getLastName()) << "|";
    std::cout << std::setw(10) << str_len_control(contact.getNickName()) << std::endl;
}

int PhoneBook::search_contact()
{
    int i;
    int index;
    std::string input;

    std::cout << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::setw(10) << "Nick Name" << std::endl;

    i = 0;
    while (i < 8 && contacts[i].getFirstName().empty() == false)
    {
        contact_print_line(contacts[i], i);
        i++;
    }

    if (i == 0)
    {
        std::cout << "Phone book is empty." << std::endl;
        std::cout << std::endl;
        return (0);
    }
    std::cout << "Enter an index : ";
    while (1)
    {
        if (!getline(std::cin, input))
            return (1);
        if (input.empty())
        {
            std::cout << "Empty input. Try again." << std::endl;
            std::cout << "Enter an index : ";
        }
        else
        {
            index = input[0] - 48;
            if (input.length() > 1 || index < 0 || index >= i)
            {
                std::cout << "Invalid index. Try again" << std::endl;
                std::cout << "Enter an index : ";
            }
            else
                break;
        }
    }
    std::cout << "First Name : " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name : " << contacts[index].getLastName() << std::endl;
    std::cout << "Nick Name : " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    std::cout << std::endl;

    return (0);
}