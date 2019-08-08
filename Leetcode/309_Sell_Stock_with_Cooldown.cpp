/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/08/19 09:20
	Description: 
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
        int profit = 0,lastProfit = 0;
        int *sell = new int[size+5];
        int *buy = new int[size+5];
        
        memset(sell,0,sizeof(int)*(size+5));
        memset(buy,0,sizeof(int)*(size+5));
        
        for(int i=1;i<size;i++){        	
//        	int maxV = 0;
//        	for(int j=0;j<i-1;j++){
//        		if(sell[j]>maxV) maxV = sell[j];
//			}
			buy[i] = lastProfit;
			
			int maxV = 0;
			for(int j=0;j<i;j++){
				if(buy[j]+prices[i]-prices[j]>maxV){
					maxV = buy[j]+prices[i]-prices[j];
				}
			}
			sell[i] = maxV;
			if(sell[i]>profit) {
				lastProfit = profit;
				profit = sell[i];
			}else{
				lastProfit = profit;
			}
		}
        
        
        return profit;
    }
};


int main(){
	
//	vector<int> test = {1,2,3,0,2};
	vector<int> test = {3,1,2,1,1};
//	vector<int> test = {1,4,2};

	Solution su = Solution();
	
	cout << su.maxProfit(test) << endl;
	return 0;
}
