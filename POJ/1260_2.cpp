/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/06/19 20:58
	Description: dp[i]表示已知i类珍珠时购买的最低价格 
*/

#include <iostream>

using namespace std;

void run(){
	int c;
	cin >> c;
	
	int *nums = new int[c+5];
	int *price = new int[c+5];
	int *sum = new int[c+5] ;
	
	sum[0] = 0;
	for(int i=1;i<=c;i++){
		cin >> nums[i] >> price[i];
		sum[i] = nums[i] + sum[i-1];
	}
	
	
	int *dp = new int[c+5];
	dp[0] = 0;
	
	for(int i=1;i<=c;i++){
		int minV = -1;
		for(int j=0;j<=i-1;j++)	{
			int tmp = (sum[i] - sum[j] + 10) * price[i] + dp[j];
			if(minV==-1 || tmp<minV){
				minV = tmp;
			}
		}
		dp[i] = minV;
	}
	
	cout << dp[c] << endl;
	
	delete [] nums;
	delete [] price;
	delete [] dp;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		run();
	}
}

