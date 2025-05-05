#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int minSubArrayLen(const int target, vector<int>& nums) {
  int j = 0, sum = 0;
  int minlen = 100001;
  for (int i = 0; i < nums.size(); i++ ){
      if(sum < target){
        sum += nums[i];
      }
      while(sum >= target && j<=i){
        sum -= nums[j];
		if(minlen > i-j+1) minlen = i-j+1;
        j++;
      }
      if(minlen == 1) break;
    }
    if (minlen == 100001) return 0;
    return minlen;
}

int main ()
{
    string line;
    getline(cin, line); // 读入整行
    cout << "你输入的是：" << line << endl;

    stringstream ss(line);
    vector<int> arr;
    
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    cout << minSubArrayLen( 7 , arr) << endl;


    return 0;

}
