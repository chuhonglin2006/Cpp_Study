#include <iostream>
#include <list>
#include <string>
using namespace std;

// 双向链表 每个节点除了存数据 还保存两个指针 分别指向前一个和后一个节点


int main() {
    // 定义一个双向链表
    list<int> lst = {10,20,30};
    cout << lst.size() << endl; // 获取当前元素个数
    cout << lst.front() << endl; // 获取首元素
    cout << lst.back() << endl; // 获取末尾元素
    // 循环遍历
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;


    lst.clear(); // 清空链表
    lst.push_front(40); // 在头部添加元素
    lst.push_back(50); // 在尾部添加元素
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;

    lst.pop_front(); // 删除头部元素
    lst.pop_back(); // 删除尾部元素
    cout << lst.size() << endl;

    // 自定义类型
    struct Student {
        Student(string n,int a) {
            name = n;
            age = a;
        }
        string name;
        int age;
    };
    list<Student>students;
    students.push_back({"aym",18});
    students.emplace_back("tom",20); // 需要构造函数
    students.emplace_back(Student{"mike",19}); // 不需要构造函数


    // 插入与删除
    list<int>li = {1,2,3};
    // 获取第一个元素的迭代器
    auto it = li.begin();
    cout << *it << " ";
    cout << *++it << " "; // 指向下一个元素 需要解引用
    cout << *++it << endl; // 再次指向下一个元素

    li.insert(next(li.begin(),0),5); // 在指定元素前插入5
    for (int x : li) {
        cout << x << " ";
    }
    cout << endl;

    li.erase(next(li.begin(),0)); // 删除指定元素

    li.erase(next(li.begin(),1),next(li.begin(),2)); // 删除区间内的元素[x,y)
    for (int x : li) {
        cout << x << " ";
    }
    cout << endl;

    li.remove(20); // 删除所有值为20的元素
    li.remove_if([](int x) {return x % 2 == 0;}); // 按条件删除


    // 其它操作
    list<int> a = {3,1,2};
    list<int> b = {9,8};

    a.sort(); // 排序链表
    a.reverse(); // 反转链表
    a.unique(); // 去除相邻的重复元素
    a.splice(a.end(),b); // 将b所有节点拼接到a末尾 不拷贝 O(1)
    a.merge(b); // 合并两个链表

    return 0;
}