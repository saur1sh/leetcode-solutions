class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0)
            return 0;
        int ans = 1, inc=0, dec=0, peak=0;
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i-1]==ratings[i]) {
                inc=0;
                dec=0;
                peak=0;
                ans+=1;
            }
            else if(ratings[i-1]<ratings[i]) {
                inc++;
                dec=0;
                peak=inc;
                ans += 1 + inc;
            }
            else {
                dec++;
                inc=0;
                ans += 1 + dec - (int)(peak>=dec);
            }
        }
        return ans;
    }
};