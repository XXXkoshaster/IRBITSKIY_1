#pragma once

#include <iostream>

class Complex final
{
private:
    double real;
    double imag;
public:
    Complex(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

    Complex add(const Complex& other) const 
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex sub(const Complex& other) const 
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex multiply(const Complex& other) const
    { 
        return Complex(real * other.real - imag * other.imag, real * other.real + imag * other.imag);
    }

    Complex divide(const Complex& other, double eps) const
    {
        double dominator = other.real * other.real + other.imag * other.imag;

        if (std::abs(dominator) < eps)
            throw std::runtime_error("Division by zero\n");

        double new_real = (real * other.real + imag * other.imag) / dominator;
        double new_imag = (other.real * imag - real * other.imag) / dominator;

        return Complex(new_real, new_imag);
    }

    double module() const 
    {
        return std::sqrt(real * real + imag * imag);
    }

    double get_args() const
    {
        return std::atan2(imag, real);
    }
    
    double get_real() const
    {
        return real;
    }

    double get_imag() const
    {
        return imag;
    }
};
