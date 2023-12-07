#include <functional>

class Nec {
public:
	int foo(int);
	int bar(int);
	int baz(int);
};

using necfunc = int (Nec::*)(int);

void gf(Nec& nec, necfunc nfp, int val)
{
	auto ret1 = (nec.*nfp)(val);
	auto ret2 = std::invoke(nfp, nec, val);
	//...
}

int main()
{
	Nec mynec;
	gf(mynec, &Nec::bar, 10);
}
