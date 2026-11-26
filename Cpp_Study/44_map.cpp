#include <iostream>
#include <map>
#include <string>
using namespace std;

// map : 元素存在一颗始终保持平衡的二叉树 每次比较key 决定向左还是向右查找 所以查找是O(log n) 中序遍历天然有序

int main() {

    // 定义一个map
    map<string,int> m;

    // 插入方式
    m["apple"] = 1;
    m.insert({"data",2});
    m.insert(make_pair("elder",3));
    m.emplace("fig",4);

    // 遍历map
    for (auto& [key,value] : m) {
        cout << key << ":" << value << endl;
    }

    // 查找元素
    cout << m["apple"] << endl;
    cout << m["orange"] << endl; // []访问不存在的元素会被插入
    cout << m.size() << endl; // 获取当前元素个数

    // find查找
    auto it = m.find("apple");
    if (it != m.end()) {
        cout << it->first << ":" << it->second << endl; // first表示key second表示value
    } else {
        cout << "未找到" << endl;
    }

    // 判断是否存在
    if (m.count("apple")) {
        cout << "存在" << endl;
    } else {
        cout << "不存在" << endl;
    }


    // 删除元素
    map<string, int> ma = {{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}};
    cout << ma.erase("a") << endl; // 按key删除 返回删除的个数

    auto ite = ma.find("b");
    if (ite != ma.end()) { // 按迭代器删除
        ma.erase(ite);
    }

    m.erase(ma.begin(),ma.end()); // 按区间删除

    m.clear(); // 清空

    return 0;
}