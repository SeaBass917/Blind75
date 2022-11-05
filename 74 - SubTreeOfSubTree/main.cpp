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
    bool do_match(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot) return root == subRoot;
        if(root->val != subRoot->val) return false;
        return do_match(root->left, subRoot->left) && do_match(root->right, subRoot->right);
    };
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root == subRoot;
        if(do_match(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto root1 = TreeNode(3);
        auto node0 = TreeNode(4);
        auto node1 = TreeNode(5);
        auto node4 = TreeNode(1);
        auto node5 = TreeNode(2);
        root1.left = &node0;
        root1.right = &node1;
        node0.left = &node4;
        node0.right = &node5;
        
        auto root2 = TreeNode(4);
        auto node7 = TreeNode(1);
        auto node8 = TreeNode(2);
        root2.left = &node7;
        root2.right = &node8;

        auto soln = (solver.isSubtree(&root1, &root2))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    {
        auto root1 = TreeNode(3);
        auto node0 = TreeNode(4);
        auto node1 = TreeNode(5);
        auto node4 = TreeNode(1);
        auto node5 = TreeNode(2);
        auto node6 = TreeNode(0);
        root1.left = &node0;
        root1.right = &node1;
        node0.left = &node4;
        node0.right = &node5;
        node5.left = &node6;
        
        auto root2 = TreeNode(4);
        auto node7 = TreeNode(1);
        auto node8 = TreeNode(2);
        root2.left = &node7;
        root2.right = &node8;

        auto soln = (solver.isSubtree(&root1, &root2))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }

    {
        auto root1 = TreeNode(1);
        auto node0 = TreeNode(1);
        root1.left = &node0;
        
        auto root2 = TreeNode(1);

        auto soln = (solver.isSubtree(&root1, &root2))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    return 0;
}
