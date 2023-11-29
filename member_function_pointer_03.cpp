#include <iostream>
#include <functional>

class Myclass {

public:
	Myclass(int a) : mx{ a } {}
	void set(int x)
	{
		std::cout << "Myclass::set\n";
		mx = x;
	}

	void print()const
	{
		std::cout << "mx = " << mx << '\n';
	}
private:
	int mx;
};

int main()
{
	//void (Myclass::*fptr)(int) = &Myclass::set;
	auto fptr = &Myclass::set;
	Myclass x{ 20 };
	x.print();
	(x.*fptr)(30);
	x.print();
	std::invoke(&Myclass::set, x, 40);
	x.print();
}
