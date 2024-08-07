class Solution {
public:
    string solve(int num, unordered_map<int, string> digits, unordered_map<int, string> tenToNineteen, unordered_map<int, string> tenToNinety){
        if(num<10){
            return digits[num];
        }

        if(num<20){
            return tenToNineteen[num];
        }

        if(num<100){
            return tenToNinety[num/10] + (num%10!=0 ? " "+digits[num%10] : ""); 
        }

        if(num<1000){
            return solve(num/100, digits, tenToNineteen, tenToNinety) + " Hundred" + ((num%100!=0) ? " " + solve(num%100,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        if(num<1000000){
            return solve(num/1000,  digits, tenToNineteen, tenToNinety) + " Thousand" + (num%1000!=0 ? " "+solve(num%1000,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        if(num<1000000000){
            return solve(num/1000000,  digits, tenToNineteen, tenToNinety) + " Million" + (num%1000000!=0 ? " "+solve(num%1000000,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        return solve(num/1000000000,  digits, tenToNineteen, tenToNinety) + " Billion" + (num%1000000000!=0 ? " "+solve(num%1000000000, digits, tenToNineteen, tenToNinety) : ""); 

        
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        unordered_map<int, string> digits={
            {0, ""},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"}
        };

        unordered_map<int, string> tenToNineteen={
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
        };

        unordered_map<int, string> tenToNinety={
            {1, "Ten"},
            {2, "Twenty"},
            {3, "Thirty"},
            {4, "Forty"},
            {5, "Fifty"},
            {6, "Sixty"},
            {7, "Seventy"},
            {8, "Eighty"},
            {9, "Ninety"}
        };

        return solve(num, digits, tenToNineteen, tenToNinety);
    }
};
