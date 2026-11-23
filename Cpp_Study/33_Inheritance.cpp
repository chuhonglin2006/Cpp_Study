#include <iostream>
#include <string>
using namespace std;

// 类的继承

// 基本用法
class Animal { // 父类
public:
	string name;
	void eating() {
		cout << name << "正在吃东西" << endl;
	}
};

class Dog : public Animal { // 子类 公有继承
public:
	void brak() {
		cout << name << "汪汪叫" << endl;
	}
};


// 三种访问权限与三种继承方式

// 类成员有三种访问权限：
// 权限	     类内部	派生类	类外部
// public	  ✅     ✅	     ✅
// protected  ✅	 ✅	     ❌
// private	  ✅	 ❌	     ❌

class Base {
public:
	int a = 1;
protected:
	int b = 2;
private:
	int c = 3;
};

class Derived : public Base {
public:
	void show() {
		cout << a << endl;   // ✅ public 成员
		cout << b << endl;   // ✅ protected 成员，子类可访问
		// cout << c;        // ❌ private 成员，子类不能访问
	}
};

// 三种继承方式的区别
/* public: 父类public -> public protected → protected
 * protected: 父类public → protected  protected → protected
 * private: 父类public → private protected → private
 * 父类的 private 成员 无论哪种继承方式 派生类都不能直接访问
 */

int main() {
	// 类的基本使用
	Dog d;
	d.name = "aaa"; // 继承自Animal类
	d.eating(); // 继承自Animal类
	d.brak(); // Dog自己的方法

	// 三种访问权限与三种继承方式
	Derived der;
	der.show();

	return 0;
}