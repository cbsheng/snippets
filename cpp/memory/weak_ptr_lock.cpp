//weak_ptr.lock
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Son;

class Father {
public:
	string name_;
	shared_ptr<Son> son_;
	Father(string name) : name_(name) { cout << name_ << " Created\n"; }
	~Father() { cout << name_ << " Destoryed\n"; }
	void MySon();
};

class Son {
public:
	string name_;
	weak_ptr<Father> father_;
	Son(string name) : name_(name) { cout << name_ << " Created\n"; }
	~Son() { cout << name_ << " Destoryed\n"; }
	void MyFather() {
		auto father = father_.lock();
		if (father)
			cout << father->name_ << " is MyFather\n"; 
		else
			cout << "father is gone\n";
	}
};

void Father::MySon()
{ 
	cout << son_->name_ << " is MySon\n";
}

int main()
{
	shared_ptr<Son> s(new Son("S"));
	{
		shared_ptr<Father> f(new Father("F"));
		
		f->son_ = s;
		s->father_ = f;
		
		f->MySon();
	}
	s->MyFather();
	
	/*
	S Created
	F Created
	S is MySon
	F Destoryed
	father is gone
	S Destoryed
	*/
}