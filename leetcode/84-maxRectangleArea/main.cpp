#include <iostream>
#include <vector>
using namespace std;

vector<int> zhan;

int maxRectangleArea(const vector<int> &height) {
    vector<int> zhan;
    int sum = 0;

    // 加一个哨兵高度0在末尾，确保最后所有元素能被处理
    vector<int> heights = height;
    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++) {
        // 维护单调递增栈
        while (!zhan.empty() && heights[zhan.back()] > heights[i]) {
            int hindex = zhan.back();
            zhan.pop_back();

            int width;
            if (zhan.empty()) {
                width = i;
            } else {
                width = i - zhan.back() - 1;
            }

            int area = heights[hindex] * width;
            if (area > sum)
                sum = area;
        }
        zhan.push_back(i);
    }

    return sum;
}

int main()
{
    vector<int> heights{2,1,2};
    //heights.push_back(0);
    //int x;
    // if(cin.peek() == '\n')
    //     return -1;
    // while (cin >> x)
    // {
    //     heights.push_back(x);
    //     if (cin.peek() == '\n') break; // 如果下一个字符是换行符，就停止
    // }
    // heights.push_back(0);

    int area = maxRectangleArea(heights);
    cout << "max area is " << area << endl;

}