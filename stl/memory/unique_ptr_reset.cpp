// unique_ptr.reset
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Foo {
public:
	string s_;
	Foo(string s) : s_(s) { cout << "Foo Created\n"; }
	~Foo() { cout << s_ << " Destroyed\n"; }
	string Get() { return s_;}
};

int main()
{
	unique_ptr<Foo> f(new Foo("Foo"));
	unique_ptr<Foo> f1(new Foo("Another Foo"));
	//cout << f->Get() << endl;
	
	//f.reset(new Foo("new Foo"));
	//f.reset(f.get());  //you can try
	f.reset(f1.release());
	cout << f->Get() << endl;
	
	if (nullptr != f) {
		cout << "unique_ptr f also Valid After reset()\n";
		cout << f->Get() << endl;
	} else {
		cout << "unique_ptr f is equal to nullptr After reset()\n";
	}
	
	/*
	Foo Created
	Foo Created
	Foo Destroyed
	Another Foo
	unique_ptr f also Valid After reset()
	Another Foo
	Another Foo Destroyed
	*/
}