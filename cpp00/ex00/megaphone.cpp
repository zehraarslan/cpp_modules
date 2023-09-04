/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarslan <zarslan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:44:44 by zarslan           #+#    #+#             */
/*   Updated: 2023/01/23 23:44:48 by zarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
    {
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
        {
            std::cout << char(toupper(argv[i][j]));
        }
        std::cout <<" ";
    }
    std::cout << std::endl;
    return (0);
}