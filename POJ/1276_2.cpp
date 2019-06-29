/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/06/19 20:11
	Description: dp[i,j] (i:前i种物品,j:填满容量为j的背包,dp:剩余的第i种物品的数量)
				复杂度O(VN) 
*/

#include <iostream> 
#include <cstring>

using namespace std;

int dp[15][100005];

void run(int cash,int N){
	
	dp[0][0] = 0;
	for(int i=1;i<=cash;i++){
		dp[0][i] = -1;
	}
	
	for(int i=1;i<=N;i++){
		int count,value;
		cin >> count >> value;
		
		for(int j=0;j<=cash;j++){
			if(dp[i-1][j]>=0){
				dp[i][j] = count;
			}else{
				dp[i][j] = -1;
			}
		}
		
		for(int j=0;j<=cash-value;j++){
			if(dp[i][j]>0){
				dp[i][j+value] = (dp[i][j+value] > dp[i][j]-1) ? dp[i][j+value] : dp[i][j]-1;
			}
		}
	}
	
	int res = cash;
	while(res>=0){
		if(dp[N][res]>=0) break;
		res --;
	}

	
	cout << res << endl;
}

int main(){
	int cash,N;
	
	while(cin >> cash >> N){
		run(cash,N);
	}
	
	return 0;
}


