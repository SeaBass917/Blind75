#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

struct Test {
    vector<int> problem;
    vector<int> solution;
    Test(vector<int> problem, vector<int> solution) : problem(problem), solution(solution) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return nullptr;
    }
};

bool populate_tree(vector<TreeNode &> &vec_nodes){
    bool status(true);
    auto root = vec_nodes[0];
    
    for(unsigned i = 1; i < vec_nodes.size(); i++){
        TreeNode *node = &vec_nodes[i];
        
        TreeNode *node_parent = &root;
        set<TreeNode *> visited = {};
        while(true){
            visited.emplace(node_parent);

            if(node_parent->left == nullptr){
                node_parent->left = node;
                break;
            }
            else if(node_parent->right == nullptr){
                node_parent->right = node;
                break;
            }
            else {
                if (visited.find(node_parent->left) == visited.end()){
                    node_parent = node_parent->left;
                }
                else if (visited.find(node_parent->right) == visited.end()){
                    node_parent = node_parent->right;
                }
                else{
                    status = false;
                    break;
                }
            }
        }
    }

    return status;
}

vector<int> flatten_tree(TreeNode *root){
    return {};
}

bool vector_compare(vector<int> a, vector<int> b){
    if (a.size() != b.size()) return false;

    for(unsigned i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }

    return true;
}

int main(int argc, char const *argv[]){

    set<Test> tests = {
        {
            {4,2,7,1,3,6,9}, {4,7,2,9,6,3,1}
        }
    };

    auto soln = Solution();
    for(auto test:tests){
        auto problem = test.problem;
        auto solution = test.solution;

        // Create each node
        vector<TreeNode &> test_nodes(problem.size());
        for(unsigned i = 0; i < problem.size(); i++){
            test_nodes[i] = TreeNode(problem[i]);
        }

        // Connect the pointers
        if(populate_tree(test_nodes)){
            soln.invertTree(&test_nodes[0]);

            auto solution_flat = flatten_tree(&test_nodes[0]);

            if(!vector_compare(solution, solution_flat)){
                cout << "Error for test case: [";
                for(auto x : solution) cout << x << ",";
                cout << "]." << endl;

                cout << "Received: [";
                for(auto x : solution_flat) cout << x << ",";
                cout << "]." << endl;
            }
        }
        else{
            cout << "Error in tree population code!" << endl;
            break;
        }
    }

    return 0;
}
