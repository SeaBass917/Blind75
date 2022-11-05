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
    
    // A-Z : [65-90]
    // a-z : [97-122]
    char to_lower(const char c){
        if(65 <= c && c <= 90) return c + 32;
        return c;
    }
    
    bool is_alphanum(const char c){
        return (48 <= c && c <= 57) || (97 <= c && c <= 122);
    }
    
public:
    // "jimx.....ij"
    bool isPalindrome(string s) {
        
        int iL = 0;
        int iR = s.size() - 1;
        
        while(iL < iR){
            const char cL = to_lower(s[iL]);
            const char cR = to_lower(s[iR]);
            
            
            if(!is_alphanum(cL)) {
                iL++;
                continue;
            }
            if(!is_alphanum(cR)) {
                iR--;
                continue;
            }
            
            if(cL != cR) return false;
            iL++;
            iR--;
        }
        
        return true;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        auto soln = (solver.isPalindrome("A man, a plan, a canal: Panama"))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }
    
    {
        auto soln = (solver.isPalindrome("race a car"))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }
    
    {
        auto soln = (solver.isPalindrome(" "))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }
    
    {
        auto soln = (solver.isPalindrome("0P"))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }
    
    return 0;
}
