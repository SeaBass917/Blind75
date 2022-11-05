#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int val_min = INT32_MAX;
        int profit_max = 0;
        for(const auto val : prices){
            profit_max = max(profit_max, val - val_min);
            val_min = min(val_min, val);
        }
        return profit_max;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> prices = {7,1,5,3,6,4};
        cout << "Expected 5, computed: " << solver.maxProfit(prices) << endl;
    }

    {
        vector<int> prices = {7,6,4,3,1};
        cout << "Expected 0, computed: " << solver.maxProfit(prices) << endl;
    }

    return 0;
}
