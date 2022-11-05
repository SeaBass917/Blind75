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
    vector<int> productExceptSelf(vector<int>& nums) {

        const int n = nums.size();
        
        // Output vector to be build int sweeps
        vector<int> prod_out(n, 1);
        
        // FIrst compute a running list of products
        // to the right ->
        int prod = 1;
        unsigned i = 0;
        for(const auto num : nums){
            prod *= num;
            prod_out[i] = prod;
            i++;
        }
        
        // Now sweep back computing a running product towards the left
        // At each interval we have the info to compute out[i]
        // out[i] = PROD(left of i) * PROD(right of i)
        prod = 1;
        for(int i = n-1; 0 < i; i--){
            prod_out[i] = prod_out[i-1] * prod;
            prod *= nums[i];
        }
        prod_out[0] = prod;
        return prod_out;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<int> nums = {1,2,3,4};
        auto soln = solver.productExceptSelf(nums);
        cout << "Expected [24,12,8,6], computed: [ ";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
    }

    return 0;
}
