#include <iostream>
#include <vector>

class Myclass {

public:
	Myclass(int a) : mx{ a } {}
	int f1(int a)
	{
		std::cout << "int Myclass:f1(int)\n";
		return a + mx + 10;
	}

	int f2(int a)
	{
		std::cout << "int Myclass:f2(int)\n";
		return a + mx + 20;
	}

	int f3(int a)
	{
		std::cout << "int Myclass:f3(int)\n";
		return a + mx + 30;
	}

	int f4(int a)
	{
		std::cout << "int Myclass:f4(int)\n";
		return a + mx + 40;
	}

private:
	int mx;
};


using MyclassFptr = int (Myclass::*)(int);

int main()
{
	MyclassFptr a[] = { &Myclass::f1, &Myclass::f2, &Myclass::f3, &Myclass::f4 };
	Myclass mx{ 10 };

	for (auto fptr : a) {
		std::cout << (mx.*fptr)(5) << '\n';
		//std::cout << std::invoke(fptr, mx, 5)<< '\n';

	}
}
