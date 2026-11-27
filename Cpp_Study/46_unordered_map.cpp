#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// unordered_map 是一个基于哈希表（Hash Table）实现的键值对容器，可以通过 key 快速查找 value
// 底层使用哈希表 元素没有排序保证 平均查找、插入、删除为 O(1)

int main() {
    // 定义一个 unordered_map
    unordered_map<string,int> score = {
        {"tom",90},{"lily",80},
        {"mike",89},{"bob",96}
    };
    cout << score["tom"] << endl;


    // 插入元素
    score["amy"] = 100; // 如果key不存在就会创建一个新的键值对 如果key已经存在就会修改对应的value
    score.insert({"lisa",94}); // 如果key已经存在不会覆盖原来的value
    score.emplace("tonly",85); // emplace() 会直接在容器中构造元素

    // 查找元素
    auto it = score.find("tom");
    if (it != score.end()) {
        cout << it->first << " = " << it->second << endl;
    } else {
        cout << "没找到" << endl;
    }
    // 不要使用 scores["tom"] 来判断元素是否存在。 因为如果 tom 不存在，[] 会自动插入一个新元素

    // 删除元素
    score.erase("tom");

    auto ite = score.find("tonly");
    if (ite != score.end()) {
        score.erase(ite);
    } // 也可以通过迭代器删除

    // score.clear(); // 清空

    // 判断元素是否存在
    if (score.count("amy")) {
        cout << "存在" << endl;
    } else {
        cout << "不存在" << endl;
    }

    cout << score.size() << endl; // 获取当前元素个数

    return 0;
}