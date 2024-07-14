class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> mul;
        mul.push(1);
        int p = 1;
        map<string, int> mp;

        int n = formula.size();
        string x = "";
        int digit = 0;
        int m = 1;
        for(int i = n-1; i>=0; i--) {
            // extract the digits first
            if(isdigit(formula[i])) {
                digit = digit + (formula[i]-'0')*m;
                m *= 10;
            }
            // push the digit in the stack 
           else if(formula[i] == ')') {
                if(digit>0){
                p = p*digit;
                mul.push(digit);
                }
                digit = 0;
                m=1;
            } else if(formula[i] == '(' && !mul.empty()) { // remove the digit from the stack
                p = p/mul.top();
                mul.pop();
            }
             else if(isalpha(formula[i])) {
                if(formula[i] >= 'A' && formula[i] <='Z') {
                    mp[x+formula[i]] += (digit == 0? 1: digit)*p;
                    digit = 0;
                    m=1;
                } else {
                    string t = x+ formula[i-1] + formula[i];
                    mp[t] += (digit == 0? 1: digit)*p;
                    cout<<digit<<" "<<p<<"\n";
                    digit = 0;
                    m=1;
                    i-=1;
                }
            }
        }
        string ans = "";
        for(auto m : mp) {
        ans+=m.first;
        if(m.second>1)
        ans+=to_string(m.second);
        }
        return ans;
    }
};
