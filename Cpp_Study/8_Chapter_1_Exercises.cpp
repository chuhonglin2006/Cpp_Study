#include <iostream>
using namespace std;

// 第一章练习题

// 1.编写一个C++程序，它显示您的姓名和地址
void print_info() {
	cout << "My name is wangjia" << endl;
	cout << "My address is Hubei" << endl;
}

// 2.编写一入C++程序它要求用户输入一个以longs为单位的距离，然后将它转换为码
void change_long() {
	long longs;
	cout << "请输入long的值:";
	cin >> longs;
	long result = longs / 220;
	cout << "转换结果:" << result << endl;
}

// 4·编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月
void year_to_mouth() {
	int age;
	cout << "请输入age:";
	cin >> age;
	int result = age * 12;
	cout << "转换结果:" << result << endl;
}


int main() {
	print_info();
	change_long();
	year_to_mouth();
	return 0;
}