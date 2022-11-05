#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <numeric>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int par_cnt = 0;
        int brk_cnt = 0;
        int brc_cnt = 0;
        
        // [(){}]
        stack<char> last_open_stack;
        for(const auto c : s){
            switch(c){
                case '(': {
                    par_cnt++;
                    last_open_stack.emplace('(');
                    break;
                }
                case '[': {
                    brk_cnt++;
                    last_open_stack.emplace('[');
                    break;
                }
                case '{': {
                    brc_cnt++;
                    last_open_stack.emplace('{');
                    break;
                }
                case ')': {
                    if(!last_open_stack.empty()){
                        const char last_open = last_open_stack.top(); last_open_stack.pop();
                        if(last_open == '[' || last_open == '{') return false;
                    }
                    if(par_cnt == 0) return false;
                    par_cnt--;
                    break;
                }
                case ']': {
                    if(!last_open_stack.empty()){
                        const char last_open = last_open_stack.top(); last_open_stack.pop();
                        if(last_open == '(' || last_open == '{') return false;
                    }
                    if(brk_cnt == 0) return false;
                    brk_cnt--;
                    break;
                }
                case '}': {
                    if(!last_open_stack.empty()){
                        const char last_open = last_open_stack.top(); last_open_stack.pop();
                        if(last_open == '(' || last_open == '[') return false;
                    }
                    if(brc_cnt == 0) return false;
                    brc_cnt--;
                    break;
                }
            }
        }
        
        return par_cnt == 0 && brk_cnt == 0 && brc_cnt == 0;
    }
};



int main(int argc, char const *argv[]){

    auto solver = Solution();
    
    std::cout << "TRUE:" << std::endl;
    std::cout << solver.isValid("()") << std::endl;
    std::cout << solver.isValid("()[]{}") << std::endl;
    std::cout << solver.isValid("[(){}]") << std::endl;
    std::cout << solver.isValid("[[[()]{}]]") << std::endl;
    std::cout << solver.isValid("[[[()]{}]]()[]") << std::endl;
    std::cout << std::endl;

    std::cout << "FALSE:" << std::endl;
    std::cout << solver.isValid("[(])") << std::endl;
    std::cout << solver.isValid("]") << std::endl;
    std::cout << solver.isValid("}]") << std::endl;
    std::cout << solver.isValid("]][]") << std::endl;
    std::cout << solver.isValid("({[[]({})}]})") << std::endl;
    std::cout << solver.isValid("(){}}{") << std::endl;

    return 0;
}
