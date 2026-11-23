#include <iostream>
#include <string>
using namespace std;

// 拷贝构造函数

class Person {
public:
	Person(string name,int age) {
		// 构造函数
		this->name = name,this->age = age;
	}

	Person(const Person &p) {
		// 拷贝构造函数   const 类名 &参数
		// 将传入的对象的所有属性 拷贝到另一个对象身上
		age = p.age,name = p.name;
	}

	void print_info() {
		// 输出信息
		cout << "name:" << name << " " << "age:" << age << endl;
	}

private:
	int age;
	string name;
};

// 2.值传递的方式给函数传参数值
void do_work(Person p) {
	p.print_info();
}

// 3.值方式返回局部对象
Person do_work_2() {
	Person p_x("小米",10);
	return p_x; // 函数执行完了 p_x会被释放掉 会创建一个新的对象来返回
}


int main() {
	Person p_1("小明",20); // 调用普通构造函数
	p_1.print_info();

	Person p_2(p_1); // 调用拷贝构造函数 将p_1所有属性拷贝到p_2上面
	p_2.print_info();



	// 拷贝构造函数调用时机

	// 1.使用一个已经创建完毕的对象来初始化一个新对象
	Person p_3 (p_1);
	p_3.print_info();

	// 2.值传递的方式给函数传参数值
	do_work(p_1); // 将p_1传入时会拷贝出一份新的副本

	// 3.值方式返回局部对象
	Person px = do_work_2();
	px.print_info();

	return 0;
}

