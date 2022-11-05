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
    TreeNode *search(TreeNode* root, const TreeNode* p, const TreeNode* q){
        const int val_m = root->val;
        const int val_l = p->val;
        const int val_r = q->val;
        
        if(val_l <= val_m && val_m <= val_r) return root;
        else{
            if(val_m < val_l) return search(root->right, p, q);
            else              return search(root->left, p, q);
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(p->val < q->val) return search(root, p, q);
        else                return search(root, q, p);
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto root0 = TreeNode(6);
        auto node0 = TreeNode(3);
        auto node1 = TreeNode(7);
        auto node2 = TreeNode(1);
        auto node3 = TreeNode(4);
        root0.left = &node0;
        root0.right = &node1;
        node0.left = &node2;
        node0.right = &node3;

        cout << "Expected 3 found: " << solver.lowestCommonAncestor(&root0, &node2, &node3)->val << endl;
    }

    {
        auto root0 = TreeNode(6);
        auto node0 = TreeNode(2);
        auto node1 = TreeNode(8);
        auto node2 = TreeNode(0);
        auto node3 = TreeNode(4);
        auto node4 = TreeNode(7);
        auto node5 = TreeNode(9);
        auto node6 = TreeNode(3);
        auto node7 = TreeNode(5);
        root0.left = &node0;
        root0.right = &node1;
        node0.left = &node2;
        node0.right = &node3;
        node1.left = &node4;
        node1.right = &node5;
        node3.left = &node6;
        node3.right = &node7;

        cout << "Expected 6 found: " << solver.lowestCommonAncestor(&root0, &node0, &node1)->val << endl;
    }

    {
        auto root0 = TreeNode(6);
        auto node0 = TreeNode(2);
        auto node1 = TreeNode(8);
        auto node2 = TreeNode(0);
        auto node3 = TreeNode(4);
        auto node4 = TreeNode(7);
        auto node5 = TreeNode(9);
        auto node6 = TreeNode(3);
        auto node7 = TreeNode(5);
        root0.left = &node0;
        root0.right = &node1;
        node0.left = &node2;
        node0.right = &node3;
        node1.left = &node4;
        node1.right = &node5;
        node3.left = &node6;
        node3.right = &node7;

        cout << "Expected 4 found: " << solver.lowestCommonAncestor(&root0, &node6, &node7)->val << endl;
    }

    return 0;
}
