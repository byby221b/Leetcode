/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 20:37
	Description: 最长递增子序列 
*/

#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	
	int *data = new int[N+5];
	int *dp = new int[N+5];
	
	for(int i=0;i<N;i++){
		cin >> data[i];
	}
	
	dp[0] = 1;
	for(int i=1;i<N;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(data[j]<data[i] && dp[j]+1>dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	int maxV = 1;
	for(int i=0;i<N;i++){
		if(dp[i]>maxV) maxV = dp[i];
	}
	
	cout << maxV << endl;
	
	delete [] data;
	delete [] dp;
	
	return 0;
}
