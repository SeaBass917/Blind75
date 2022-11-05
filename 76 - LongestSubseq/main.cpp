#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;

// [0, 1, 2, 4]
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.size();
        const int m = text2.size();
        vector<vector<int>> dp_table(n+1, vector<int>(m+1, 0));

        for(int i = n-1; 0 <= i; i--){
            const auto c1 = text1[i];
            auto &dp_row = dp_table[i];
            auto &dp_row_next = dp_table[i+1];
            for(int j = m-1; 0 <= j; j--){
                const auto c2 = text2[j];
                
                dp_row[j] = (c1 == c2)? 1 + dp_row_next[j+1] : max( dp_row_next[j], dp_row[j+1] );
            }   
        }

        return dp_table[0][0];
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        cout << "Expected 3 found: " << solver.longestCommonSubsequence("ashjsdbksjdc", "abc") << endl;
    }

    {
        cout << "Expected 3 found: " << solver.longestCommonSubsequence("abashjsdbksjdc", "abc") << endl;
    }

    {
        cout << "Expected 6 found: " << solver.longestCommonSubsequence("axbxcxaxbxcdef", "abcdef") << endl;
    }

    {
        cout << "Expected 4 found: " << solver.longestCommonSubsequence("alalala", "aaaa") << endl;
    }

    return 0;
}
