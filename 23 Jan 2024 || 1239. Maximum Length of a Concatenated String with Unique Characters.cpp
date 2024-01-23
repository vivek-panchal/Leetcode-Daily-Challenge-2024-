class Solution {
private:
    
    bool compare(vector<int> &selected, string &currString){
        vector<int> selfCheck(26, 0); 
        
        for (int i = 0; i < currString.size(); i++){
            if (selfCheck[currString[i] - 'a'] == 1)
                return false ;

            selfCheck[currString[i] - 'a'] = 1 ;
        }

        for (int i = 0; i < currString.size(); i++){
            if (selected[currString[i] - 'a'] == 1)
                return false ;
        }
        return true ;
    }

    int help(int i, vector<string> &arr, vector<int> &selected, int len){
        // If we reach till the end of arr[], we need to return the max Length we have taken till now
        if (i == arr.size() ) {
            return len ;
        }

        string currString = arr[i] ;
        // If currString contains Duplicate Characters or it's characters have already been taken, we have no option but to skip curr String and move to next Index
        
        if (compare(selected, currString) == false){
            // skip the currString
            return help(i + 1, arr, selected, len) ;
        }
        // Else we have two options, One to include CurrString OR another option is to Skip CurrString
        else{
            // If we pick the currString, all it's characters must be marked as taken in selected [] vector
            
            for (int j = 0; j < currString.size(); j++){
                selected[currString[j] - 'a'] = 1 ;
            }

            // Increase the length by currString.size() 
            len += currString.size() ;

            // Ask Recursion to do rest of task
            int op1 = help(i + 1, arr, selected, len) ; 

            // Backtrack and unmark all the characters of currString as NOT TAKEN in selected[] vector
            for (int j = 0; j < currString.size(); j++){
                selected[currString[j] - 'a'] = 0 ;
            }

            // As we are not including currString, we should decrease len by currString.size()
            len -= currString.size() ;

            // Ask recursion to do rest of the task
            int op2 = help(i + 1, arr, selected, len) ;

            // Lastly, we will return the max of (op1 , op2) whichever brings the Longest Length
            return max(op1, op2) ;
        }
    }

public:
    int maxLength(vector<string>& arr) {
        
        // selected [] vector will keep track of all the characters which have been taken yet
        vector<int> selected(26, 0) ;
        return help(0, arr, selected, 0);
        
    }
};

/*
    Time Complexity:  O(K * 2^N)
    Space Complexity: O(N)
*/
