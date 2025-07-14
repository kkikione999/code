#include <iostream>
#include <variant>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int dis = 0;
        int i = 0, j = 0;
        int left = 0, right = n-1;
        int up = 0, down = n-1;
        for (int p = 1; p <= n*n; p++) {
            if (dis == 0) {
                matrix[i][j] = p;
                j++;
                if (j > right) {
                    j--;
                    dis++;
                    up++;
                    i++;
                }
            }else if (dis == 1) {
                matrix[i][j] = p;
                i++;
                if (i >down) {
                    i--;
                    j--;
                    dis++;
                    right--;
                }
            }else if (dis == 2) {
                matrix[i][j] = p;
                j--;
                if (j < left) {
                    j++;
                    i--;
                    down--;
                    dis++;
                }
            }else if (dis == 3) {
                matrix[i][j] = p;
                i--;
                if (i < up) {
                    dis = 0;
                    i++;
                    j++;
                    left++;
                }
            }
        }
        // for (int t = 0; t < n; t++) {
        //     for (int k = 0; k < n; k++) {
        //         cout << matrix[t][k] << "\t";
        //     }
        //     cout << endl;
        // }
        return matrix;

    }

};

int main() {
    Solution s;
    s.generateMatrix(1);
    return 0;

}