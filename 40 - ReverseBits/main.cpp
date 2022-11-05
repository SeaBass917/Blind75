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
    uint32_t reverseBits(uint32_t n) {
        uint32_t out(0);
        for(unsigned i = 0; i < 32; i++){
            auto bit = (n >> i) & 1u;
            out |= bit << (31 - i);
        }
        return out;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();
    
    {
        cout << "Expected 4026531840 found: " << solver.reverseBits(15) << endl;
    }
    
    {
        cout << "Expected 964176192 found: " << solver.reverseBits(43261596) << endl;
    }

    {
        cout << "Expected 3221225471 found: " << solver.reverseBits(4294967293) << endl;
    }
    
    return 0;
}
