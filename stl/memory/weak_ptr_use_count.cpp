//weak_ptr.use_count
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
	weak_ptr<Foo> w1;
	{
		auto p1 = make_shared<Foo>("Foo");
		auto p2 = p1;
		auto p3 = p2;
		
		w1 = p1;
		//w1->print();
		cout << "w1.use_count() = " << w1.use_count() << endl;
	}
	
	//cout << "w1.use_count() = " << w1.use_count() << endl;
	
	/*
	Foo Created
	w1.use_count() = 3
	Foo Destoryed
	*/
}