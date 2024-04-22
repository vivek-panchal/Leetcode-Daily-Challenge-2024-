class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int, string>> q;
        unordered_map<string, int> graph;
        for (const auto& deadend : deadends) {
            graph[deadend] = 1;
        }
        unordered_map<char, char> forward = {{'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'}, {'4', '5'}, {'5', '6'}, {'6', '7'}, {'7', '8'}, {'8', '9'}, {'9', '0'}};
        unordered_map<char, char> reverse = {{'0', '9'}, {'1', '0'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}};
        
        if (graph.find("0000") != graph.end()) return -1; 
        q.push({0, "0000"});
        graph["0000"] = 1; 
        
        while (!q.empty()) {
            int stage = q.front().first;
            string node = q.front().second;
            q.pop();
            
            if (node == target) return stage; 
            
            for (int i = 0; i < node.size(); ++i) {
                string temp = node;
                temp[i] = forward[temp[i]];
                if (graph.find(temp) == graph.end()) { 
                    q.push({stage + 1, temp});
                    graph[temp] = 1;
                    if (temp == target) return stage+1;
                }
                
                temp[i] = reverse[node[i]];
                if (graph.find(temp) == graph.end()) { // Check if the new state is not a deadend
                    q.push({stage + 1, temp});
                    graph[temp] = 1;
                    if (temp == target) return stage+1;
                }
            }
        }
        
        return -1;
    }
};
