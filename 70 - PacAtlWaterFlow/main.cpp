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

class Solution {
    using FlagTable = vector<vector<bool>>;
    int m;
    int n;
    
    void dfs(const int i, const int j, const int height_prev, FlagTable &visited, const vector<vector<int>>& heights){
        
        // If we have visisted here, or are out of bounds return
        if(i < 0 || m <= i || j < 0 || n <= j || visited[i][j]) return;

        // Grab the value at this location
        const int height = heights[i][j];

        // If we are less than the prev hiehgt this direction is not legal
        if(height < height_prev) return;

        visited[i][j] = true;

        dfs(i+1, j, height, visited, heights);
        dfs(i-1, j, height, visited, heights);
        dfs(i, j+1, height, visited, heights);
        dfs(i, j-1, height, visited, heights);
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        // Iniailize a visited table for each ocean
        FlagTable visited_pacific(m, vector<bool>(n, false));
        FlagTable visited_atlantic(m, vector<bool>(n, false));

        // Reverse the problem
        // Scan from the ocean inwards.
        // Determine all loations that hit pacific, then atlantic
        for(unsigned i = 0; i < m; i++){
            dfs(i,   0,   heights[i][0], visited_pacific, heights);
            dfs(i, n-1, heights[i][n-1], visited_atlantic, heights);
        }
        for(unsigned j = 0; j < n; j++){
            dfs(0,   j,   heights[0][j], visited_pacific, heights);
            dfs(m-1, j, heights[m-1][j], visited_atlantic, heights);
        }

        // Return the overlap between the two tables
        vector<vector<int>> res_coords;
        for(int i = 0; i < m; i++){
            const auto row_pacific = visited_pacific[i];
            const auto row_atlantic = visited_atlantic[i];
            for(int j = 0; j < n; j++){
                if(row_pacific[j] && row_atlantic[j]) res_coords.push_back({i, j});
            }   
        }

        return res_coords;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        auto soln = solver.pacificAtlantic(heights);
        cout << "Expected [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]], computed: [";
        for(const auto s : soln){
            cout << "[" << s[0] << "," << s[1] << "]";
        }
        cout << ']' << endl;
    }

    return 0;
}
