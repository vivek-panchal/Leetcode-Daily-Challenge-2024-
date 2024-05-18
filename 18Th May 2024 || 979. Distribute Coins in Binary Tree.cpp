class Solution {
private:
    int solve(TreeNode* root, int& moves) {
        if (root == NULL)
            return 0;
        int l = solve(root -> left, moves);
        int r = solve(root -> right, moves);

        moves += abs(l) + abs(r);
        return (l+ r + root -> val) - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        solve(root, moves);
        return moves;
    }
};
