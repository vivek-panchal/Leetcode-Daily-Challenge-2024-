class Solution {
private:
    void reverseInOrder(TreeNode* node, int& sum) {
        if (node == nullptr) {
            return;
        }
        reverseInOrder(node->right, sum);
        sum += node->val;
        node->val = sum;
        reverseInOrder(node->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInOrder(root, sum);
        return root;
    }
};
