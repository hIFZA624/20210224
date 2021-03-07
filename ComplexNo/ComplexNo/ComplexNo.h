#include<iostream>
#include<math.h>
using namespace std;
class Complex
{
	double real;
	double imaginary;
public:
	Complex()
	{
		real = 0;
		imaginary = 0;
	}
	Complex(double r)
	{
		real = r;
	   imaginary = 0;
	}
	Complex(double r, double i)
	{
		real = r;
		imaginary = i;
	}
	Complex(Complex &c)
	{
		real = c.real;
		imaginary = c.imaginary;
		//cout << "Copy Constructor";
	}
	Complex add(Complex c)
	{
		Complex temp;
		temp.real = this->real + c.real;
		temp.imaginary = this->imaginary + c.imaginary;
		return temp;
	}
	Complex subtract(Complex c)
	{
		Complex temp;
		temp.real = this->real - c.real;
		temp.imaginary = this->imaginary - c.imaginary;
		return temp;
	}
	Complex multiply(Complex c)
	{
		Complex temp;
		temp.real = (this->real * c.real) - (this->imaginary*c.imaginary);
		temp.imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);
		return temp;
	}
	Complex divide(Complex c)
	{
		Complex temp;
		temp.real = ((real * c.imaginary) + (imaginary * c.real)) / ((pow(c.real, 2)) + (pow(c.imaginary, 2)));
		temp.imaginary= ((imaginary * c.real) - (real * c.imaginary)) / ((pow(c.real, 2)) + (pow(c.imaginary, 2)));
		return temp;
	}
	Complex conjugate()
	{
		Complex temp;
		temp.real = real;
	    temp.imaginary = -imaginary;
	    return temp;
	}
	void print()
	{
		if(imaginary>=0)
		  cout << this->real << "+" << this->imaginary << "i";
		else 
			cout << real << imaginary << "i";
	}
	void setReal(double r)
	{
		this->real = r;
	}
	double getReal()
	{
		return real;
	}
	void setImaginary(double i)
	{
		this->imaginary = i;
	}
	double getImaginary()
	{
		return imaginary;
	}

};