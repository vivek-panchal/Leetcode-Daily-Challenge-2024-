class Solution {
public:
    vector<int> detectCycleInDirectedGraph(int n, vector<vector<int>> & edges) {
        vector<int>ans;
        unordered_map<int, list<int>>adj;
        // To calculate the indegrees of a node
        vector<int>indegrees(n);
        //prepare adj list
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            //counts indegrees
            indegrees[v]++;
        }
        int totalNodesInTopo=0;
        queue<int>q;
        //push all the 0 indegree nodes to queue
        for(int i = 0; i<n; ++i){
           if (indegrees[i] == 0) {
              q.push(i);
           }
        }
        while(!q.empty()){
        	int frontnode=q.front();
        	q.pop();
        	//store the ans
            ans.push_back(frontnode + 1);
        	totalNodesInTopo++;
        	for( auto neighbor: adj[frontnode]){
          //Decrease the no of indegrees instead of marking visited
        		indegrees[neighbor]--;
          //if equal to 0 then push to the queue
        		if(indegrees[neighbor]==0){
        			q.push(neighbor);
        		}
        	}
        }
          //THE TOTAL NO OF NODES IN THE TOPOLOGICAL SORT SHOULD BE EQUAL TO THE NO OF NODES
          //BECAUSE  EVERY NODE IS VISITED ONLY ONCE
          //BUT IF A CYCLE  IS PRESENT THE NO OF NODES  ARE EITHER MORE OR LESS
          if(totalNodesInTopo==n){
            return ans;
          }
          return {};
        }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> mat(k, vector<int>(k, 0));

        vector<int>toporow = detectCycleInDirectedGraph(k, rowConditions);
        if(toporow.empty()){
            return {};
        }
        for(int i: toporow){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<int>topocol = detectCycleInDirectedGraph(k, colConditions);
        if(topocol.empty()){
            return {};
        }
        for(int i: topocol){
            cout<<i<<" ";
        }

        for(int i=0; i<k; i++){
            int rownum = toporow[i];
            for(int j=0; j<k; j++){\
                if(rownum == topocol[j]){
                    mat[i][j] = rownum;
                    break;
                }
            }
        }
        return mat;
    }
};
