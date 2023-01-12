/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:37:59 by mrafik            #+#    #+#             */
/*   Updated: 2023/01/12 23:49:42 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
 private:
  int raw_;
  static const int fractional_bits_ = 8;
 
 public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed& fixed);
  
  int getRawBits(void) const;
  void setRawBits(int const raw);

};

#endif