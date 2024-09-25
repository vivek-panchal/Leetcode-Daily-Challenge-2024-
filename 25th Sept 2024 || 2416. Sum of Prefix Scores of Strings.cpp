class Solution {
    class Trie {
    public:
        int counter;
        unordered_map<char, Trie*> nodes;
        Trie() : counter(0){}
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie * root = new Trie();
        for(auto& w: words) {
            insert(w, root);
        }
        vector<int> result(words.size(), 0);
        for(int i=0;i<words.size();i++) {
            result[i] = getCount(words[i], root);
        }
        return result;
    }

    int getCount(const string& w, Trie* root) {
        int sum = 0;
        for(auto c: w) {
            Trie *node = root->nodes[c];
            sum += node->counter;
            root = node;
        }
        return sum;
    }

    void insert(const string& w, Trie *root) {
        for(auto c: w) {
            Trie *node = root->nodes[c];
            if (node == nullptr) {
                node = new Trie();
                root->nodes[c] = node;
            }
            node->counter += 1;
            root = node;
        }
    }
};
