#include <iostream>
using namespace std;

// this指针

// this 指针是 C++ 里每个非静态成员函数都隐含拥有的一个指针 它指向调用该函数的那个对象


// 区分同名的参数和成员变量
class Persion {
public:
	void set_age(int age) {
		this->age = age; // 左边是成员变量,右边是参数
	}
private:
	int age;
};

// 返回对象自身,实现链式调用(把多个方法调用连着写在一行里)
class Count {
public:
	Count add_n(Count &c) {
		this->n += c.n;
		return *this; // 返回这个对象本身
		// 拷贝了一份新的数据 返回
	}

	void print_n() {
		cout << n << endl;
	}

private:
	int n = 10;
};

int main() {
	Count c;
	c.add_n(c).add_n(c).add_n(c); // 链式调用
	c.print_n();
	return 0;
}


























