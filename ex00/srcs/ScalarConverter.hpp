/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:43:18 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/10/22 15:43:21 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cmath>

/*	Ex00 tecahes us to use "static_cast<cast type>(parameter)"	*/
class ScalarConverter
{
	public:
		/*	OCF	 */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &src);

		/* Member functions */
		char	toChar(double src);
		int		toInt(double src);
		float	toFloat(double src);
		double	toDouble(double src);
		double	convertInput(std::string input);

	private:
};

#endif
