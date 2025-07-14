#include <iostream>
#include <random>
#include <string>
using namespace std;
void swap(string &a,int front, int rear){
    char temp;
    for (int i = front, j = rear; i <= (front + rear)/2; i++,j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void reverse(string &str,int k){
    int end = 0, len = str.length();
    int front = 0, rear = 0;
    while(end <= len){
        //反转前k个
        if (end + 2*k <= len) {
            end += 2*k;
            rear = front + k - 1;
        }
        //反转前k个
        else if (end + 1*k <= len) {
            end = len;
            rear = front + k - 1;
        }
        else if (end == len)break;
        //少于k个全部反转
        else if (end + k > len) {
            end = len;
            rear = end -1;
        }
        swap(str, front, rear);
        front = end;
    }
    cout << str << endl;
}

void reverse2(string &str,int k) {
    int front = 0, rear = str.size()-1;

    while (front <= rear) {
        if (front + 2*k-1 <= rear) {

        }
    }

}



int main(){

    string str;
    cin >> str;
    reverse(str,4);
    return 0;

}