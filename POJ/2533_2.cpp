/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 20:45
	Description: �����������O(N*log(N))д�� 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	int *data = new int[N+5];
	int *dp = new int[N+5];
	
	for(int i=0;i<N;i++){
		cin >> data[i];
	}
	
	int maxLen = 0;
	dp[maxLen] = -1;
	for(int i=0;i<N;i++){
		if(data[i]>dp[maxLen]){
			maxLen ++;
			dp[maxLen] = data[i];
		}else{
			int idx = lower_bound(dp,dp+maxLen+1,data[i]) - dp;
			dp[idx] = data[i];
		}
	}
	
	cout << maxLen << endl;
	
	delete [] data;
	delete [] dp;
	
	return 0;
}

