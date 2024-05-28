class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int left=0, right=0, maxi=0;
      while(right < t.size()) {
        maxCost -= abs(s[right] - t[right]);
        while(maxCost < 0) {
            maxCost += abs(s[left] - t[left]);
            left++;
        }
        right++;
        maxi = max(maxi, right-left); 
      }
      return maxi;
    }
};
