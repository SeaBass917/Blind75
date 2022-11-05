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

class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            const auto _and = (a & b);
            a ^= b;
            // NOTE: LeetCode considered Left-shift on neg val an error
            // so we make negatives safe.
            b = (0 <= _and)? _and << 1 : (_and & INT32_MAX) << 1;
        }
        return a;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        cout << "Expected 0 found: " << solver.getSum(1, -1) << endl;
    }

    {
        cout << "Expected 50 found: " << solver.getSum(20, 30) << endl;
    }

    {
        cout << "Expected 3 found: " << solver.getSum(1, 2) << endl;
    }

    {
        cout << "Expected 2 found: " << solver.getSum(1, 1) << endl;
    }

    {
        cout << "Expected 1 found: " << solver.getSum(0, 1) << endl;
    }

    {
        cout << "Expected -1 found: " << solver.getSum(0, -1) << endl;
    }

    {
        cout << "Expected 30 found: " << solver.getSum(15, 15) << endl;
    }

    return 0;
}
