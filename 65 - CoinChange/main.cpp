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
    int coinChange(vector<int>& coins, int amount) {
        const int default_amount = amount+1;
        
        vector<int> dp(amount+1, default_amount);

        dp[0] = 0;
        for(unsigned n = 1; n <= amount; n++){
            for(const auto coin : coins){
                const int rem = n - coin;
                if(0 <= rem){
                    dp[n] = min(dp[n], 1 + dp[rem]);
                }
            }
        }

        const int res = dp[amount]; 
        return (default_amount != res)? res : -1;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        vector<int> nums = {1,2147483647};
        cout << "Expected : 2  | Received : " << soln.coinChange(nums, 2) << endl;
    }


    {
        vector<int> nums = {1, 2, 5};
        cout << "Expected : 3  | Received : " << soln.coinChange(nums, 11) << endl;
        cout << "Expected : 6  | Received : " << soln.coinChange(nums, 26) << endl;
    }


    {
        vector<int> nums = {2};
        cout << "Expected : -1  | Received : " << soln.coinChange(nums, 3) << endl;
    }


    {
        vector<int> nums = {1};
        cout << "Expected : 0  | Received : " << soln.coinChange(nums, 0) << endl;
    }

    return 0;
}
