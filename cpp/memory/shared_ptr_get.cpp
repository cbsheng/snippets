// shared_ptr.get
// You need to go easy on with shared_ptr.get
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Foo {
public:
	string s_;
	Foo(string s) : s_(s) { cout << s_ << " Created\n"; }
	~Foo() { cout << s_ << " Destoryed\n"; }
	void print() { cout << s_ << endl; }
};

void fun(Foo *ptr)
{
	ptr->print();
	//delete ptr; // you can try
}

int main()
{
	shared_ptr<Foo> p1(new Foo("Foo"));
	fun(p1.get());
	
	/*
	Foo Created
	Foo
	Foo Destoryed
	*/
}