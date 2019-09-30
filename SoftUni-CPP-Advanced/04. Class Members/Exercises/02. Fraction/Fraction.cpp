#include "Fraction.h"

namespace MyFraction {
  Fraction::Fraction() : numerator(0), denominator(1) { }

  Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    this->normalize();
  }

  int Fraction::gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  void Fraction::normalize() {
    int gdc = gcd(this->numerator, this->denominator);
    if (gdc > 1) {
      this->numerator /= gdc;
      this->denominator /= gdc;
    }
  }

  int Fraction::getNumerator() const {
    return this->numerator;
  }

  int Fraction::getDenominator() const {
    return this->denominator;
  }

  Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    ++(*this);
    return temp;
  }

  Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    --(*this);
    return temp;
  }

  Fraction& Fraction::operator++() {
    this->numerator = this->numerator + this->denominator;
    this->normalize();
    return *this;
  }

  Fraction& Fraction::operator--() {
    this->numerator = this->numerator - this->denominator;
    this->normalize();
    return *this;
  }

  Fraction& Fraction::operator/=(const Fraction& other) {
    this->numerator *= other.denominator;
    this->denominator *= other.numerator;
    this->normalize();
    return *this;
  }

  Fraction& Fraction::operator*=(const Fraction& other) {
    this->numerator *= other.numerator;
    this->denominator *= other.denominator;
    this->normalize();
    return *this;
  }

  Fraction& Fraction::operator-=(const Fraction& other) {
    if (this->denominator != other.denominator) {
      this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
      this->denominator *= other.denominator;
    } else {
      this->numerator -= other.numerator;
    }
    this->normalize();
    return *this;
  }

  Fraction& Fraction::operator+=(const Fraction& other) {
    if (this->denominator != other.denominator) {
      this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
      this->denominator *= other.denominator;
    } else {
      this->numerator += other.numerator;
    }
    this->normalize();
    return *this;
  }

  Fraction operator-(const Fraction& fraction) {
    return { -fraction.numerator, fraction.denominator };
  }

  Fraction operator+(const Fraction& fraction) {
    return Fraction{ fraction };
  }

  Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction result{ lhs };
    result += rhs;
    return result;
  }

  Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction result{ lhs };
    result -= rhs;
    return result;
  }

  Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction result{ lhs };
    result *= rhs;
    return result;
  }

  Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction result{ lhs };
    result /= rhs;
    return result;
  }

  const bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
  }

  const bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return rhs < lhs;
  }

  const bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return lhs > rhs || lhs == rhs;
  }

  const bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return lhs < rhs || lhs == rhs;
  }

  const bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs != rhs);
  }

  const bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return lhs < rhs || lhs > rhs;
  }

  std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    if (fraction.denominator == 0) {
      out << "NaN";
    } else if (fraction.numerator == 0) {
      out << 0;
    } else if (fraction.denominator == 1) {
      out << fraction.numerator;
    } else {
      out << fraction.numerator << "/" << fraction.denominator;
    }
    return out;
  }

  std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char slash;
    in >> fraction.numerator >> slash >> fraction.denominator;
    fraction.normalize();
    return in;
  }
}
