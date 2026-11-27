#include <iostream>
using namespace std;

// 构造函数与析构函数

class Student {
public:
	// 析构函数 作用:创建对象时自动调用,用来初始化成员变量
	// 函数名和类名相同 没有返回值 可以重载

	// 默认构造函数 没有参数
	Student() {
		name = "Unknown";
		age = 0;
	}

	// 带参数的构造函数
	Student(string n,int a) {
		name = n;
		age = a;
	}

	void show_info() {
		cout << "nane:" << name << " " << "age:" << age << endl;
	}


	// 析构函数 作用:对象销毁时自动调用 用来做清理工作
	// 名字是 ~类名 没有参数、没有返回值 一个类只有一个析构函数,不能重载

	~Student() {
		cout << "析构函数调用" << endl;
	}

private:
	string name;
	int age;
};

// 调用顺序 构造:按创建的先后顺序 析构:和构造相反(后创建的先销毁)

int main() {
	Student s_1; // 创建一个对象 调用的是无参数的构造函数
	Student s_2("小明",20); // 带上参数 调用的是有参数的构造函数
	s_1.show_info();
	s_2.show_info();
	return 0;
}