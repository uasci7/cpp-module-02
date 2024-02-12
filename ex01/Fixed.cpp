/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:18:17 by uasci             #+#    #+#             */
/*   Updated: 2024/01/24 06:20:25 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"

Fixed::Fixed(void) : _pf(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int n) : _pf(n << _nbFrac)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float f) : _pf((int)roundf(f * (1 << _nbFrac)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_pf = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_pf);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_pf = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_pf / (1 << _nbFrac));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)_pf / (1 << _nbFrac))));
}

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
