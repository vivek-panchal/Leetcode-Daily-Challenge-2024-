class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> v;
    int size;
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m[val] = size;
            v.push_back(val);
            size++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int ind = m[val];
            v[ind] = v[size-1];
            v.pop_back();
            m[v[ind]] = ind;
            m.erase(val);
            size--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ans = rand()%size;
        return v[ans];
    }
};
