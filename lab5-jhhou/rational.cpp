#include "rational.h"

/** Helper funciton that finds the greatest common divisor of two integers.
 */
int Rational::gcd(const int a, const int b) const{
    for (int i = (a < b ? a : b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }

    return 1;
}

/**
Constructor supports 3 types of Initialization 
*/
Rational::Rational(int n, int d){
    if (d == 0) {
        throw invalid_argument("Denominator can't be zero!");
    }

    else if (d < 0) {
        this->n = -n;
        this->d = -d;
    }

    else {
        this->n = n;
        this->d = d;
    }
}

/** Returns the numerator*/    
int Rational::num() const {
    return n;
}

/** Returns the denomator*/
int Rational::denom() const {
    return d;
}

/** Returns the reciprocal of the rational number*/
Rational Rational::reciprocal() const{
    return Rational{d, n};
}

/** reduces the rational number such that 
* the greatest common divisor of 
* the numerator and denominator is 1
*/
void Rational::reduce() {
    if (n == 0) {
        d = 1;
    }

    else {
        int gcd_ = gcd(n, d);
        n /= gcd_;
        d /= gcd_;
    }
}

/** Addition compound-assignment operator for Rational numbers. */
Rational & Rational::operator+=(const Rational &rnum) {
    n = n * rnum.denom() + rnum.num() * d;
    d *= rnum.denom();
    reduce();

    return *this;
}

/** Subtraction compound-assignment operator for Rational numbers. */
Rational & Rational::operator-=(const Rational &rnum) {
    *this += Rational{-rnum.num(), rnum.denom()};

    return *this;
}

/** Multiplication compound-assignment operator for Rational numbers. */
Rational & Rational::operator*=(const Rational &rnum) {
    n *= rnum.num();
    d *= rnum.denom();
    reduce();

    return *this;

}

/** Division compound-assignment operator for Rational numbers. */
Rational & Rational::operator/=(const Rational &rnum){
    *this *= rnum.reciprocal();

    return *this;
}


/** Returns the sum of two given rational numbers. */
Rational operator+(const Rational &a, const Rational &b) {
    return Rational{a.num(), a.denom()} += b;
}


/** Returns the difference of two given rational numbers. */
Rational operator-(const Rational &a, const Rational &b) {
    return Rational{a.num(), a.denom()} -= b;
}

/** Returns the product of two given rational numbers. */
Rational operator*(const Rational &a, const Rational &b){
    return Rational{a.num(), a.denom()} *= b;
}

/** Returns the quotient of two given rational numbers. */
Rational operator/(const Rational &a, const Rational &b) {
    return Rational{a.num(), a.denom()} /= b;
}

/** Stream-Output for the given Rational number. */
ostream & operator<<(ostream &os, const Rational &r) {
    os << r.num();

    if (r.denom() != 1) {
        os << "/" << r.denom();
    }

    return os;
}