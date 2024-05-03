class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        int i = 0, j= 0;
        
        while(i<n1 && j<n2){
            int num1 = 0, num2 = 0;
            while(i<n1 && version1[i]!='.'){
                num1 = 10*num1 + (version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                num2 = 10*num2 + (version2[j]-'0');
                j++;
            }
            if(num1 < num2){
                return -1;
            }
            if(num1 > num2){
                return 1;
            }
            i++;
            j++;
        }

        while(i<n1){
            if(version1[i]!='.' && version1[i]!='0'){
                return 1;
            }
            i++;
        }
        while(j<n2){
            if(version2[j]!='.' && version2[j]!='0'){
                return -1;
            }
            j++;
        }
        return 0;
    }
};
