#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll dist[26][26];
        for(ll i=0; i<26; i++){
            for(ll j=0; j<26; j++){
                if(i==j) dist[i][j]=0;
                else dist[i][j]=1e18;
            }
        }
        int n = original.size();
        for(ll i=0; i<n; i++){
            dist[original[i]-'a'][changed[i]-'a'] = min((ll)cost[i],dist[original[i]-'a'][changed[i]-'a']);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        ll ans = 0;
        int m = source.size();
        for(int i=0; i<m; i++){
            if(dist[source[i]-'a'][target[i]-'a']==1e18){
                return -1;
            }
            ans += dist[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};
