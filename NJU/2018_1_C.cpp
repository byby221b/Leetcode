/*
	Name: 
	Copyright: 
	Author: 
	Date: 24/06/19 09:22
	Description: dp问题,固定零件和带宽,最小化价格
				POJ 1018 
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int mCount[105];
int bandwidth[105][105];
int price[105][105];
int dp[105][1000];
int n;


int minValue(int a,int b){
	if(a<0){
		return b;
	}else{
		return (a < b) ? a : b;
	}
}


void run(){
	
	int minBand = 1e6;
	int maxBand = 0;
	cin >> n;
	//input
	for(int i=0;i<n;i++){
		cin >> mCount[i];
		for(int j=0;j<mCount[i];j++){
			cin >> bandwidth[i][j] >> price[i][j];
			if(bandwidth[i][j]<minBand) minBand = bandwidth[i][j];
			if(bandwidth[i][j]>maxBand) maxBand = bandwidth[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=minBand;j<=maxBand;j++){
			dp[i][j] = 1e6;
		}
	}
	
	for(int j=0;j<mCount[0];j++){
		dp[0][bandwidth[0][j]] = minValue(dp[0][bandwidth[0][j]],price[0][j]);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<mCount[i];j++){
			int currB = bandwidth[i][j];
			int currP = price[i][j];
			
			//带宽小于当前带宽时，需要更新对应带宽值 
			for(int k=minBand;k<=currB;k++){
				dp[i][k] = minValue(dp[i][k],dp[i-1][k]+currP);
			}
			//带宽大于当前带宽时，可以更新当前带宽 
			for(int k=currB;k<=maxBand;k++){
				dp[i][currB] = minValue(dp[i][currB],dp[i-1][k] + currP);
			}
			
		}
	}
	
	double maxRes = 0;
	for(int k=minBand;k<=maxBand;k++){
		if(dp[n-1][k]<1e6){
			double currRes = double(k) / double(dp[n-1][k]);
			if(currRes>maxRes){
				maxRes = currRes;
			}
		}
	}
	
	printf("%.3f\n",maxRes);
//	cout << maxV << endl;
}

int main(){
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		run();
	}
	return 0;
}
