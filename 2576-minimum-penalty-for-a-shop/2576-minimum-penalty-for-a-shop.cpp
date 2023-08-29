class Solution {
public:
    int bestClosingTime(string cust) {
        pair<int, int> open={0, 0};
        int sum=0;
        for(int i=0; i<cust.length(); i++) {
            if(cust[i]=='Y')
                sum++;
            else
                sum--;
            if(sum>open.first)
                open = {sum, i};
        }
        if(open.second==0 && open.first==0)
            return 0;
        return open.second+1;
    }
};