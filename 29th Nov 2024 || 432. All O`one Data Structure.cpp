class AllOne {
    private:
    unordered_map<string,int> mp;
    set<pair<int,string>> st;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mp.find(key)!=mp.end()){
            st.erase({mp[key],key});
        }
        mp[key]++;
        st.insert({mp[key],key});
    }
    
    void dec(string key) {
        st.erase({mp[key],key});
        mp[key]--;
        if(mp[key]==0){
            mp.erase(key);
        }
        else{
            st.insert({mp[key],key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0) return "";
        return st.rbegin()->second;
    }
    
    string getMinKey() {
        if(st.size()==0) return "";
        return st.begin()->second;
    }
};
