#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> magazineMap;
    for (char c : magazine) {
        magazineMap[c]++;
    }
    for (char c : ransomNote) {
        if (magazineMap[c] == 0) {
            return false;
        }
        else magazineMap[c]--;
    }
    return true;
}
int main() {
    cout << canConstruct("aasdab", "aaabasd")<<endl;
    return 0;
}