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
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        // Minor improvement to read/write
        auto &matrix_0 = matrix[0];
        
        // Use the first row and first column as markers for
        // What row/column to zero out
        
        // Need an additional variable since we intersect at 0,0
        // This will mark the 0th row
        int cell_0_row = matrix_0[0];
        
        // Read the whole matrix and mark rows and cells
        for(unsigned i = 0; i < m; i++){
            auto &row = matrix[i];
            for(unsigned j = 0; j < n; j++){
                auto &cell = row[j];
                
                if(cell == 0){
                    // Mark column
                    matrix_0[j] = 0;
                    
                    // Mark row
                    if(0 < i){
                        matrix[i][0] = 0;
                    }
                    else{
                        cell_0_row = 0;
                    }
                    
                }
            }
        }
        
        // Zero out rows
        for(unsigned i = 1; i < m; i++){
            if(matrix[i][0] == 0){    
                for(unsigned j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out cols
        for(unsigned j = 0; j < n; j++){
            if(matrix_0[j] == 0){    
                for(unsigned i = 1; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Zero out 1st row
        if(cell_0_row == 0){
            for(unsigned j = 0; j < n; j++){
                matrix_0[j] = 0;
            }
        }
        
        return;
    }
};

string to_string_matrix(const vector<vector<int>> &matrix){
    
    string s_out = "";
    for(const auto row : matrix){
        for(const auto ele : row){
            s_out += "[";
            if(ele){
                for(unsigned i = 0; i < 1 - int(log10(ele)); i++) 
                    s_out += " ";
            }
            else{
                s_out += " ";
            }
            s_out += std::to_string(ele) + "]";
        }
        s_out += '\n';
    }
    return s_out;
}

int main(int argc, char const *argv[]){
    auto solver = Solution();

    vector<vector<int>> matrix0 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}}; 
    std::cout << "Before:" << std::endl;
    std::cout << to_string_matrix(matrix0) << std::endl;
    solver.setZeroes(matrix0);
    std::cout << "After:" << std::endl;
    std::cout << to_string_matrix(matrix0) << std::endl;
    std::cout << std::endl;

    return 0;
}
