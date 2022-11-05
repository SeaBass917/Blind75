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
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        
        // Left Right Middle pointers
        int iL = 0;
        int iR = nums.size()-1;
        int iM = iR / 2;
        
        // Loop until we cross L/R pointers
        while(iL <= iR){
           
            // Read in the values at each pointer
            const int vL = nums[iL];
            const int vM = nums[iM];
            const int vR = nums[iR];
            
            // Check for target
            if(vM == target) return iM;
            if(vL == target) return iL;
            if(vR == target) return iR;
            
            // Determine whether target is in left sector or right
            // Branch based on the 3 cases
            //   - Left sector is sorted, target in bounds
            //   - Left sector is NOT sorted, Target is outside right sector
            bool isInLeftSector = false;
            if(vL < vM){
                if(vL < target && target < vM) isInLeftSector = true;
            }
            else{
                if (target < vM || vR < target) isInLeftSector = true;
            }

            // Adjust pointers into the search sector
            if(isInLeftSector)  {iR = iM-1; iL++;}
            else                {iL = iM+1; iR--;}
            iM = (iR + iL) >> 1;
        }
        
        return -1;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    std::cout << "Empty:" << std::endl;
    std::vector<int> tk0 = {};
    std::cout << solver.search(tk0, 700) << std::endl;
    std::cout << std::endl;

    std::cout << "Scalar:" << std::endl;
    std::vector<int> tk1 = {71};
    std::cout << solver.search(tk1, 655641) << std::endl;
    std::cout << solver.search(tk1, 71) << std::endl;
    std::cout << std::endl;

    std::cout << "Even:" << std::endl;
    std::vector<int> tk2 = {19,20,25,31,-24,-12,0,18};
    std::cout << solver.search(tk2, 7999) << std::endl;
    std::cout << solver.search(tk2, 19) << std::endl;
    std::cout << solver.search(tk2, 20) << std::endl;
    std::cout << solver.search(tk2, 25) << std::endl;
    std::cout << solver.search(tk2, 31) << std::endl;
    std::cout << solver.search(tk2, -24) << std::endl;
    std::cout << solver.search(tk2, -12) << std::endl;
    std::cout << solver.search(tk2, 0) << std::endl;
    std::cout << solver.search(tk2, 18) << std::endl;
    std::cout << std::endl;

    std::cout << "Odd:" << std::endl;
    std::vector<int> tk3 = {4,5,6,7,0,1,2};
    std::cout << solver.search(tk3, 15648) << std::endl;
    std::cout << solver.search(tk3, 4) << std::endl;
    std::cout << solver.search(tk3, 5) << std::endl;
    std::cout << solver.search(tk3, 6) << std::endl;
    std::cout << solver.search(tk3, 7) << std::endl;
    std::cout << solver.search(tk3, 0) << std::endl;
    std::cout << solver.search(tk3, 1) << std::endl;
    std::cout << solver.search(tk3, 2) << std::endl;
    std::cout << std::endl;

    std::cout << "Small 2:" << std::endl;
    std::vector<int> tk4 = {2,1};
    std::cout << solver.search(tk4, 65423) << std::endl;
    std::cout << solver.search(tk4, 2) << std::endl;
    std::cout << solver.search(tk4, 1) << std::endl;
    std::cout << std::endl;

    std::cout << "Small 3:" << std::endl;
    std::vector<int> tk5 = {2,-2,1};
    std::cout << solver.search(tk5, 65423) << std::endl;
    std::cout << solver.search(tk5, 2) << std::endl;
    std::cout << solver.search(tk5, -2) << std::endl;
    std::cout << solver.search(tk5, 1) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Even 2:" << std::endl;
    std::vector<int> tk6 = {4,5,6,7,8,1,2,3};
    std::cout << solver.search(tk6, 123456) << std::endl;
    std::cout << solver.search(tk6, 4) << std::endl;
    std::cout << solver.search(tk6, 5) << std::endl;
    std::cout << solver.search(tk6, 6) << std::endl;
    std::cout << solver.search(tk6, 7) << std::endl;
    std::cout << solver.search(tk6, 8) << std::endl;
    std::cout << solver.search(tk6, 1) << std::endl;
    std::cout << solver.search(tk6, 2) << std::endl;
    std::cout << solver.search(tk6, 3) << std::endl;
    std::cout << std::endl;
    
    return 0;
}
