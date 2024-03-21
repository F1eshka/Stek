#include <iostream>
using namespace std;

template<typename T>

class Steck

{
	T* arr = new T[capacity];
	unsigned int size = 0;
	unsigned int capacity = 12;

public:

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	bool IsFull() const
	{
		return false;
	}

	int GetCount() const
	{
		return size;
	}

	void Push(T value)
	{
		if (size == capacity)
		{
			T* temp = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}

		arr[size++] = value;
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			--size;
			return arr[size];
		}
		else
		{
			throw "Steck is empty";
		}
	}
	~Steck()
	{
		delete[] arr;
	}
};

int main()
{
	Steck<int> st; 

	for (int i = 0; i < 100000; i++)
	{
		st.Push(rand() % 100);
	}
	cout << "All good!\n";

	for (int i = 0; i < 100000; i++)
	{
		cout << st.Pop() << "\n";
	}
}