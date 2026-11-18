#include <iostream>
#include <string>
using namespace std;

// 指针的基本用法



// 指针函数 函数传递的参数 函数里面修改的是副本 但是使用指针可以修改调用者的变量
void change(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main() {
	int a = 10;

	int *p = &a; // 指针里面存的是另一个变量的地址  p存的是a的地址
	cout << p << endl;

	// & 取地址符 得到变量的地址
	// * 解引用符 通过地址访问、修改所指向的值

	*p = 20; // 通过指针修改变量值
	cout << a << endl;


	// 指针的初始化
	int *pp = nullptr; // 暂时不使用的指针要赋空指针 不然指向随机值(野指针)
	if (pp != nullptr) { // 使用前先检查
		cout << *pp << endl;
	} else {
		cout << "空指针" << endl;
	}


	// 指针与数组
	int arr[] = {1,2,3,4,5};
	int *ppp = arr; // 数组名在大多情况下会退化为指向首元素的指针 等价于 &arr[0]
	cout << *ppp << endl;
	cout << *(ppp + 1) << endl; // 向后移动一位
	cout << ppp[2] << endl; // 等价于 *(p + x)
	// 指针算数 p + 1移动的是一个元素的大小不是一字节
	for (int *q = arr;q < arr + 5;q++) {
		cout << *q << " ";
	}
	cout << endl;

	// 指针函数
	int x = 1,y = 2;
	cout << "修改前:" << "x:" << x << " " << "y:" << y << endl;
	change(&x,&y);
	cout << "修改后:" << "x:" << x << " " << "y:" << y << endl;


	// 指针与结构体
	struct Student {
		string name;
		int age;
	};
	Student s_1 = {.name = "小明",.age = 20};
	Student *s = &s_1;

	cout << "name:" << s->name << " " << "age:" << s->age << endl; // 等价于(*s).name/age

	return 0;
}