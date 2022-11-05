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
    int hammingWeight(uint32_t n) {
        unsigned cnt = 0;
        for(unsigned i = 0; i < 32; i++){
            if( (n >> i) & 1u ) cnt++;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();
    
    {
        cout << "Expected 3 found: " << solver.hammingWeight(11) << endl;
    }
    
    {
        cout << "Expected 1 found: " << solver.hammingWeight(128) << endl;
    }

    {
        cout << "Expected 2 found: " << solver.hammingWeight(129) << endl;
    }
    
    {
        cout << "Expected 6 found: " << solver.hammingWeight(268977282) << endl;
    }
    
    return 0;
}
