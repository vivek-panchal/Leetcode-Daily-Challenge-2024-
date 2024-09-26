class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) { 
      mp[start]++;
      mp[end]--;
        
        int sum=0;
        
        for(auto c:mp){
            sum+=c.second;
            if(sum>1){
               mp[start]--;
                mp[end]++;
            return false;;
            } 
        }
        return true;   
        }
};
