class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        queue<string> q;
        for (int i = 0; i < sentence.size(); i++) {
            while (i < sentence.size() && sentence[i] == ' ') {
                i++;
            }
            string s = "";
            while (i < sentence.size() && sentence[i] != ' ') {
                s += sentence[i];
                i++;
            }
            if (!s.empty()) {
                q.push(s);
            }
        }

        string ans = "";
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            int val = INT_MAX;
            string ans1 = s;

            for (int i = 0; i < dict.size(); i++) {
                string comp = dict[i];
                bool flag = true;
                int j = 0;
                for (j = 0; j < comp.size(); j++) {
                    if (j >= s.size() || comp[j] != s[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && j > 0) { 
                    if (val >= j) {
                        ans1 = comp;
                        val = j;
                    }
                }
            }
            ans += ans1 + " ";
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
