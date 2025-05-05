#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;




int main() {
    system("chcp 65001"); // 设置控制台编码为 UTF-8
    // std::string str = "hello world";
    // std::unordered_map<char, int> freq;  // 哈希表：键是字符，值是出现次数
    //
    // // 统计每个字符出现次数
    // for (char c : str) {
    //     std::cout << c << "\t";
    //     if (c != ' ') {  // 忽略空格
    //         freq[c]++;
    //     }
    // }
    //
    // // 输出每个字符及其出现次数
    // for (auto pair : freq) {
    //     std::cout << "字符 '" << pair.first << "' 出现了 " << pair.second << " 次。" << std::endl;
    // }
    // unordered_map<string, int> goods_price_map;
    // string goods_name;
    // int goods_price;
    // for (int i = 0; i < 3; i++) {
    //     cout << "Enter goods name: ";
    //     cin >> goods_name;
    //     cout << "Enter goods price: ";
    //     cin >> goods_price;
    //     cout << endl;
    //     goods_price_map[goods_name] = goods_price;
    // }
    //pair相当于c语言里面的结构团体
    // for (auto pair : goods_price_map) {
    //     cout << pair.first << " " << pair.second << endl;
    // }
    unordered_map<string , int> freq;
    freq["apple"] = 5;
    freq.insert({"banana", 7});
    freq.emplace("cucumber", 22);
    for (auto p : freq) {
        cout << "name: " << p.first << "  price: " << p.second << endl;
    }
    auto it = freq.begin();
    // if (it != freq.end())
    //     cout << "find" << endl;
    // else
    //     cout << "can't find" << endl;

    for (; it != freq.end(); ++it) {
        cout << it->first << "  " << it->second << endl;
    }
    return 0;
}
