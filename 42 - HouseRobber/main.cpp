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
    int rob(vector<int>& nums) {
        
        // Store the max 1 house behind, 
        // and 2 houses behind, respectively 
        int max_1 = 0;
        int max_2 = 0;
        
        // Run through the array, 
        // Counting the maximum we can rob
        for(const auto &num : nums){
            const int max_val = max(max_1, max_2 + num);
            max_2 = max_1;
            max_1 = max_val;
        }
        
        return max(max_1, max_2);
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> in = {1,2,3,1};
        cout << "Expected 4 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {2,7,9,3,1};
        cout << "Expected 12 found: " << solver.rob(in) << endl;
    }
    
    {
        vector<int> in = {};
        cout << "Expected 0 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {1};
        cout << "Expected 1 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {13};
        cout << "Expected 13 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {2,0,2};
        cout << "Expected 4 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {13, 25, 123, 43, 12, 4, 6, 43, 231, 346, 2, 1, 1, 0, 0, 12, 0};
        cout << "Expected 862 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {1,1,1,1,1,1,1,1,1,0,1,0,1,1,10,11,1,0,1,1,1,0,1,0,1,1,10,11,1,0,1,1,1,1,1,1,0,1,0,1,1,10,11,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,10,11,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,10,11,1,0,1,1};
        cout << "Expected 167 found: " << solver.rob(in) << endl;
    }

    return 0;
}
