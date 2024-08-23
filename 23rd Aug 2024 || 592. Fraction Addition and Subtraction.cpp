class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.size();
        int i=0;
        int numoOld=0,denoOld=1;
        while(i<n){

             int sign=1;
             if(expression[i]=='-' || expression[i]=='+'){
                if(expression[i]=='-')
               sign=-1;
               i++;
             }

             int numoNew=0;
             int denoNew=0;

             while(i<n && isdigit(expression[i])){
                numoNew=numoNew*10+(expression[i]-'0');
                i++;
             }
             numoNew*=sign;
             i++;
             while(i<n && isdigit(expression[i])){
                denoNew=denoNew*10+(expression[i]-'0');
                i++;
             }
             numoOld=numoOld*denoNew+numoNew*denoOld;
             denoOld*=denoNew;
             int GCD=gcd(abs(numoOld),denoOld);
             numoOld/=GCD;
             denoOld/=GCD;
        }
        return to_string(numoOld)+"/"+to_string(denoOld);
    }
};
