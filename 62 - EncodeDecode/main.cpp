#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;
#include <sstream>

// [0, 1, 2, 4]
class Solution {
    const char delim = '.';
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        stringstream s_out;
        for(const auto str : strs){
            s_out << std::to_string(str.length()) << delim << str;
        }
        return s_out.str();
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        
        vector<string> strs;

        int i_end = -1;
        int i = -2;
        stringstream len_str;
        stringstream str_build;
        for(const auto c : str){
            if(i < 0){
                if(c != delim){
                    len_str << c;
                }
                else{
                    const int len = std::stoi(len_str.str());
                    if(len){
                        i_end = len - 1;
                        i = 0;
                    }
                    else{
                        strs.push_back("");
                        len_str.str(std::string());
                    }
                }
            }
            else if(i == i_end){
                str_build << c;
                strs.push_back(str_build.str());
                str_build.str(std::string());
                len_str.str(std::string());
                i_end = -1;
                i = -2;
            }
            else{
                str_build << c;
                i++;
            }
        }
        
        return strs;
    }
};

string to_string_vector(const vector<string> strs){
    stringstream s_out;
    for(const auto str : strs){
        s_out << "\""<<str<<"\",";
    }
    return s_out.str();
}

bool vector_match(const vector<string> strs1, const vector<string> strs2){
    const int n1 = strs1.size();
    const int n2 = strs2.size();
    if(n1 != n2) return false;
    for(unsigned i = 0; i < n1; i++){
        if(strs1[i] != strs2[i]) return false;
    }
    return true;
}

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<string> words = {"wrter","wrt"};
        auto code = solver.encode(words);
        auto res = solver.decode(code);
        if(!vector_match(words, res)){
            cout << "Expected "<< to_string_vector(words) <<" found: " << to_string_vector(res) << endl;
        }
        else{
            cout << "Passed!" << endl;
        }
    }

    {
        vector<string> words = {"a","b", "", "asdaw"};
        auto code = solver.encode(words);
        auto res = solver.decode(code);
        if(!vector_match(words, res)){
            cout << "Expected "<< to_string_vector(words) <<" found: " << to_string_vector(res) << endl;
        }
        else{
            cout << "Passed!" << endl;
        }
    }

    {
        vector<string> words = {"a","a", "aa", "aaaaaa"};
        auto code = solver.encode(words);
        auto res = solver.decode(code);
        if(!vector_match(words, res)){
            cout << "Expected "<< to_string_vector(words) <<" found: " << to_string_vector(res) << endl;
        }
        else{
            cout << "Passed!" << endl;
        }
    }

    {
        vector<string> words = {".",";", ":", "\""};
        auto code = solver.encode(words);
        auto res = solver.decode(code);
        if(!vector_match(words, res)){
            cout << "Expected "<< to_string_vector(words) <<" found: " << to_string_vector(res) << endl;
        }
        else{
            cout << "Passed!" << endl;
        }
    }

    return 0;
}
