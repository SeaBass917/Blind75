#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n+1);
        int msb_curr = 0;
        int msb_next = 1;
        out[0] = 0;
        for(unsigned k = 1; k <= n; k++){
            if(msb_next == k){
                msb_next = k << 1;
                msb_curr = k;
            }
            out[k] = (1 + out[k % msb_curr]);
        }
        return out;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto soln = solver.countBits(2);
        cout << "Expected [0,1,1], computed: [ ";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
    }

    {
        auto soln = solver.countBits(0);
        cout << "Expected [0], computed: [ ";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
    }

    return 0;
}
