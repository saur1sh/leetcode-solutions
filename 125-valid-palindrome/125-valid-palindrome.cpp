class Solution {
public:
    bool isValid(char c){
        int l = (int)c;
        if(l>47&&l<58 || l>64&&l<91 || l>96&&l<123){
            return true;
        }
        else 
            return false;
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<=j){
            if(isValid(s[i])){
                if(isValid(s[j])){
                    if((int)s[i]<91 && (int)s[i]>64){
                        s[i]+=32;
                    }
                    if((int)s[j]<91 && (int)s[j]>64){
                        s[j]+=32;
                    }
                    if(s[i]==s[j]){
                        i++;
                        j--;
                    }
                    else
                        return false;
                }
                else
                    j--;
            }
            else
                i++;
            }
        return true;
    }
};