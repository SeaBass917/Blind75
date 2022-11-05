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
    void rotate(vector<vector<int>>& matrix) {
        const unsigned N = matrix.size();
        if(N == 0) return;
        
        unsigned level = 0;
        const unsigned middle = N / 2;
        const unsigned end = N - 1;
        while(level < middle){
            
            // Pull high access rows into local memory
            auto matrix_level = matrix[level];
            auto matrix_level_end = matrix[end-level];
            
            // -----------------
            // Corner behaviour
            // -----------------
            /*
            [X][ ][>][ ][X]
            [ ][X][ ][X][ ]
            [^][ ][ ][ ][V]
            [ ][X][ ][X][ ]
            [X][ ][<][ ][X]
            
            [X][ ][ ][X]
            [ ][X][X][X]
            [ ][X][X][ ]
            [X][ ][ ][X]
            */
            
            // NE Pixel
            const int tmp_corner = matrix_level[end-level];
            
            // NW -> NE
            matrix_level[end-level] = matrix_level[level];
            
            // SW -> NW
            matrix_level[level] = matrix_level_end[level];
            
            // SE -> SW
            matrix_level_end[level] = matrix_level_end[end-level];
            
            // NE -> SE
            matrix_level_end[end-level] = tmp_corner;
            
            // ---------------
            // Edge Behaviour
            // ---------------
            /*
            [ ][X][-][>][ ]
            [^][ ][X][ ][X]
            [|][X][ ][X][|]
            [X][ ][X][ ][V]
            [ ][<][-][X][ ]
            */
            for(unsigned i = level+1; i < end-level; i++){
                
                // N pixel
                const int tmp_edge = matrix_level[i];
                
                // W -> N
                matrix_level[i] = matrix[end-i][level];
                
                // S -> W
                matrix[end-i][level] = matrix_level_end[end-i];
                
                // E -> S
                matrix_level_end[end-i] = matrix[i][end-level];
                
                // N -> E
                matrix[i][end-level] = tmp_edge;
            }
            
            // Restore high access rows from local memory
            matrix[level] = matrix_level;
            matrix[end-level] = matrix_level_end;
            
            // Move inward
            level++;
        }
    }
};

string to_string_matrix(const vector<vector<int>> &matrix){
    
    string s_out = "";
    for(const auto row : matrix){
        for(const auto ele : row){
            s_out += "[";
            for(unsigned i = 0; i < 1 - int(log10(ele)); i++) s_out += " ";
            s_out += std::to_string(ele) + "]";
        }
        s_out += '\n';
    }
    return s_out;
}

int main(int argc, char const *argv[]){
    auto solver = Solution();

    vector<vector<int>> matrix0 = {{1,2,3},{4,5,6},{7,8,9}}; 
    std::cout << "Before:" << std::endl;
    std::cout << to_string_matrix(matrix0) << std::endl;
    solver.rotate(matrix0);
    std::cout << "After:" << std::endl;
    std::cout << to_string_matrix(matrix0) << std::endl;
    std::cout << std::endl;

    vector<vector<int>> matrix1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 
    std::cout << "Before:" << std::endl;
    std::cout << to_string_matrix(matrix1) << std::endl;
    solver.rotate(matrix1);
    std::cout << "After:" << std::endl;
    std::cout << to_string_matrix(matrix1) << std::endl;
    std::cout << std::endl;
    
    vector<vector<int>> matrix2 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}; 
    std::cout << "Before:" << std::endl;
    std::cout << to_string_matrix(matrix2) << std::endl;
    solver.rotate(matrix2);
    std::cout << "After:" << std::endl;
    std::cout << to_string_matrix(matrix2) << std::endl;
    std::cout << std::endl;

    return 0;
}
