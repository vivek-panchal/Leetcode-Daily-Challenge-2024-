class Solution {
public:

long long int getPallindrome(long long int leftPart,bool even){
    long long int result = leftPart;
    if(!even)
    leftPart /= 10;

    while(leftPart > 0){
        result = (result*10)+(leftPart%10);
        leftPart /= 10;
    }
    return result;
}
    string nearestPalindromic(string n) {
        int size = n.size();
        bool even = 0;
        int mid = n.size()/2;
        if(n.size()%2 == 0)
        even = 1;

        if(even)
        mid--;

        if(size == 1)
        return to_string(stoll(n)-1);

        long long int leftPart = stoll(n.substr(0,mid+1));

        vector<long long int> cases;

        //Converting ending digits to starting digits.
        cases.push_back(getPallindrome(leftPart,even));
        //Incrementing middle
        cases.push_back(getPallindrome(leftPart+1,even));
        //Decrementing middle
        cases.push_back(getPallindrome(leftPart-1,even));
        //Reduce digit by 1
        cases.push_back(pow(10,size-1)-1);
        //Increase digit by 1
        cases.push_back(pow(10,size)+1);

        long long int ans = LLONG_MAX;
        long long int diff = LLONG_MAX;
        long long int value = stoll(n);

        for(auto it:cases){
            if(it == value)
            continue;
            long long int currDiff = abs(it-value);

            if(diff > currDiff){
                ans = it;
                diff = currDiff;
            }
            else if(diff == currDiff){
                ans = min(ans,it);
            }
        }
        return to_string(ans);
    }
};
