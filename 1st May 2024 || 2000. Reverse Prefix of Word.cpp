class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=0;
        if(word.find(ch)==-1||word[0]==ch){
            return word;
        }else{
            index=word.find(ch);
        }
        reverse(word.begin(), word.begin()+index+1);
        return word;
    }
};
