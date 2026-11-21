#include <iostream>
using namespace std;

// 运算符重载

// 运算符重载就是让我们自己定义的类或结构体 也能够使用 C++ 原本的运算符 并且规定这些运算符具体执行什么操作


class Person {
public:
	int age = 0;

	Person() = default; // 让编译器生成默认构造函数

	Person(int age) {
		this->age = age;
	}

	// 重载 + 号运算符
	Person operator+(Person &p) { // operator要重载的运算符
		Person temp;
		temp.age = this->age + p.age; // 内部具体怎么重载 是要自己定义的
		return temp;
	}

	// 重载 -  号运算符
	Person operator-(Person &p) {
		Person temp;
		temp.age = this->age - p.age;
		return temp;
	}

	// 重载 == 运算符
	bool operator==(Person &p) {
		return this->age == p.age;
	}

	// 重载 != 运算符
	bool operator!=(Person &p) {
		return this->age != p.age;
	}

	// 重载 < > 运算符
	bool operator<(const Person &p) {
		return this->age < p.age;
	}
	bool operator>(const Person &p) {
		return this->age > p.age;
	}

	void print_age() {
		cout << age << endl;
	}


	// 重载 ++ 和 --

	// 前置++:先自增,再返回自身的引用
	Person& operator++() {
		this->age++;
		return *this;
	}

	// 后置++:先保存旧值,再自增,返回旧值
	Person operator++(int) {   // int 只是用来区分前置/后置的占位参数
		Person old = *this;
		this->age++;
		return old;
	}
	// --和++完全相同
};


int main() {
	Person p_1(18);
	Person p_2(30);
	Person p_3 = p_1 + p_2;
	p_3.print_age();

	Person p_4 = p_1 - p_2;
	p_4.print_age();

	cout << (p_1 == p_2) << endl;
	cout << (p_1 > p_2) << endl;
	cout << (p_1 < p_2) << endl;

	++p_1;
	Person old = p_2++;
	p_1.print_age();
	p_2.print_age();
	old.print_age();


	return 0;
}




































