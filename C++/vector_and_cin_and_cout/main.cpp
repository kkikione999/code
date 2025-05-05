#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

// this page include the usage of cin/cout and vector operation

int main() {
    // int a, b;
    // cin >> a >> b;              // 读取两个整数，遇到空格或换行分隔
    // cout << "Sum = " << a + b;  // 输出字符串和数值
    // cout << endl;
    // cout << "sum = " << a << "+" << b;

    // string s;
    // getline(cin, s);
    // cout << s << endl;
    vector<int> v1;
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v3(6);
    vector<int> v4(10,7);
    // for (int i = 0; i<10;i++) {
    //     cout << v2[i]<<endl;
    // }
    // cout << v1.size()<<endl;
    //
    // cout << v2.size()<<endl;
    // cout << "v2.at(1) :" <<v2.at(1)<<endl;
    //
    // cout << v3.size()<<endl;
    // cout << v4.size()<<endl;
    // v2[2] = 999;
    // for (int i = 0; i < v2.size(); i++) {
    //     cout << v2[i] << endl;
    // }
    for (int i = 0; i < v3.size(); i++) {
        cin >> v3[i];
    }
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << endl;
    }
    cout << "current v3 size " <<v3.size() << endl;
    v3.push_back(999);
    cout << "push_back v3 size " <<v3.size() << endl;
    v3.pop_back();
    cout << "post-pop v3 size " <<v3.size() << endl;
    v3.insert(v3.begin()+3, 999);
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << endl;
    }

    // cout << v1.empty()<<endl;
    // cout << v2.empty()<<endl;
    // cout << v2.end() << endl;


    return 0;
}
