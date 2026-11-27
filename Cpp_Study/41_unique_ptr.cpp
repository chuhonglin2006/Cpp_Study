#include <iostream>
#include <memory>
using namespace std;

// unique_ptr 是独占所有权的智能指针 同一时刻 只有一个 unique_ptr 拥有这块堆内存 它离开作用域时自动 delete


void func_1() {
	unique_ptr<int> p = make_unique<int>(10);
	cout << &p << " " << *p << endl;
	*p = 20;
	cout << &p << " " << *p << endl;
} // p离开作用域自动销毁 不需要手动释放


void func_2() {
	class Student {
	public:
		void hello() {
			cout << "hello" << endl;
		}
	};
	auto s = make_unique<Student>();
	// 访问对象时使用 ->
	s->hello();
}

// 核心特点 : 不能拷贝 只能移动
// 独占 意味着不能有两个 unique_ptr 指向同一块内存，所以拷贝被禁用
void func_3() {
	auto a = make_unique<int>(10);
	// auto b = a; // 编译错误 不能拷贝

	auto b = std::move(a); // 将所有权从a转移给b
	// 移动后 a 就变为空了 b拥有这块内存
	if (a == nullptr) {
		cout << "a已为空" << endl;
	}
	cout << *b << endl;
}


// 常用成员函数
void func_5() {
	auto p = make_unique<int>(10);

	int* raw = p.get(); // 返回裸指针 不转移 不delete
	cout << raw << endl;
	p.reset(); // 释放当前内存 p 变为空
	p = make_unique<int>(5); // 释放当前内存 改为管理新的
	cout << *p << endl;

	int* q = p.release(); // 放弃所有权 返回裸指针 不会delete 需要自己手动管理
	cout << *q << endl;
	delete q;
	q = nullptr;
}


// 作为返回值
unique_ptr<int> creat() {
	return make_unique<int>(10);  // 返回的是一个临时的 unique_ptr，所有权随返回值交出去
	// return 一个局部的 unique_ptr或临时对象 时编译器会自动按移动处理
}
void test() {
	auto p = creat(); // p拿到了所有权
	cout << *p << endl;
} // p离开作用域 自动销毁


// 传参
void take(unique_ptr<int> p) { // 接管所有权
	cout << *p << endl;
} // 函数结束 p被释放

// 如果函数只是使用对象 不需要拿走所有权 传裸指针或者引用更合适
void use(int* p) { // p 是普通的裸指针
	cout << *p << endl;
	// 借出去的裸指针不能 delete，也不要保存起来长期使用
}  // 函数结束，只是这个指针变量 p 消失了，它指向的内存不受影响





int main() {
	func_1();
	func_2();
	func_3();
	func_5();

	auto p = make_unique<int>(10);
	use(p.get());
	take(std::move(p)); // 传参时要使用move传所有权


	return 0;
}



