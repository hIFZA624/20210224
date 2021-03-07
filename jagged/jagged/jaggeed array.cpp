#include<iostream>
#include<stdarg.h>
#include "Array.h"
using namespace std;
template<typename T>
class jaggedArray
{
	template<typename R>
friend ostream& operator <<(ostream&, const jaggedArray<T>&);
template<typename R>
friend istream& operator >>(istream&, const jaggedArray<T>&);

Array<T>** data;
int rows;
int isValidIndex(int) const;
public:
	jaggedArray(int, ...);
	jaggedArray(const jaggedArray<T>&);
	Array<T>& operator[](int);
	const Array<T>& operator[](int) const;
	int getRows() const;
	int getCoulumns(int) const;
	~jaggedArray();
	void reSize(int);
};
template<typename T>
int jaggedArray<T>::isValidIndex(int index) const
{
	return index >= 0 && index < rows;
}

template<typename T>
jaggedArray<T>::jaggedArray(int argCount, ...)
{
	if (argCount == 0)
	{
		data = nullptr;
		rows = 0;
		return;
	}
	va_list argList;
	va_start(argList, argCount);
	rows = argCount;
	data = new Array<T> * [rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = new Array<T>(va_arg(argList, int));
	}
	va_end(argList);
	cout << "jagged array constructor" << endl;
}
template<typename T>
jaggedArray<T>::jaggedArray(const jaggedArray<T>& ref)
{
	if (ref.data == nullptr)
	{
		data = nullptr;
		rows = 0;
		return;
	}
	rows = ref.rows;
	data = new Array<T>*[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i] = ref.data[i];
	}
}
template<typename T>
Array<T>& jaggedArray<T>::operator[](int i)
{
	if (isValidIndex(i))
		return *(data[i]);
	exit(0);
}
template<typename T>
const Array<T>& jaggedArray<T>::operator[](int i)const
{
	if (isValidIndex(i))
		return *(data[i]);
	exit(0);
}
template<typename T>
int jaggedArray<T>::getRows() const
{
	return rows;
}
template<typename T>
int jaggedArray<T>::getCoulumns(int index) const
{
	if (isValidIndex(index))
		return data[index]->getCapacity();
	exit(0);
}
template<typename T>
jaggedArray<T>::~jaggedArray()
{
	for (int i = 0; i < rows; i++)
		delete data[i];
	delete[] data;
	data = nullptr;
}
template<typename T>
ostream& operator <<(ostream& out, const jaggedArray<T>& ref)
{
	for (int i = 0; i < ref.rows; i++)
	{
		for (int j = 0; j < ref.getcoulumns(i); j++)
		{
			out << ref.data[i][j];
		}
	}
	return out;
}
template<typename T>
void jaggedArray<T>::reSize(int newSize)
{
	for (int i = 0; i < rowsi++)
	{
		if (this == data[i])
		{
			Array::reSize(newSize);
			return;
		}
	}
	delete data[];
	Array<T>** temp = new Array<T> *[newSize];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = data[i];
	}
	for (int i = this->rows-1; i < newSize; i++)
	{
		data[i] = new Array<T>(0);
	}

}
template<typename T>
istream& operator >>(istream& in, const jaggedArray<T>& ref)
{
	for (int i = 0; i <ref.rows; i++)
	{
		for (int j = 0; j < ref.getcoulumns(i); j++)
		{
			in>> ref.data[i][j];
		}
	 }
	return in;
}


