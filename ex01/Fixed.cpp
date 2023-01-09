/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:33 by mrafik            #+#    #+#             */
/*   Updated: 2023/01/09 19:31:51 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() {
	raw_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->raw_ = i << fractional_bits_;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
  this->raw_ = roundf(f * (1 << this->fractional_bits_));
}

Fixed::~Fixed() {
	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  this->raw_ = fixed.getRawBits();
}


Fixed &Fixed::operator=(Fixed fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	raw_ = fixed.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->raw_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->raw_ = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->raw_ / (1 << this->fractional_bits_));
}

int Fixed::toInt(void) const {
  return (this->raw_ >> this->fractional_bits_);
}