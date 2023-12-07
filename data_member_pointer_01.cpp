#include <iostream>
#include <functional>

struct A {
	int mx{};
	//...
};


int main()
{
	A ax;

	std::cout << "ax.mx = " << ax.mx << ;

	int A::* ptr = &A::mx;
	ax.*ptr = 100;
	std::cout << "ax.mx = " << ax.mx << ;

	std::invoke(ptr, ax) = 200;
	std::cout << "ax.mx = " << ax.mx << ;
}
