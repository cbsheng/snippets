// shared_ptr.swap
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Foo {
public:
	string s_;
	Foo(string s) : s_(s) { cout << s_ << " Created\n"; }
	~Foo() { cout << s_ << " Destoryed\n"; }
	string print() { return s_; }
};

int main()
{
	shared_ptr<Foo> p1(new Foo("Foo1"));
	shared_ptr<Foo> p2(new Foo("Foo2"));
	
	cout << "p1->print() = " << p1->print() << "   p1.use_count() = " << p1.use_count() << endl;
	cout << "p2->print() = " << p2->print() << "   p2.use_count() = " << p2.use_count() << endl;
	
	p1.swap(p2);
	
	cout << "p1->print() = " << p1->print() << "   p1.use_count() = " << p1.use_count() << endl;
	cout << "p2->print() = " << p2->print() << "   p2.use_count() = " << p2.use_count() << endl;
	
	/*
	Foo1 Created
	Foo2 Created
	p1->print() = Foo1   p1.use_count() = 1
	p2->print() = Foo2   p2.use_count() = 1
	p1->print() = Foo2   p1.use_count() = 1
	p2->print() = Foo1   p2.use_count() = 1
	Foo1 Destoryed
	Foo2 Destoryed
	*/
}