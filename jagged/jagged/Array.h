#pragma once
#include<iostream>
using namespace std;
template< typename T>
class Array
{
	template<typename R>
	friend ostream& operator <<(ostream&, const Array<R>& ref);
	template<typename R>
	friend istream& operator >>(istream&, const Array<R>& ref);
	T* data;
	int  capacity;
	int isValidIndex(int index) const;
public:
	Array(int = 0);
	Array(const Array < T >&);
	~Array();
	T& operator [] (int i);
	const T& operator [] (int i) const;
	int getCapacity() const;
	void reSize(int newCap);
	Array<T>& operator = (const Array <T>& ref);

};
template< typename T>
int Array<T>::isValidIndex(int index) const
{
	return index >= 0 && index < capacity;
}
template< typename T>
Array<T>::Array(int size)
{
	if (size <= 0)
	{
		data = nullptr;
		capacity = 0;
		return;

	}
	capacity = size;
	data = new T[capacity];
	cout << "constructor" << endl;
}
template< typename T>
Array<T>::Array(const Array <T>& ref) :Array()
{
	if (ref.data == nullptr)
	{
		cout << "copy constructor" << endl;
		return;

	}
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		data[i] = ref.data[i];
	}
	cout << "copy constructor" << endl;
}
template< typename T>
Array<T>::~Array()
{
	if (data)
		delete[] data;
	data = 0;
	//cout << endl;
	cout << "destructor" << endl;
}
template< typename T>
T& Array<T>:: operator [] (int i)
{
	if (isValidIndex(i))
		return data[i];
	else
	{
		cout << "out of bound access" << endl;
		exit(0);
	}
}
template< typename T>
const T& Array<T>:: operator [] (int i) const
{
	if (isValidIndex(i))
		return data[i];
	else
	{
		cout << "out of bound access" << endl;
		exit(0);
	}
}
template< typename T>
int Array<T>::getCapacity() const
{
	return capacity;
}
template< typename T>
void Array<T>::reSize(int newcap)
{
	if (newcap <= 0)
	{
		this->~Array();
		return;
	}
	T* ptr = new T[newcap];
	if (capacity > 0)
	{
		int size = capacity < newcap ? capacity : newcap;
		for (int i = 0; i < size; i++)
		{
			ptr[i] = data[i];
		}
	}
	this->~Array();
	capacity = newcap;
	data = ptr;
}
template< typename T>
Array<T>& Array<T>:: operator = (const Array <T>& ref)
{
	if (this == &ref)
		return *this;
	if (ref.capacity == 0)
	{
		data = nullptr;
		capacity = 0;
		return *this;
	}
	this->~Array();
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < ref.capacity; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
template<typename T>
ostream& operator <<(ostream& out, const Array<T>& ref)
{
	for (int i = 0; i < ref.capacity; i++)
	{
		out << ref.data[i];
	}
	return out;
}
template<typename R>
istream& operator >>(istream& in, const Array<R>& ref)
{
	for (int i = 0; i < ref.capacity; i++)
	{
		in >> ref.data[i];
	}
	return in;
}
