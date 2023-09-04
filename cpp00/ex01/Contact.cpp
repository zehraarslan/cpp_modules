/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:44:55 by zarslan           #+#    #+#             */
/*   Updated: 2023/01/23 23:44:57 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

std::string Contact::getFirstName()
{
    return firstName;
}
std::string Contact::getLastName()
{
    return lastName;
}
std::string Contact::getNickName()
{
    return nickName;
}
std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}

void Contact::setFirstName(std::string _firstName)
{
    firstName = _firstName;
}
void Contact::setLastName(std::string _lastName)
{
    lastName = _lastName;
}
void Contact::setNickName(std::string _nickName)
{
    nickName = _nickName;
}
void Contact::setPhoneNumber(std::string _phoneNumber)
{
    phoneNumber = _phoneNumber;
}
void Contact::setDarkestSecret(std::string _darkestSecret)
{
    darkestSecret = _darkestSecret;
}