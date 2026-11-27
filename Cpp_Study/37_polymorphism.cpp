#include <iostream>
using namespace std;

// 多态

// 多态就是同一个接口 不同的行为 用基类的指针或引用调用函数时实际执行的是对象真实类型的版本


//       类型	          绑定时机	          实现方式
// 静态多态（编译期）	编译时决定调用哪个函数	函数重载、模板
// 动态多态（运行期）	运行时决定调用哪个函数	继承 + 虚函数
// 多态的三个必要条件
// 有继承关系
// 基类函数是 virtual，子类重写（override）了它
// 通过基类的指针或引用调用

class Animal {
public:
	virtual void speak() { cout << "动物叫" << endl; }
	virtual ~Animal() {}
};

class Dog : public Animal {
public:
	void speak() override { cout << "汪汪" << endl; }
};

class Cat : public Animal {
public:
	void speak() override { cout << "喵喵" << endl; }
};

class Cow : public Animal {
public:
	void speak() override { cout << "哞哞" << endl; }
};

// 这个函数不关心具体是什么动物
void makeSound(Animal &a) {
	a.speak();
}

int main() {
	Dog d; Cat c; Cow w;
	makeSound(d);
	makeSound(c);
	makeSound(w);

	return 0;
}