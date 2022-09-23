class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map <char, int> mp;
        for(auto &c: s){
            ++mp[c];
            if(mp[c]>(n+1)/2) return "";
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto c: mp){
            pq.push({c.second, c.first});
        }
        
        pair<int, char> prevMax = {0, 'n'};
        string ans = "";
        while(pq.size()){
            pair<int, char> temp = pq.top();
            pq.pop();
            ans+=temp.second;
            temp.first--;
            if(prevMax.first>0){
                pq.push(prevMax);
            }
            prevMax = temp;
        }
        if(ans.length()==n) return ans;
        return "";
    }
};