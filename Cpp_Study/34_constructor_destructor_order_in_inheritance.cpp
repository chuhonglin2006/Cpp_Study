#include <iostream>
#include <string>
using namespace std;

// 继承中的构造函数与析构函数顺序

// 创建子类对象时，先构造基类，再构造派生类；销毁时顺序相反


class Base {
public:
	Base() {
		cout << "Base构造函数调用" << endl;
	}

	~Base() {
		cout << "Base析构函数调用" << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << "Derived的造函数调用" << endl;
	}

	~Derived() {
		cout << "Derived的构函数调用" << endl;
	}
};


// 基类构造函数有参数时 必须在派生类的初始化列表中显式调用
class Person {
public:
	string name;
	Person (string n) {
		name = n;
	}
};

class Student : public Person {
public:
	int id;
	Student(string n,int i) : Person(n) { // 调用基类构造函数
		id = i;
	}
};

// 同名成员 隐藏
// 派生类中定义了与基类同名的成员 会隐藏基类的所有同名成员包括重载版本
class Base_1 {
public:
	void show() {
		cout << "Base_1::show" << endl;
	}
	void show(int x) {
		cout << "Base_1::show(int)" << endl;
	}
};

class Derived_1 :public Base_1 {
public:
	void show() {
		cout << "Derived_1::show" << endl;
	}
};


int main() {
	Derived d;

	Student s_1("小米",1);
	cout << s_1.id << " " << s_1.name << endl;

	// 同名成员 隐藏
	Derived_1 d_1;
	d_1.show(); // Derived_1::show
	// d_1.show(10); // 编译错误 Base 的 show(int) 被隐藏了
	d_1.Base_1::show(10); // 用作用域运算符访问基类版本

	return 0;
}