/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:16:15 by schuah            #+#    #+#             */
/*   Updated: 2023/10/22 15:34:56 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Base.hpp"
# include"A.hpp"
# include"B.hpp"
# include"C.hpp"

Base	*generate(void)
{
	int	n;

	srand(time(NULL));
	n = rand() % 3;
	if (n == 0)
		return (dynamic_cast<Base *>(new A));
	if (n == 1)
		return (dynamic_cast<Base *>(new B));
	return (dynamic_cast<Base *>(new C));
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

/*	need to use try catch because dynamic_cast will throw an exeption if unsuccesful	*/
void	identify(Base &p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl; 
	}
	catch(const std::exception& e) {}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl; 
	}
	catch(const std::exception& e) {}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl; 
	}
	catch(const std::exception& e) {}
}

int	main(void)
{
	std::cout << "\n---------- EX02 Random Test ----------\n" << std::endl;
    Base *random = generate();
    
    identify(random);
    identify(*random);

    delete random;
    return (0);
}
