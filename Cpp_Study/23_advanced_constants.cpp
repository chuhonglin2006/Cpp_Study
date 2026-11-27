#include <iostream>
using namespace std;

// 常量进阶 常量指针 指针常量 常量引用


int main() {

	// 常量指针 : 指针可以修改指向 但是不能通过指针修改指向的值
	int num_1 = 100,num_2 = 200;
	const int *ptr = &num_1;

	cout << *ptr << endl;

	// *ptr = 300; // 不能通过指针修改 num_1

	ptr = &num_2; // 可以修改指针的指向

	cout << *ptr << endl;



	// 指针常量 : 指针本身不能修改指向 但可以通过指针修改所指向的值
	int num_3 = 100,num_4 = 200;
	int *const p = &num_3;

	cout << *p << endl;

	*p = 999; // 可以修改值

	cout << num_3 << endl;

	// p = &num_4; // 不能修改指针的指向



	// 常量指针常量 : 都不能修改
	int num_5 = 100,num_6 = 200;
	const int *const pt = &num_5;

	cout << *pt << endl;

	// *pt = 300; // 不能修改目标值

	// pt = &num2; // 不能修改指针指向



	// 常量引用 : 可以读取原变量 但是不能通过引用修改原变量
	int num = 100;
	const int &ref = num;

	cout << ref << endl;

	// ref = 200; // 不能修改原量

	num = 300;
	cout << ref << endl;

	return 0;
}