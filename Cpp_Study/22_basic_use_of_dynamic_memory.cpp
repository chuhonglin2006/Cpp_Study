#include <iostream>
using namespace std;

// 动态内存的基本使用

/* 程序里的内存主要分两块:
 *            栈（stack）      	     堆（ heap）
 *	分配方式  	自动	            手动（new / malloc）或智能指针
 *	释放时机	离开作用域自动释放	         你决定何时释放
 *  大小	    较小（通常几 MB）       	很大，受系统内存限制
 *	典型用途	局部变量	        大数组、大小运行时才知道的数据、需要跨函数存活的对象
 */

int main() {
	// new与delete
	int *p = new int; // 分配 未初始化
	int *q = new int(10); // 分配并初始化为10

	cout << *q << endl;
	*q = 100; // 修改q的值

	delete q; // 释放
	delete p;
	q = nullptr; // 防止悬空指针
	p = nullptr;


	// 动态数组
	int *arr = new int[5]; // 申请一个int类型 长度为5的数组

	delete[] arr; // 释放动态数组 delete后面要加[]

	arr = nullptr; // 置空

	int *a = new int[5]{1,2,3,4,5}; // 动态数组初始化 大括号中不填元素初始化为0

	int length = 5; // new返回指针 丢失长度信息
	for (int index = 0;index < length;index++) {
		cout << a[index] << " ";
	}

	delete[] a;
	a = nullptr;



	return 0;
}