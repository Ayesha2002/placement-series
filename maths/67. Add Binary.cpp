class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;

        while(i>=0 || j>=0 || carry){
            if (i>=0)
            carry+= a[i--]-'0';
            if (j>=0)
            carry += b[j--]-'0';
            answer+=carry %2 +'0';
            carry/=2;
        }
        reverse(begin(answer), end(answer));
        return answer;
    }
};
