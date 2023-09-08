class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp={1};
        ans.push_back(temp);
        if(numRows==1) {
            return ans;
        }
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2) {
            return ans;
        }
        for(int i=3; i<=numRows; i++) {
            vector<int> row = {1};
            for(int i=0; i<temp.size()-1; i++) {
                row.push_back(temp[i] + temp[i+1]);
            }
            row.push_back(1);
            ans.push_back(row);
            temp = row;
        }
        return ans;
    }
};