#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;



int lengthOfLongestSubstring(string s) {
    queue<char> st;
    unordered_set<char> set;
    vector<int> res(3,0);           //第一个储存j，第二个储存i，第三个储存j-i


    for(int j = 0,i = 0;i<s.length(); i++)
      {
          if(set.empty())
          {
            set.insert(s[i]);
            st.push(s[i]);
              if((i-j+1)>res[2]) res[2] = i-j+1;
          }
          else
            {

              if(set.count(s[i])){
                  while (set.count(s[i]) && j<=i && !set.empty())
                  {
                    j++;
                    set.erase(st.front());
                    st.pop();
                  }
              }
              for(int i = i+1;i<s.length();i++)
                {
                }



              set.insert(s[i]);

              st.push(s[i]);
              if((i-j+1)>res[2]) res[2] = i-j+1;
            }
      }
    return res[2];


}

int main()
{
    //

    int res = lengthOfLongestSubstring("bba");
    cout << res << endl;





    return 0;
}
