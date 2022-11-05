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
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        stack<TreeNode*> node_history;
        auto curr = root;
        
        while (curr || !node_history.empty()){
            while(curr){
                node_history.emplace(curr);
                curr = curr->left;
            }
            curr = node_history.top();
            node_history.pop();
            i++;
            
            if(i == k) return curr->val;
            
            curr = curr->right;
        }
        
        // k > number of nodes
        return -1;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto root0 = TreeNode(3);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(2);
        auto node2 = TreeNode(4);
        root0.left = &node0;
        node0.right = &node1;
        root0.right = &node2;

        cout << "Expected 1 found: " << solver.kthSmallest(&root0, 1) << endl;
    }

    {
        auto root0 = TreeNode(3);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(2);
        auto node2 = TreeNode(4);
        root0.left = &node0;
        node0.right = &node1;
        root0.right = &node2;

        cout << "Expected 4 found: " << solver.kthSmallest(&root0, 4) << endl;
    }

    {
        auto root0 = TreeNode(65);
        auto node0 = TreeNode(34);
        auto node1 = TreeNode(42);
        auto node2 = TreeNode(102);
        root0.left = &node0;
        node0.right = &node1;
        root0.right = &node2;

        cout << "Expected 65 found: " << solver.kthSmallest(&root0, 3) << endl;
    }


    return 0;
}
