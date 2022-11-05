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
class Solution {
public:
    map<int, int> solns;
    int climbStairs(int n) {
        
        // If we're at the base case or we've seen this before
        if(n <= 2) return n;
        if(solns.find(n) != solns.end()) return solns[n];
        
        // Otherwise recurse
        const int _sum = climbStairs(n-1) + climbStairs(n-2);
        
        // Cache soln and return
        solns[n] = _sum;
        return _sum;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    cout << "Expected 1 => " << solver.climbStairs(1) << endl;
    cout << "Expected 2 => " << solver.climbStairs(2) << endl;
    cout << "Expected 3 => " << solver.climbStairs(3) << endl;
    cout << "Expected 610 => " << solver.climbStairs(14) << endl;
    cout << "Expected 1836311903 => " << solver.climbStairs(45) << endl;
    
    return 0;
}
