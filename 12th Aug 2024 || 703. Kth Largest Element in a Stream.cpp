class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int temp;
    KthLargest(int k, vector<int>& nums) {
        temp = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }  
    }
    
    int add(int val) { 
       pq.push(val);

        while(pq.size()>temp){
            pq.pop();
        }
        return pq.top();
    }
};
