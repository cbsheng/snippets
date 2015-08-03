// unique_ptr.swap
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
	unique_ptr<Foo> f1(new Foo("f1"));
	unique_ptr<Foo> f2(new Foo("f2"));
	
	cout << "f1 : " << f1->Get() << endl;
	cout << "f2 : " << f2->Get() << endl;
	
	f1.swap(f2);
	
	cout << "f1 : " << f1->Get() << endl;
	cout << "f2 : " << f2->Get() << endl;
	
	/*
	Foo Created
	Foo Created
	f1 : f1
	f2 : f2
	f1 : f2
	f2 : f1
	f1 Destroyed
	f2 Destroyed
	*/
}