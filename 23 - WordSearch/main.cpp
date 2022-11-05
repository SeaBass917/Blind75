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
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        const char char_0 = word[0];
        
        // Initialize visited
        visited = vector<vector<bool>>(m);
        for(auto &row : visited) row = vector<bool>(n, false);
        
        // Loop through each cell and start a search 
        // if the character matches the start
        int i = 0;
        int j = 0;
        bool is_found = true;
        for(const auto &row : board){
            j = 0;
            for(const auto &c : row){
                if(c == char_0){
                    is_found = search(board, {i, j}, word);
                    visited[i][j] = false;
                    if(is_found) return true;
                }
                j++;
            }   
            i++;
        }
        
        return false;
    }
                       
private:
    using Coord = pair<int,int>;
    vector<vector<bool>> visited;
    int m;
    int n;
                       
    bool search(const vector<vector<char>>& board, const Coord coord, const string word){        
        const int i = coord.first;
        const int j = coord.second;
        const char char_0 = word[0];
        const char char_board = board[i][j];
        
        // Exit this branch, if char not match, or we've been here before.
        if(char_board != char_0) return false;

        // End condition when the word have 1 char and char matches
        if(word.size() == 1 && char_0 == char_board) return true;
        
        // Lok to adjacent coordinates
        const Coord coord_N = {i-1, j  };
        const Coord coord_S = {i+1, j  };
        const Coord coord_W = {i  , j-1};
        const Coord coord_E = {i  , j+1};
        
        visited[i][j] = true;
        
        bool is_found = false;
        if(0 <= coord_N.first && !visited[coord_N.first][coord_N.second]){
            is_found = search(board, coord_N, word.substr(1));
            visited[coord_N.first][coord_N.second] = false;
            if(is_found) return true;
        }
        
        if(coord_S.first < m && !visited[coord_S.first][coord_S.second]){
            is_found = search(board, coord_S, word.substr(1));
            visited[coord_S.first][coord_S.second] = false;
            if(is_found) return true;
        }
        
        if(0 <= coord_W.second && !visited[coord_W.first][coord_W.second]){
            is_found = search(board, coord_W, word.substr(1));
            visited[coord_W.first][coord_W.second] = false;
            if(is_found) return true;
        }
        
        if(coord_E.second < n && !visited[coord_E.first][coord_E.second]){
            is_found = search(board, coord_E, word.substr(1));
            visited[coord_E.first][coord_E.second] = false;
            if(is_found) return true;
        }
            
        return false;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    vector<vector<char>> tk1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    auto flag_str1 = solver.exist(tk1, "ABCCED")? "True" : "False";
    std::cout << "Expected TRUE, computed: " << flag_str1 << std::endl;

    vector<vector<char>> tk2 = {{'a','b'},{'c','d'}};
    auto flag_str2 = solver.exist(tk2, "acdb")? "True" : "False";
    std::cout << "Expected TRUE, computed: " << flag_str2 << std::endl;
    
    vector<vector<char>> tk3 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    auto flag_str3 = solver.exist(tk3, "ABCB")? "True" : "False";
    std::cout << "Expected FALSE, computed: " << flag_str3 << std::endl;
    
    vector<vector<char>> tk4 = {{'A'}};
    auto flag_str4 = solver.exist(tk4, "A")? "True" : "False";
    std::cout << "Expected TRUE, computed: " << flag_str4 << std::endl;
    
    vector<vector<char>> tk5 = {{'A'}};
    auto flag_str5 = solver.exist(tk5, "AB")? "True" : "False";
    std::cout << "Expected FALSE, computed: " << flag_str5 << std::endl;
    
    vector<vector<char>> tk6 = {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
    auto flag_str6 = solver.exist(tk6, "aaaaaaaaaaaaa")? "True" : "False";
    std::cout << "Expected FALSE, computed: " << flag_str6 << std::endl;
    
    vector<vector<char>> tk7 = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    auto flag_str7 = solver.exist(tk7, "AAB")? "True" : "False";
    std::cout << "Expected TRUE, computed: " << flag_str7 << std::endl;
    
    
    return 0;
}
