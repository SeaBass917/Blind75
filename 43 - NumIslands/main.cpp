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
    int hash(const int a, const int b){
        return (((a + b) * (a + b + 1)) >> 1) + a;
    }

    unordered_set<int> visited;
    int h;
    int w;

    void tag_adjacents_dfs(const vector<vector<char>>& grid, const int i, const int j){

        visited.emplace(hash(i,j));

        // North
        if(0 < i){
            if(visited.find(hash(i-1, j)) == visited.end() && grid[i-1][j] == '1'){
                tag_adjacents_dfs(grid, i-1, j);
            }
        }
        // South
        if(i+1 < h){
            if(visited.find(hash(i+1, j)) == visited.end() && grid[i+1][j] == '1'){
                tag_adjacents_dfs(grid, i+1, j);
            }
        }
        // West
        if(0 < j){
            if(visited.find(hash(i, j-1)) == visited.end() && grid[i][j-1] == '1'){
                tag_adjacents_dfs(grid, i, j-1);
            }
        }
        // East
        if(j+1 < w){
            if(visited.find(hash(i, j+1)) == visited.end() && grid[i][j+1] == '1'){
                tag_adjacents_dfs(grid, i, j+1);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        visited.clear();
        h = grid.size();
        w = grid[0].size();

        // Loop through the grid and count islands
        // Once one is found mark all connected cells as visited.
        int num_islands = 0;
        for(int i = 0; i < h; i++){
            const auto row = grid[i];
            for(int j = 0; j < w; j++){
                // Is an island
                if(row[j] == '1'){
                    // Skip if we have seen this already
                    if(visited.find(hash(i,j)) != visited.end()) continue;

                    // Tag all connected cells
                    tag_adjacents_dfs(grid, i, j);
                    num_islands++;
                }
            }      
        }

        return num_islands;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<vector<char>> in = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        };
        cout << "Expected 1 found: " << solver.numIslands(in) << endl;
    }

    {
        vector<vector<char>> in = {
            {'1','1','0','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        };
        cout << "Expected 2 found: " << solver.numIslands(in) << endl;
    }

    return 0;
}
