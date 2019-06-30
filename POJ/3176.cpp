/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 14:41
	Description: ¼òµ¥dp 
*/

#include <iostream>

using namespace std;

bool exist(int i,int j){
	return (j>=0 && j<=i);
}

int calIdx(int i,int j){
	return (i*(i+1)/2 + j);
}

int main(){
	int N;
	
	cin >> N;
	
	int total = N*(N+1)/2;
	int *data = new int[total + 5];
	int *dp = new int[total+5];
	
	for(int i=0;i<total;i++){
		cin >> data[i];
	}
	
	dp[0] = data[0];
	
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			int idx = calIdx(i,j);
			bool left = exist(i-1,j-1);
			bool right = exist(i-1,j);
			if(left && right){
				dp[idx] = (dp[calIdx(i-1,j-1)] > dp[calIdx(i-1,j)]) ? dp[calIdx(i-1,j-1)] + data[idx] : dp[calIdx(i-1,j)] + data[idx];
			}else if(left){
				dp[idx] = dp[calIdx(i-1,j-1)] + data[idx];
			}else if(right){
				dp[idx] = dp[calIdx(i-1,j)] + data[idx];
			}
		}
	}
	
//	for(int i=0;i<N;i++){
//		for(int j=0;j<=i;j++){
//			cout << dp[calIdx(i,j)] << " ";
//		}
//		cout << endl;
//	}
	
	int maxV = -1;
	for(int j=0;j<N;j++){
		if(dp[calIdx(N-1,j)]>maxV){
			maxV = dp[calIdx(N-1,j)];
		}
	}
	cout << maxV << endl;
	
	delete [] data;
	delete [] dp;
	return 0;
}

