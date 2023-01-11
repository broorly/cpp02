
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
  this->raw_++;
  return tmp;
}

Fixed &Fixed::operator--() {
  this->raw_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->raw_--;
  return tmp;
}

Fixed Fixed::operator+=(const Fixed &t) {
  this->raw_ = this->raw_ + t.raw_;
	return *this;
}

Fixed Fixed::operator-=(const Fixed &t) {
  this->raw_ = this->raw_ - t.raw_;
	return *this;
}

Fixed Fixed::operator*=(const Fixed &t) {
  this->raw_ = (this->raw_ * t.getRawBits()) >> this->fractional_bits_;
	return *this;
}

Fixed Fixed::operator/=(const Fixed &t) {
  this->raw_ = (this->raw_ << this->fractional_bits_) / t.getRawBits();
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
  if(f1.getRawBits() < f2.getRawBits())
      return(f1);
  else
    return(f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    if(f1.getRawBits() < f2.getRawBits())
      return(f1);
  else
    return(f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	  if(f1.getRawBits() > f2.getRawBits())
      return(f1);
  else
    return(f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    if(f1.getRawBits() > f2.getRawBits())
      return(f1);
  else
    return(f2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

bool Fixed :: operator==(const Fixed &t)const {
  return this->raw_ == t.getRawBits() ? true : false;
}

bool Fixed :: operator!=(const Fixed &t)const {
  return this->raw_ != t.getRawBits() ? true : false;
}

bool Fixed :: operator<(const Fixed &t) const{
  return this->raw_ < t.getRawBits() ? true : false;
}

bool Fixed :: operator>(const Fixed &t) const{
  return this->raw_ > t.getRawBits() ? true : false;
}

bool Fixed :: operator<=(const Fixed &t) const{
  return this->raw_ <= t.getRawBits() ? true : false;
}

bool Fixed :: operator>=(const Fixed &t) const{
  return this->raw_ >= t.getRawBits() ? true : false;
}

Fixed Fixed :: operator+(const Fixed &t) {
  Fixed tmp;
  tmp.setRawBits(this->raw_ + t.getRawBits());
  return tmp;
}

Fixed Fixed :: operator-(const Fixed &t) {
 Fixed tmp;
  tmp.setRawBits(this->raw_ - t.getRawBits());
  return tmp;
}

Fixed Fixed :: operator*(const Fixed &t) {
  Fixed tmp;
  tmp.setRawBits((this->raw_ * t.getRawBits()) >> this->fractional_bits_);
  return(tmp.getRawBits());
}

Fixed Fixed :: operator/(const Fixed &t) {
 Fixed tmp;
  tmp.setRawBits((this->raw_ << this->fractional_bits_) / t.getRawBits());
  return(tmp.getRawBits());
}