/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/08/19 09:20
	Description: 状态转移: 买之后，卖之后，冷冻期 
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
public:
	
	int myMax(int a,int b){
		return (a>b ? a : b);
	}
	
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int size = prices.size();
        int sell = 0,buy = -prices[0], cooldown = 0;
        int tmpSell,tmpBuy,tmpCooldown;
        
        for(int i=1;i<size;i++){        	
			tmpSell = sell;
			tmpBuy = buy;
			tmpCooldown = cooldown;
			
			sell = myMax(tmpBuy+prices[i],tmpSell);
			buy = myMax(cooldown-prices[i],tmpBuy);
			cooldown = myMax(tmpSell,tmpCooldown);
		}
        
        
        return myMax(sell,cooldown);
    }
};


int main(){
	
//	vector<int> test = {1,2,3,0,2};
//	vector<int> test = {3,1,2,1,1};
	vector<int> test = {1,4,2};

	Solution su = Solution();
	
	cout << su.maxProfit(test) << endl;
	return 0;
}
