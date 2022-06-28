#include<unordered_set>
class Solution {
public:
    bool isAnagram(string s, string t) {
        int fs[26] = {0}, ft[26]={0};
        for(char ch: s){
            fs[ch-'a']++;
        }
        for(char ch: t){
            ft[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(ft[i]!=fs[i])
                return false;
        }
        return true;
    }
};