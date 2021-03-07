#include<iostream>
using namespace std;
void print1(char ch,int n)
{
	if (n == 1)
	{
		cout << ch;
		return;
	} 
	print1(ch, n - 1);
	cout << ch;
}
void printPattern1(char ch, int n)
{
	if (n == 1)
	{
		cout << ch;
		return;
	}
	print1(ch, n);
	cout << endl;
	printPattern1(ch,n-1);
}
void print2(int n)
{
	if (n == 1)
	{
		cout << endl;
		cout << n << ".";
		return;
	}
	print2(n - 1);
	cout << n << ".";
}
void printPattern2(int n)
{
	if (n == 1)
	{
		cout << n;
		return;
	}
    printPattern2(n - 1);
	print2(n - 1);
	cout << n;
}

void printChar(char ch, int n)
{
	if (n == 0)
		return;
	cout << ch;
	printChar(ch, n - 1);
	
}
void printSquares(int n)
{
	if (n == 1)
	{
		cout << n << "  ";
		return;
	}
	if (n % 2 != 0)
		cout << n * n << "  ";
	printSquares(n - 1);
	if (n % 2 == 0)
		cout << n * n << "  ";
}
int quotient(int divisor, int dividend)
{
	bool negResult = false;
	if (dividend < 0)
	{
		dividend = -dividend;
		if (divisor < 0)
			divisor = -divisor;
		else
			negResult = true;
	}
	else if (divisor < 0)
	{
		divisor = -divisor;
		negResult = true;
	}
	if (dividend < divisor)
		return  0;
	int rem = 0;
	rem = dividend - divisor;
	int count= 1+ quotient(divisor, rem);
	if (negResult)
		count = -count;
	return count;
}
template<typename T>
int findFirstOccurance(const T arr[], const int N, const T key)
{
	if (N == 1)
	{
		if (arr[N-1] == key)
			return N - 1;
		else 
		    return -1;
	}
	int result=findFirstOccurance(arr,N-1,key);
	if (result == -1)
	{
		if (arr[N-1] == key)
			return N - 1;
	}
	return result;
}
void printZigZag(int* arr, int start, int end)
{
	if (start == end)
	{
		cout << arr[start];
		return;
	}
	if (start == end - 1)
	{
		cout << arr[start] << "  " << arr[end] << "  ";
		return;
	}
	cout << arr[start] << "  " << arr[end] << "  ";
	printZigZag(arr, start+1, end-1);
}
int main()
{
	//printPattern(4);
	//printChar('a', 5);
	int a[6] = { 7,1,9,3,5,2 };
	cout<<findFirstOccurance(a, 7, 4);
	//printSquares(1);
	//printZigZag(a, 0, 5);
	//printPattern1('@',10);
	//cout << quotient(-6,36);
}