#include <iostream>
using namespace std;

// 友元
// C++ 的类通过 private / protected 实现封装,外部代码无法访问私有成员
// 友元是一种受控的"破例"机制:类可以声明某个函数或某个类是自己的"朋友",被声明的朋友可以直接访问该类的私有和保护成员


// 友元的三种形式

// 1.友元函数
class Box {
private:
    int width;
public:
    Box(int w) {
        width = w;
    }

    friend void print_width(const Box& b); // 声明友元
};

void print_width(const Box& b) {
    cout << "width:" << b.width << endl; // 可以直接访问私有成员
}

// 2.友元类 一个类的所有成员函数都能访问另一个类的私有成员
class Engine; // 声明类

class Car {
private:
    int speed = 100;
    friend class Engine; // Engine是Car的友元类
};

class Engine {
public:
    void print_speed(Car& c) {
        cout << c.speed << endl;
    }
};

// 3.友元成员函数
class People; // 声明类

class Man {
public:
    void boost(People& p);    // 仅声明
    void check(People& p);
};

class People {
private:
    int speed = 10;
    friend void Man::boost(People& p); // 只有boost是友元
};

void Man::boost(People& p) {
    p.speed += 1;
}
// Man::check 不能访问 c.speed




















