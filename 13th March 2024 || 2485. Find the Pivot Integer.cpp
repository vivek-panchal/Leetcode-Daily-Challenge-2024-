class Solution {
public:
    int pivotInteger(int n) {

        int totalSum = (n*(n+1))/2;
        int start=1;
        int end = n;

        while(start<=end){
            int mid = start+(end-start)/2;

            int firstHaflSum = (mid*(mid+1))/2;
            int secondHalfSum = (totalSum-firstHaflSum)+mid;

            if(firstHaflSum==secondHalfSum)
             return mid;

            else if(firstHaflSum<secondHalfSum)
             start = mid+1;


            else
              end = mid-1; 
        }

        return -1;  
    }
};
