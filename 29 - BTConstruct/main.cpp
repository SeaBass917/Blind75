#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        int root_val = preorder[0];

        auto root = new TreeNode(root_val);
        auto mid = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), root_val));

        auto left_preorder = vector<int>(&preorder[1], &preorder[mid+1]);
        auto right_preorder = vector<int>(&preorder[mid+1], &preorder[preorder.size()]);
        auto left_inorder = vector<int>(&inorder[0], &inorder[mid]);
        auto right_inorder = vector<int>(&inorder[mid+1], &inorder[inorder.size()]);
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p || !q) return !p && !q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        auto soln = solver.buildTree(preorder, inorder);

        auto root0 = TreeNode(3);
        auto node0 = TreeNode(9);
        auto node1 = TreeNode(20);
        auto node2 = TreeNode(15);
        auto node3 = TreeNode(7);
        root0.left = &node0;
        root0.right = &node1;
        node1.left = &node2;
        node1.right = &node3;

        string result = (isSameTree(&root0, soln))? "Passed" : "FAILED!";
        cout << result << endl;
    }

    {
        vector<int> preorder = {-1};
        vector<int> inorder = {-1};
        auto soln = solver.buildTree(preorder, inorder);

        auto root0 = TreeNode(-1);

        string result = (isSameTree(&root0, soln))? "Passed" : "FAILED!";
        cout << result << endl;
    }

    return 0;
}
