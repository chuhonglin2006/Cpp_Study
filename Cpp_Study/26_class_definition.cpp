#include <iostream>
using namespace std;

// 类的基本使用


// 类的定义
class Student { // 定义一个类
public: // 公有 : 外部可以访问
	void print_hello() {
		cout << "Hello" << endl;
	}

private: // 私有 : 只有类内部可以访问
	void print_world() {
		cout << "World" << endl;
	}
};


int main() {
	Student s_1; // 创建一个对象
	s_1.print_hello(); // 可以调用公有方法等
	// s_1.print_world(); // 私有的无法访问

	return 0;
}