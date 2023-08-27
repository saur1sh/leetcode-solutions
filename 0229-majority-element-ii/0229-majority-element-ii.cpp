class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int y(-1), z(-1), cy(0), cz(0);
        for(const int &e: nums) {
            if(e==y)
                cy++;
            else if(e==z)
                cz++;
            else if(!cy) y=e, cy=1;
            else if(!cz) z=e, cz=1;
            else
                cy--, cz--;
        }
        cy=cz=0;
        for(const int &e: nums) {
            if(e==y) cy++;
            else if(e==z) cz++;
        }
        vector<int> ans;
        if(cy>size(nums)/3) ans.push_back(y);
        if(cz>size(nums)/3) ans.push_back(z);
        return ans;
    }
};