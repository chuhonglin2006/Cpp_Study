#include <iostream>
using namespace std;

// 深拷贝与浅拷贝

// 浅拷贝 : 编译器提供的简单的赋值操作
// 深拷贝 : 在堆区重新申请空间 进行拷贝操作


class Person {
public:
	Person(int age,int height) {
		this->age = age;

		this->height = new int(height); // 在堆区申请一块空间
		// 浅拷贝把指针的地址拷贝了过去 析构函数释放了两次

		cout << "Person的有参构造函数调用" << endl;
	}

	// 深拷贝
	Person (const Person &p) {
		this->age = p.age;
		this->height = new int(*p.height); // 重新申请一块空间
		// 深拷贝就是重新申请一块内存空间 赋值过去
		// 浅拷贝就是普通的赋值

		cout << "Person拷贝构造函数调用" << endl;
	}

	~Person() {
		// 释放申请的空间
		if (height != nullptr) {
			delete height;
			height = nullptr;
		}

		cout << "Person的析构函数调用" << endl;
	}

	void print_info() {
		cout << age << " " << *height << endl;
	}

private:
	int age;
	int *height;
};


int main() {
	Person p_1(18,160);
	p_1.print_info();

	Person p_2(p_1); // 编译器提供的拷贝构造函数 浅拷贝 问题: 堆区内存重复释放
	p_2.print_info();
	return 0;
}