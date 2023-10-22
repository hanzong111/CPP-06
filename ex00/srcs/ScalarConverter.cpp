/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:43:10 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/10/22 15:43:14 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

/* Converts double to char type */
char	ScalarConverter::toChar(double src)
{
	if (std::isnan(src) || std::isinf(src))
		throw std::string("Impossible");
	if (std::isprint(src) == 0)
		throw std::string("Non displayable");
	return (static_cast<char>(src));
}

/* Converts double to int type */
int		ScalarConverter::toInt(double src)
{
	long	output;

	output = static_cast<long>(src);
	if (std::isnan(src) || std::isinf(src)
		|| output < INT_MIN || output > INT_MAX)
		throw std::string("Impossible");
	return (static_cast<int>(src));
}

/* Converts double to float type */
float	ScalarConverter::toFloat(double src)
{
	return (static_cast<float>(src));
}

/* Converts double to double type */
double	ScalarConverter::toDouble(double src)
{
	return (static_cast<double>(src));
}

/* Checks whether input can be converted */
double	ScalarConverter::convertInput(std::string input)
{
	int	dot_counter;
	
	std::cout << input << std::endl;
	dot_counter = 0;
	if (input.length() <= 1 && std::isdigit(input[0]) == 0)
		return (static_cast<int>(input[0]));   
	if ((input != "-inff" && input != "+inff" && input != "inff"
		&& input != "-inf" && input != "+inf" && input != "inf"
		&& input != "nanf" && input != "nan"))
	{
		for (size_t i = (input[0] == '-' || input[0] == '+'); i < input.length(); i++)
		{
			if (std::isdigit(input[i]) == 0 && input[i] != '.' && input[input.length() - 1] != 'f')
				throw std::string("Cannot be converted");
			if (input[i] == '.')
				dot_counter++;
		}
	}
	if (dot_counter > 1)
		throw std::string("Cannot be converted");
	return (std::stod(input));
}
