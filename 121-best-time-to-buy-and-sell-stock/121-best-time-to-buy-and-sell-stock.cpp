class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int gmax=0, l=0, r=1;
        while(r<prices.size()){
        	if(prices[r]<prices[l]){
        		l=r;
        		r++;
        	}
        	else{
        		gmax=max(prices[r]-prices[l], gmax);
        		r++;
        	}
        }
        return gmax;
    }
};