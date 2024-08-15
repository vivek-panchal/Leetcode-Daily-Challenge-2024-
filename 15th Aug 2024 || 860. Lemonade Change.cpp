class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0 ; i < bills.size(); i++){
            if(bills[i] == 5)
                five++;
            else if(bills[i] == 10){
                if(five == 0)
                    return false;
                
                five--;
                ten++;
            }
            else{
                // bills[i]==20
                if(five == 0)
                    return false;
                else if(ten >= 1 && five >= 1){
                    five--;
                    ten--;
                }
                else if(five >= 3)
                    five -= 3;
                else 
                    return false; 
            }    
        }
        return true;
    }
};
