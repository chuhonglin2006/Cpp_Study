#include <iostream>
using namespace std;

// 引用的基本使用



int main() {
	// 引用可以为一个已经存在的变量起一个别名 可以通过别名来访问那个变量
	int number = 100;

	// 创建引用
	int &ref = number;

	cout << number << " " << ref << endl;

	ref = 10; // 修改ref 就是修改number

	cout << number << " " << ref << endl;


	return 0;
}