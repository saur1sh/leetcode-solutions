class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int i=0, j=1;
        int gmax=0;
        while(j<prices.size()){
            if(prices[j]>prices[i]){
                int pr = prices[j]-prices[i];
                if(pr>gmax)
                    gmax=pr;
            }
            else
                i=j;
            j++;
        }
        return gmax;
    }
};