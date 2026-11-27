#include <memory>
#include <iostream>
using namespace std;


//shared_ptr
// shared_ptr 是共享所有权的智能指针
// 多个 shared_ptr 可以指向同一块堆内存 靠 引用计数 记录有几个主人 最后一个主人销毁时才释放内存

void func_1() {
	auto a = make_shared<int>(10); // 引用计数 = 1
	cout << a.use_count() << endl; // 获取当前引用计数

	{
		auto b = a; // 拷贝 计数 = 2
		cout << a.use_count() << endl;
		cout << *b << endl;
	} // 作用域结束 b销毁 计数 = 1

	cout << a.use_count() << endl;
} // a销毁 计数 = 0 内存释放

// 与make_unique的区别 : 可以拷贝
auto a = make_shared<int>(10);
auto b = a;
auto c = a; // 只要还有一个 shared_ptr 活着 内存就不会被释放

int* raw = new int(10);
shared_ptr<int> d(raw);
// shared_ptr<int> e(raw); // 两个独立的引用计数 会重复释放
// 当 d 离开作用域 它以为自己是最后一个所有者 释放内存 但是 e离开时 也认为自己是最后一个所有者 再次释放

shared_ptr<int> e = a; // 正确写法

// shared_ptr循环引用的问题 : 两个对象互相持有对方的 shared_ptr，计数永远降不到 0，造成内存泄漏

struct B;

struct A {
	shared_ptr<B> b;
	~A() {
		cout << "A销毁" << endl;
	}
};

struct B {
	shared_ptr<A> a;
	~B() {
		cout << "B销毁" << endl;
	}
};

void test() {
	auto a = make_shared<A>(); // A计数 = 1
	auto b = make_shared<B>(); // B计数 = 1
	a->b = b; // B计数 = 2  通过 A 对象内部的 b 成员，让它也共享外面的 b 所管理的 B 对象。
	b->a = a; // A计数 = 2
} // a、b 销毁，各自计数 -1 → 都还是 1，永远不为 0
  // 没有输出"A 销毁""B 销毁"，发生泄漏


// weak_ptr
// weak_ptr 是 弱引用 指向 shared_ptr 管理的对象 但不增加引用计数 不拥有对象
void func_2() {
	auto sp = make_shared<int>(10);
	weak_ptr<int> wp = sp; // 不增加计数
	cout << sp.use_count() << endl;

	// weak_ptr 不能直接解引用，要先用 lock() 转成 shared_ptr
	if (auto p = wp.lock()) { // 对象还活着，返回有效的 shared_ptr
		cout << *p << endl;
	} else {
		cout << "对象已被释放" << endl; // 对象已销毁，返回空
	}
	// lock() 的作用 检查对象是否还在 在的话临时拿到一个 shared_ptr 计数 +1 用完自动 -1

	cout << wp.expired() << endl; // 对象是否已被释放（true 表示已销毁）
	cout << wp.use_count() << endl; // 目前有多少个 shared_ptr 指向该对象
	wp.reset(); // 放弃观察
}


int main() {
	func_1();
	func_2();
	return 0;
}