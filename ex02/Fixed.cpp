
#include "Fixed.hpp"

Fixed::Fixed() {
	raw_ = 0;
}

Fixed::Fixed(const int i) {
	this->raw_ = i << fractional_bits_;
}

Fixed::Fixed(const float f) {
  this->raw_ = roundf(f * (1 << this->fractional_bits_));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	this->raw_ = fixed.getRawBits();
}

Fixed &Fixed::operator=(Fixed fixed) {
	raw_ = fixed.getRawBits();
	return *this;
}

Fixed &Fixed::operator++() {
  this->raw_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed &Fixed::operator--() {
  this->raw_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}

Fixed Fixed::operator+=(const Fixed &rhs) {
  this->raw_ = this->raw_ + rhs.raw_;
	return *this;
}

Fixed Fixed::operator-=(const Fixed &rhs) {
  this->raw_ = this->raw_ - rhs.raw_;
	return *this;
}

Fixed Fixed::operator*=(const Fixed &rhs) {
  this->raw_ =
      ((long long)this->raw_ * (long long)rhs.getRawBits()) >>
      this->fractional_bits_;
	return *this;
}

Fixed Fixed::operator/=(const Fixed &rhs) {
  this->raw_ =
      ((long long)this->raw_ << this->fractional_bits_) /
      rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->raw_;
}

void Fixed::setRawBits(int const raw) {
	this->raw_ = raw;
}

float Fixed::toFloat(void) const {
  return (float)this->raw_ / (1 << this->fractional_bits_);
}

int Fixed::toInt(void) const {
  return this->raw_ >> this->fractional_bits_;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

bool operator==(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() == rhs.getRawBits() ? true : false;
}

bool operator!=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() != rhs.getRawBits() ? true : false;
}

bool operator<(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() < rhs.getRawBits() ? true : false;
}

bool operator>(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() > rhs.getRawBits() ? true : false;
}

bool operator<=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() <= rhs.getRawBits() ? true : false;
}

bool operator>=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() >= rhs.getRawBits() ? true : false;
}

Fixed operator+(Fixed lhs, const Fixed &rhs) {
  lhs += rhs;
  return lhs;
}

Fixed operator-(Fixed lhs, const Fixed &rhs) {
  lhs -= rhs;
  return lhs;
}

Fixed operator*(Fixed lhs, const Fixed &rhs) {
  lhs *= rhs;
  return lhs;
}

Fixed operator/(Fixed lhs, const Fixed &rhs) {
  lhs /= rhs;
  return lhs;
}