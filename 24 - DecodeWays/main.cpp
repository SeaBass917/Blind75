#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        table.clear();
        n = s.length();
        return recurse_linear_mem(s);
    }
private:
    int n;
    map<int, int> table;
    int recurse_linear_mem(const string s, const int i = 0){

        if(table.find(i) != table.end()) return table[i];
        
        if(i == n) {
            return 1;
        }
        const char c_0 = s[i];
        
        if(c_0 == '0') return 0;
        
        int cnt = 0;
        if(i+1 < n && (c_0 == '1' || (c_0 == '2' && s[i+1] <= '6'))){
            cnt += recurse_linear_mem(s, i+2);
        }
        cnt += recurse_linear_mem(s, i+1);

        table[i] = cnt;
        return cnt;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    cout << "Expected 2 => " << solver.numDecodings("12") << endl;
    cout << "Expected 3 => " << solver.numDecodings("226") << endl;
    cout << "Expected 0 => " << solver.numDecodings("06") << endl;
    cout << "Expected 1836311903 => " << solver.numDecodings("111111111111111111111111111111111111111111111") << endl;
    
    return 0;
}
