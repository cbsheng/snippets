// unique_ptr.get
// You need to go easy on with get()
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

void fun(Foo *ptr)
{
	delete ptr;
}

int main()
{
	unique_ptr<Foo> f(new Foo("Foo"));
	//cout << f->Get() << endl;
	
	Foo *p = f.get();
	cout << p->Get() << endl;
	
	//fun(p); //you can try
	if (nullptr != f) {
		cout << "unique_ptr f also Valid After get()\n";
		cout << f->Get() << endl;
	} else {
		cout << "unique_ptr f is equal to nullptr After get()\n";
	}
	
	/*
	Foo Created
	Foo
	Foo
	unique_ptr also Valid After get()
	Foo
	Foo Destroyed
	*/
}