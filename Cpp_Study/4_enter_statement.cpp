#include <iostream>
using namespace std;

// 输入语句

int main() {
	// 在使用输入语句之前 要先定义变量来存放输入的值
	int number;

	cout << "请输入一个数字:";
	// 输入语句 cin
	cin >> number;

	cout << "你输入了:" << number;

	return 0;
}