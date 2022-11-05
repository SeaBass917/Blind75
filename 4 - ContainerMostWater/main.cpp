#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>
#include <list>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        if (height.size() < 2) return 0;
        
        int volMax = -1;
        
        int iL = 0;
        int iR = height.size() - 1;
        while (iL < iR){
            const int vL = height[iL];
            const int vR = height[iR];
            const int vol = min(vL, vR) * (iR - iL);
            
            volMax = max(vol, volMax);
            
            if (vL < vR) iL++;
            else iR--;
        }
        
        return volMax;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    std::vector<int> tk1 = {1,8,6,2,5,4,8,3,7};
    std::cout << solver.maxArea(tk1) << " =? (49)" << std::endl;

    std::vector<int> tk2 = {1,1};
    std::cout << solver.maxArea(tk2) << " =? (1)" << std::endl;
    
    return 0;
}
