// unique_ptr general usage
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Foo {
public:
	string s_;
	Foo(string s) : s_(s) { cout << "Foo Created\n"; }
	~Foo() { cout << "Foo Destroyed\n"; }
	string Get() { return s_;}
};

void fun(unique_ptr<Foo> ptr)
{
	cout << "in fun()\n";
	cout << ptr->Get() << endl;
}

int main()
{
	unique_ptr<Foo> f(new Foo("Foo"));
	//cout << f->Get() << endl;
	
	unique_ptr<Foo> f1(move(f));
	//fun(move(f1));
	{
		unique_ptr<Foo> f2(move(f1));
	}
	
	if (nullptr != f) {
		cout << "unique_ptr f also Valid\n";
		cout << f->Get() << endl;
	} else {
		cout << "unique_ptr f is equal to nullptr\n";
	}
	
	/*
	Foo Created
	Foo Destroyed
	unique_ptr f is equal to nullptr After get()
	*/
}