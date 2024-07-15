class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        // Create nodes and establish parent-child relationships
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];

            if (mp.find(parentVal) == mp.end()) {
                mp[parentVal] = new TreeNode(parentVal);
            }
            if (mp.find(childVal) == mp.end()) {
                mp[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                mp[parentVal]->left = mp[childVal];
            } else {
                mp[parentVal]->right = mp[childVal];
            }

            children.insert(childVal);
        }

        // Find the root node (node that is not a child of any other node)
        TreeNode* root = nullptr;
        for (auto& [val, node] : mp) {
            if (children.find(val) == children.end()) {
                root = node;
                break;
            }
        }

        return root;
    }
};
