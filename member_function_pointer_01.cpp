class Nec {
public:
	void foo();
	void bar()const;
};

int main()
{
	auto fpx = &Nec::foo;
	void (Nec:: * fpx_)() = &Nec::foo;

	auto fpy = &Nec::bar;
	void (Nec:: * fpy_)()const = &Nec::bar;
}
