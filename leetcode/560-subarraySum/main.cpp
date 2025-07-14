#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:

};


int main() {
	for (int i = 0; i<30 ; i++) {

		double val;
		val = sin(-M_PI/2 + 2*M_PI/60*i)/2 + 0.5;
		cout << val << ", \t";
		if (i%5 == 0) cout << endl;

	}
	exit(0);

}