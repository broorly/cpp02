
#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

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
  Fixed &operator=(Fixed fixed);

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  Fixed operator+=(const Fixed &t);
	Fixed operator-=(const Fixed &t);
	Fixed operator*=(const Fixed &t);
	Fixed operator/=(const Fixed &t);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
  bool operator==(const Fixed &t) const;
  bool operator!=(const Fixed &t)const;
  bool operator<(const Fixed &t)const;
  bool operator>(const Fixed &t)const;
  bool operator<=(const Fixed &t)const;
  bool operator>=(const Fixed &t)const;
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
  Fixed operator+(const Fixed &t);
  Fixed operator-(const Fixed &t);
  Fixed operator*(const Fixed &t);
  Fixed operator/(const Fixed &t);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);



#endif