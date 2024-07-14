#include <iostream>
#include <algorithm>

using namespace std;

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        return max(leftDepth + rightDepth, max(leftDia, rightDia));
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Creating a simple test tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    std::cout << "The diameter of the tree is: " << diameter << std::endl;

    return 0;
}
