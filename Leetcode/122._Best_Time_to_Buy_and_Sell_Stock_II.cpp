#include <iostream>
#include <vector>
using namespace std;

/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/08/19 11:42
	Description: 思路1：dp,每一天都有buy/sell两个状态，记录该状态下的累积最大收益;
				 思路2：直接求相邻两天之间的收益，将正收益累加即可 
*/

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//  		int size = prices.size();
//  		if(size<=1) return 0;
//  		
////		int *buy = new int[size+5];
////		int *sell = new int[size+5];
//		
////		buy[0] = -prices[0];
////		sell[0] = 0;
//		
//		int maxBuy = -prices[0],maxSell = 0;
//		
//		int buyCurr,sellCurr;
//		for(int i=1;i<size;i++){
//			buyCurr = maxSell - prices[i];
//			sellCurr = maxBuy + prices[i];
//			
//			if(buyCurr>maxBuy) maxBuy=buyCurr;
//			if(sellCurr>maxSell) maxSell=sellCurr;
//		}
//		
//		return maxSell;
//		        
//    }
//};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
  		int size = prices.size();
  		if(size<=1) return 0;
  		
		int maxSell = 0;
		int tmp;
		for(int i=0;i<size-1;i++){
			tmp = prices[i+1]-prices[i];
			if(tmp>0) maxSell+=tmp;
		}
		
		return maxSell;
		        
    }
};

int main(){
	vector<int> test = {7,1,5,3,6,4};
//	vector<int> test = {1,2,3,4,5};
//	vector<int> test = {7,6,4,3,1};
//	vector<int> test = {1};
	
	Solution su = Solution();
	int res = su.maxProfit(test);
	
	cout << res << endl;
	return 0;
}

