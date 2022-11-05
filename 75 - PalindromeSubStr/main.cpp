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
    int countSubstrings(string s) {
        return 0;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        cout << "Expected 3, computed: " << solver.countSubstrings("abc") << endl;
        cout << "Expected 6, computed: " << solver.countSubstrings("aaa") << endl;
    }

    return 0;
}
