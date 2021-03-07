#include<iostream>
#include "ComplexNo.h"
using namespace std;
int main()
{
	Complex number1;
	Complex number2;
	Complex result;
	number1.setReal(-1);
	number1.setImaginary(2);
	number2.setReal(3);
	number2.setImaginary(4);
	
	/*number1.print();
	cout << endl;
	number2.print();
	result=number1.subtract(number2);
	cout << endl;
	result.print();
	cout << endl;
	result.conjugate();*/
	
	result = number1.multiply(number2);
	result.print();
}
