class Nec {
public:
	static int foo(int);
	int bar(int);
	int baz(int);
	int func(int);
};

using mftype = int (Nec::*)(int);

int main()
{
	int (*fp)(int) = &Nec::foo;
	//int (*mfp)(int) = &Nec::bar; //invalid
	int (Nec:: * mfp)(int) = &Nec::bar;
	mftype fptr = &Nec::baz;

	int (Nec:: * fpar[])(int) = { &Nec::bar, &Nec::baz, &Nec::func };
	mftype fpa[] = { &Nec::bar, &Nec::baz, &Nec::func };
	decltype(&Nec::baz) fpa2[] = { &Nec::bar, &Nec::baz, &Nec::func };
}
