class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)
            return {1};
        else if(rowIndex==1)
            return {1,1};
        vector<int> prev = {1,1};
        vector<int> next;
        for(int r=2; r<=rowIndex; r++) {
            for(int i=0; i<prev.size()+1; i++) {
                if(i==0 || i==prev.size())
                    next.push_back(1);
                else {
                    next.push_back(prev[i-1]+prev[i]);
                }
            }
            prev = next;
            next.clear();
        }
        return prev;
    }
};