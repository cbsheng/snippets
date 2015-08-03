// shared_ptr general usage
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

int main()
{
	shared_ptr<Foo> p1(new Foo("Foo"));
	//todo
}