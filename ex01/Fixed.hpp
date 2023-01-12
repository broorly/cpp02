/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:06:30 by mrafik            #+#    #+#             */
/*   Updated: 2023/01/12 23:49:00 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
 private:
  int raw_;
  static const int fractional_bits_ = 8;
 
 public:
    Fixed();
    Fixed(const int i);
    Fixed(const float f);
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed& fixed);
	

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif