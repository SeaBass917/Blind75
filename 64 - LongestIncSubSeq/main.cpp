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

    int insert_loc_linear(const vector<int>& seq, const int num){
        int i;
        for(i = seq.size()-1; 0 <= i; i--){
            if(seq[i] < num) break;
        }
        return i+1;
    }

    int insert_loc(const vector<int>& seq, const int num){
        int iL = 0; 
        int iR = seq.size()-1;
        int iM = (iR + iL) >> 1;

        // [2, 6, 8, 12, 13, 15] | 9
        // [8, 12, 13, 15] | 9
        // [8, 12] | 9
        while(1 < iR - iL){
            if(seq[iM] < num){
                iL = iM;
            }
            else{
                iR = iM;
            }
            iM = (iR + iL) >> 1;
        }

        return (num <= seq[iL])? iL : iR;
    }
public:
    // 	~11 ms Time : O(nlogn) Space : O(n)
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();

        vector<int> seq;
        int prev_max = INT32_MIN;   // This works because nums is bound -10000 < nums < 10000
        int i = 0;
        int seq_len = 0;
        for(const auto num : nums){
            if(prev_max < num){
                seq.push_back(num);
                seq_len++;
                prev_max = num;
            }
            else{
                const int j = insert_loc(seq, num);
                seq[j] = num;
                prev_max = seq[seq_len-1];
            }
            i++;
        }
        
        return seq.size();
    }

    // 	~309 ms Time : O(n^2) Space : O(n)
    int lengthOfLIS_dp(vector<int>& nums) {
        const int n = nums.size();

        // Create a table of longest increasing subsequences
        vector<int> lis(n);
        int lis_true_max = 0;

        // Work our way backwards
        // Search for max amongst each subseq we are allowed to join
        for(int i = n-1; 0 <= i; i--){
            const int num = nums[i];

            int lis_max = 1;
            for(unsigned ii = i+1; ii < n; ii++){
                if(num < nums[ii]){
                    lis_max = max(lis_max, 1 + lis[ii]);
                }
            }
            lis[i] = lis_max;
            lis_true_max = max(lis_true_max, lis_max);
        }

        return lis_true_max;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        vector<int> nums = {4,10,4,3,8,9};
        cout << "Expected : 3  | Received : " << soln.lengthOfLIS(nums) << endl;
    }

    {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        cout << "Expected : 4  | Received : " << soln.lengthOfLIS(nums) << endl;
    }

    {
        vector<int> nums = {7,6,5,4,3,2,1,0};
        cout << "Expected : 1  | Received : " << soln.lengthOfLIS(nums) << endl;
    }

    {
        vector<int> nums = {7,8,5,9,3,10,1,11};
        cout << "Expected : 5  | Received : " << soln.lengthOfLIS(nums) << endl;
    }

    return 0;
}
