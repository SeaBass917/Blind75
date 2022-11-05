#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, int> s_cnt;
        map<char, int> t_cnt;
        for(auto s_iter = s.begin(), t_iter = t.begin(); 
                s_iter != s.end(); s_iter++, t_iter++){
            s_cnt[*s_iter]++;
            t_cnt[*t_iter]++;
        }
        for(const auto c : s){
            if(s_cnt[c] != t_cnt[c]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        if(soln.isAnagram("anagram", "nagaram") == true){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    

    {
        if(soln.isAnagram("rat", "car") == false){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    

    {
        if(soln.isAnagram("", "") == true){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }

    return 0;
}
