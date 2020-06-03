#include <iostream>
#include <stdexcept>

using namespace std;

/*! \class
    \brief A class representing rational numbers
    positive and negative rational numbers 
    as two int values
    numerator and denominator.
 */
class Rational {
    /** Numerator */
    int n;

    /** Denominator */
    int d;

    /*! \fn int gcd(const int a, const int b) const
        finds the greatest common divisor of two integers 
        \param a Integer 1
        \param b Integer 2
        \return the greatest common divisor of a and b
    */
    int gcd(const int a, const int b) const;


public:
    /*! \fn Rational(int n = 0, int d =1)
        Constructor supports 3 types of Initialization 
        \param n Nominator
        \param d Denominator
    */
    Rational(int n = 0, int d =1);

    /*! \fn int num() const
        \brief Getter of the numerator
        \return the numerator
    */    
    int num() const;

    /*! \fn int denom() const
        \brief Getter of the denominator
        \return the denominator
    */
    int denom() const;

    /*! \fn Rational reciprocal() const
        \brief Get the reciprocal of the rational number
        \return the reciprocal
    */
    Rational reciprocal() const;

    /*! \fn void reduce()
        Reduces the rational number such that 
        the greatest common divisor of 
        the numerator and denominator is 1
    */
    void reduce();

    /*! \fn Rational & operator+=(const Rational &rnum)
        Addition compound-assignment operator for Rational numbers
        \param rnum the rational number added
    */
    Rational & operator+=(const Rational &rnum);

    /*! \fn Rational & operator-=(const Rational &rnum)
        Subtraction compound-assignment operator for Rational numbers
        \param rnum the rational number subtracted
    */
    Rational & operator-=(const Rational &rnum);

    /*! \fn Rational & operator*=(const Rational &rnum)
        Multiplication compound-assignment operator for Rational numbers
        \param rnum the rational number multiplied 
    */
    Rational & operator*=(const Rational &rnum);

    /*! \fn Rational & operator/=(const Rational &rnum)
        Addition compound-assignment operator for Rational numbers
        \param rnum the rational number as the divisor
    */
    Rational & operator/=(const Rational &rnum);
};

/*! \fn Rational operator+(const Rational &a, const Rational &b)
    Returns the sum of two given rational numbers
    \param a Rational number a
    \param b Rational number b
    \return sum of two rational numbers
*/
Rational operator+(const Rational &a, const Rational &b);

/*! \fn Rational operator-(const Rational &a, const Rational &b)
    Returns the difference of two given rational numbers
    \param a Rational number a
    \param b Rational number b
    \return difference of two rational numbers
*/
Rational operator-(const Rational &a, const Rational &b);

/*! \fn Rational operator*(const Rational &a, const Rational &b)
    Returns the product of two given rational numbers
    \param a Rational number a
    \param b Rational number b
    \return product of two rational numbers
*/
Rational operator*(const Rational &a, const Rational &b);

/*! \fn Rational operator/(const Rational &a, const Rational &b)
    Returns the quotient of two given rational numbers
    \param a Rational number a
    \param b Rational number b
    \return quotient of two rational numbers
*/
Rational operator/(const Rational &a, const Rational &b);

/*! \fn ostream & operator<<(ostream &os, const Rational &r
    Stream-Output for the given Rational number. 
*/
ostream & operator<<(ostream &os, const Rational &r);