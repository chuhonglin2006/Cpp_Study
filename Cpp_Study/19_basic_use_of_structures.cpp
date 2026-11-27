#include <iostream>
#include <string>
using namespace std;


// 结构体的基本使用


// 结构体的定义
struct Student {
	string name;
	int age;
	double score;
};

int main() {
	// 结构体初始化

	Student s_1{.name = "小明",.age = 20,.score = 88.5};
	Student s_2 = {.name = "小红",.age = 21,.score = 94.5};

	cout << s_1.name << " " << s_1.age << " " << s_1.score << endl;
	cout << s_2.name << " " << s_2.age << " " << s_2.score << endl;


	// 成员函数 结构体中也能定义函数
	struct Add {
		double number_1,number_2;
		double add_func() const {  // const 保证不修改成员
			return number_1 + number_2;
		}
	};

	Add a = {.number_1 = 10.5,.number_2 = 1.5};
	cout << a.add_func() << endl; // 调用这个结构体中的函数


	// 构造函数与默认值
	struct Point {
		int x = 0; // 默认成员初始值
		int y = 0;


		Point() { // 构造函数 创建结构体自动执行
			x = 10;
			y = 20;
		}

		Point(int num_1,int num_2) { // 带参数的构造函数
			x = num_1;y = num_2;
		}


	};
	Point v;
	Point r(20,30);

	cout << v.x << " " << v.y << endl;
	cout << r.x << " " << r.y << endl;

	return 0;
}