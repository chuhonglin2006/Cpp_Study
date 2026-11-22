#include <iostream>
using namespace std;

// 虚函数
// 在基类成员函数前加 virtual 这个函数就成为虚函数
// 它告诉编译器调用这个函数时 不要在编译期写死 等到运行时再根据对象的真实类型决定


class Base {
public:
	void normal() { // 普通函数
		cout << "Base::normal" << endl;
	}

	virtual void vfunc() { // 将成员函数声明为虚函数，使其支持动态绑定
		cout << "Base::vfunc" << endl;
	}
};

class Derived : public Base {
public:
	void normal() {
		cout << "Derived::normal" << endl;
	}

	void vfunc() override  { // 这个函数重写父类中的虚函数
		cout << "Derived::vfunc" << endl;
	}
};

int main() {
	Derived d;
	Base* p = &d; // 子类对象可以被当作父类对象使用

	p->normal();
	p->vfunc();

	return 0;
}






















