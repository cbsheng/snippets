// shared_ptr.unique
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

void fun(shared_ptr<Foo> ptr)
{
	cout << "in fun()\n";
	cout << "ptr.use_count() = " << ptr.use_count() << endl;
	if (ptr.unique())
		cout << "ptr is unique\n";
	else
		cout << "ptr is not unique\n";
		
	cout << "quit fun()\n";
}

int main()
{
	shared_ptr<Foo> p1(new Foo("Foo"));
	
	cout << "p1.use_count() = " << p1.use_count() << endl;
	fun(p1);
	cout << "p1.use_count() = " << p1.use_count() << endl;
	if (p1.unique()) 
		cout << "p1 is unique\n";
	else
		cout << "p1 is not unique\n";
	
	/*
	Foo Created
	p1.use_count() = 1
	in fun()
	ptr.use_count() = 2
	ptr is not unique
	quit fun()
	p1.use_count() = 1
	p1 is unique
	Foo Destoryed
	*/
}