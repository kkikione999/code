#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>


using namespace std;
class Solution {
public:
  stack<char> q;
  vector<string> result;

  vector<string> restoreIpAddresses(string s) {

      return result;
  }

  //head指向第一个有效数字
  // index <= 2
  // string[head] 到 string[head + index] <= 255
  //



  // times == 4
  //12345 678 : length == 8   8-4-1
  //
  string trans(string s, int head, int index)
  {
    string res;
    res = s.substr(head, index+1);
    int i = stoi(res);
    if (i > 255) return "";
    return res;
  }
//123 456 789
  void dfs(string s, int head, int index, int times) {
    if (times == 4) {
      if((s.length()-head-1) <= 3){
        //if s[head] -- s[s.length()-1] 这个数比 255大
        string temp = s.substr(head, s.length()-head);
        if (stoi(temp) <= 255)
        {
          for (int i = 0; i+head < s.length(); i++)
          {
            q.push(s[i+head]);
          }
          q.push('\0');
        }
        //入栈这个数
        //q放到result.push_back();
        //添加‘\0’
       }



        return;
    }


      //tims++的时候就要把 '.'放进队列里

    }
  };

int main() {

  string s = "1234567";
  string res = trans(s,0,2);
  cout << res << endl;



}
