class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        while(mask<num){
            mask= (mask<<1)|1;
        }
        int ans = (~num)& mask;
        return ans;
    }
};
