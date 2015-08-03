// unique_ptr.release
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

int main()
{
	unique_ptr<Foo> f(new Foo("Foo"));
	cout << f->Get() << endl;
	
	Foo *p = f.release();
	cout << p->Get() << endl;
	
	if (nullptr != f) {
		cout << "unique_ptr f also Valid After release()\n";
		cout << f->Get() << endl;
	} else {
		cout << "unique_ptr f is equal to nullptr After release()\n";
	}
	
	//delete p; //u can try
	
	/*
	Foo Created
	Foo
	Foo
	unique_ptr is equal to nullptr After release
	*/
}