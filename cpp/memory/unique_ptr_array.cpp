// unique_ptr for array
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Foo {
public:
	string s_;
	Foo(string s) : s_(s) { cout << s_ << " Created\n"; }
	~Foo() { cout << s_ << " Destoryed\n"; }
	string Get() { return s_;}
};

int main()
{
	const int SIZE = 5;
	unique_ptr<Foo[]> f(new Foo[SIZE]);
	for (int i = 0; i < SIZE; ++i)
		cout << f[i].Get() << endl;
	
	/*
	Foo Created
	Foo Created
	Foo Created
	Foo Created
	Foo Created
	Foo
	Foo
	Foo
	Foo
	Foo
	Foo Destroyed
	Foo Destroyed
	Foo Destroyed
	Foo Destroyed
	Foo Destroyed
	*/
}