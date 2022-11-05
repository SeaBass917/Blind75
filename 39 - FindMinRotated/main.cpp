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
    int findMin(vector<int>& nums) {
        int iL = 0; 
        int iR = nums.size()-1;
        int iM = iR/2;
        
        // Edge case, when the list is fully sorted
        if(nums[iL] < nums[iR]) return nums[iL];
        
        // Otherwise binary search until left and right pointer are adjacent
        // The right pointer will be the min value
        while(1 < iR - iL){
            if(nums[iL] < nums[iM]){
                iL = iM;
            }
            else{
                iR = iM;
            }
            iM = (iL+iR)/2;
        }
        
        return nums[iR];
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> in = {1};
        cout << "Expected 1 found: " << solver.findMin(in) << endl;
    }

    {
        vector<int> in = {2,1};
        cout << "Expected 1 found: " << solver.findMin(in) << endl;
    }
    
    {
        vector<int> in = {7,8,9,2,3,4,5,6};
        cout << "Expected 2 found: " << solver.findMin(in) << endl;
    }
    
    {
        vector<int> in = {1202,3200,5000000,56,97,123,250};
        cout << "Expected 56 found: " << solver.findMin(in) << endl;
    }
    
    {
        vector<int> in = {1202,3200,5000000,56,97,123};
        cout << "Expected 56 found: " << solver.findMin(in) << endl;
    }
    
    {
        vector<int> in = {11,13,15,17};
        cout << "Expected 11 found: " << solver.findMin(in) << endl;
    }
    
    return 0;
}
