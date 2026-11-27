#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 动态数组

// vector 是可以自动扩容的数组 普通数组长度固定 vector 可以随时添加 删除元素,内存由它自己管理


int main() {
    // 创建动态 vector
    vector<int>a; // 空
    vector<int>b(5); // 5个元素 都为0
    vector<int>c(5,100); // 5个元素 都为 100
    vector<int>d = {1,2,3,4,5}; // 初始化列表
    vector<int>e(d); // 拷贝 d


    // 添加和删除元素
    vector<int>v;
    v.push_back(10); // 添加一个元素
    v.push_back(20);
    v.push_back(30);
    v.pop_back(); // 删除最后一个元素

    // 访问元素
    cout << v[0] << endl; // 访问第一个元素
    cout << v.at(1) << endl; // 访问元素 越界会抛出异常
    cout << v.front() << endl; // 访问第一个元素
    cout << v.back() << endl; // 访问最后一个元素


    // 容器大小
    cout << v.size() << endl; // 获取当前元素个数
    cout << v.empty() << endl; // 判断是否为空
    cout << v.capacity() << endl; // 查看已分配的内存(元素个数 不是字节数)

    // 当 size 超过 capacity
    // vector 会申请更大的内存(通常是2倍)把旧数据搬过去 如果提前知道大概数量 可以用 reserve 避免反复扩容
    vector<int>f;
    f.reserve(1000); // 预留空间 size依然是0
    cout << f.capacity() << endl;


    // 迭代器
    vector<int>ages = {17,18,19,20};
    // 获取容器中第一个元素的迭代器
    auto it = ages.begin();
    cout << *it << endl; // 解引用迭代器 获取值


    // 遍历的三种方式
    vector<string>names = {"tom","amy","bob","tom"};
    // 1.下标
    for (size_t i = 0;i < names.size();i++) {
        cout << names[i] << " ";
    }
    cout << endl;
    // 2.范围for
    for (const string& name:names)
        cout << name << " ";
    cout << endl;
    // 3.迭代器
    for (auto it = names.begin();it != names.end();++it) {
        cout << *it << " ";
    }
    cout << endl;
    // 在循环中修改元素 需要使用引用
    vector<int>g = {1,2,3};
    for (int& x : g) { // 依次遍历 vector v 中的每一个元素，并使用引用 x 代表当前元素
        x = x * 2;
    }


    // 插入和删除元素(中间位置)
    vector<int>h = {1,2,3,4,5};

    v.insert(v.begin() + 1,15); // 在下标1处插入 15
    v.erase(v.begin() + 2); // 删除下标2
    v.erase(v.begin(),v.begin() + 2); // 删除[0,2)
    v.clear(); // 清空



    // 二维 vector
    vector<vector<int>>arr = {
        {1,2,3,4,5},
        {6,7,8,9,0}
    };

    cout << arr[1][1] << endl;
    for (int x = 0;x < arr.size();x++) {
        for (int y = 0;y < arr[0].size();y++) {
            cout << arr[x][y] << " ";
        }
    }
    cout << endl;



    // 存放自定义类型
    struct Student {

        Student(string n,int a) {
            name = n,
            age = a;
        }

        string name;
        int age;
    };
    vector<Student>students;
    students.push_back({"tom",18});
    students.emplace_back("amy",20);  // 直接在容器里构造,更高效  1.需要添加构造函数
    students.emplace_back(Student{"amy",20}); // 2.不用添加构造函数
    return 0;
}