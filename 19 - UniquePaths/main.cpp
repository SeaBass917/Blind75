#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
/*
[S][ ][ ][ ]
[ ][ ][ ][ ]
[1][1][1][*]

[10][6][3][1]
[4][3][2][1]
[1][1][1][0]
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp_row(n, 0);
        dp_row[n-1] = 1;
        for(int j = 0; j < m; j++){
            for(int i = n - 1; 0 <= i; i--){
                dp_row[i] += (i+1 < n)? dp_row[i+1]: 0;
            }
        }
        return dp_row[0];
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    cout << "Expected 1 => " << solver.uniquePaths(1,1) << endl;
    cout << "Expected 2 => " << solver.uniquePaths(2,2) << endl;
    cout << "Expected 10 => " << solver.uniquePaths(3,4) << endl;
    
    return 0;
}
