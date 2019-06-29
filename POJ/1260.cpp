/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/06/19 20:29
	Description: 动态规划
				 dp[i][j] (i:第i类珍珠,j:使用第j类珍珠的价格购买,dp:所用的最低价格)
*/

#include <iostream> 
#include <cstring>
using namespace std;

int dp[105][105];

void run(){
	int c;
	cin >> c;
	
	int *number = new int[c+5];
	int *price = new int[c+5];
	
	
	for(int i=0;i<c;i++){
		cin >> number[i] >> price[i];
	}
	
	memset(dp,-1,sizeof(dp));
	dp[c-1][c-1] = (number[c-1]+10)* price[c-1];
	
	for(int i=c-2;i>=0;i--){
		int minV = -1;
		for(int j=c-1;j>i;j--){
			if(dp[i+1][j]>=0){
				dp[i][j] = dp[i+1][j] + number[i] * price[j];
				if(minV==-1 || dp[i+1][j]<minV){
					minV = dp[i+1][j];
				}
			}
		}
		dp[i][i] = minV + (number[i]+10)*price[i];
	}
	
	int minV = dp[0][0];
	for(int j=1;j<c;j++){
		if(dp[0][j]<minV) minV = dp[0][j];
	}
	
	cout << minV << endl;
	
	delete [] number;
	delete [] price;

}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		run();
	}
	
	return 0;
}

