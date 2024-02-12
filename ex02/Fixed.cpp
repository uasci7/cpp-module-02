/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uasci <uasci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:18:43 by uasci             #+#    #+#             */
/*   Updated: 2024/01/31 05:06:13 by uasci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int	Fixed::_frac = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _value(value * (1 << _frac))
{  
	std::cout << "Int constructor called" << std::endl;
} 

Fixed::Fixed(const float value): _value(value * (1 << _frac))
{
	std::cout << "Float constructor called" << std::endl;	 
} 

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

float	Fixed::toFloat(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value * ft_pow(2, -this->_frac));
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

Fixed	Fixed::operator--(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}

Fixed& Fixed::min( Fixed& first, Fixed& second ){
	if (first.toFloat() > second.toFloat())
		return (second);
	return (first);
}

Fixed& Fixed::min( const Fixed& first, const Fixed& second ){
	if (first.toFloat() > second.toFloat())
		return ((Fixed&)second);
	return ((Fixed&)first);
}

Fixed& Fixed::max( Fixed& first, Fixed& second ){
	if (first.toFloat() < second.toFloat())
		return (second);
	return (first);
}

Fixed& Fixed::max( const Fixed& first, const Fixed& second ){
	if (first.toFloat() < second.toFloat())
		return ((Fixed&)second);
	return ((Fixed&)first);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
