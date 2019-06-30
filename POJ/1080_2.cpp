/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 20:30
	Description: 最长公共子序列的变形,dp[i][j]表示strA[:i]和strB[:j]的最大分数
				状态转移有三种情况:
					1.strA[i]与str[j]对齐 
					2.strA[i-1]与str[j]对齐 
					3.strA[i]与str[j-1]对齐 
*/
#include <iostream> 
#include <cstring>


using namespace std;

int dp[105][105];

int matrix[5][5] = {
					{5,-1,-2,-1,-3},
					{-1,5,-3,-2,-4},
					{-2,-3,5,-2,-2},
					{-1,-2,-2,5,-1},
					{-3,-4,-2,-1,0}
					};

int ch2idx(char ch){
	int res;
	switch(ch){
		case 'A': res = 0;break;
		case 'C': res = 1;break;
		case 'G': res = 2;break;
		case 'T': res = 3;break;
		default:  res = 4;break;
	}
	
	return res;
}

int score(char a,char b){
	return matrix[ch2idx(a)][ch2idx(b)];
}

void run(){
	int lenA,lenB;
	string strA,strB;
	
	cin >> lenA >> strA;
	cin >> lenB >> strB;	
	
	strA = "-" + strA;
	strB = "-" + strB;
	

	int padding = 0;
	dp[0][0] = 0;
	for(int i=1;i<=lenA;i++){
		if(i-1>0){
			padding += score(strA[i-1],'-');
		}
		dp[i][0] = padding + score(strA[i],'-');
	}
	padding = 0;
	for(int j=1;j<=lenB;j++){
		if(j-1>0){
			padding += score('-',strB[j-1]);
		}
		dp[0][j] = padding + score('-',strB[j]);
	}
	
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			dp[i][j] = dp[i-1][j-1] + score(strA[i],strB[j]);
			int mis1 = dp[i-1][j] + score(strA[i],'-');
			int mis2 = dp[i][j-1] + score('-',strB[j]);
			if(mis1>dp[i][j]) {
				dp[i][j] = mis1;
			}
			if(mis2>dp[i][j]){
				dp[i][j] = mis2;
			}
		}
	}
	
//	for(int i=0;i<=lenA;i++){
//		for(int j=0;j<=lenB;j++){
//			cout << dp[i][j] << "\t";
//		}
//		cout << endl;
//	}
//	cout << "**************************" << endl;
	
	cout << dp[lenA][lenB] << endl;
//	cout << lenA <<" " << lenB << endl;
//	cout << strA << endl;
//	cout << strB << endl;
//	cout << "==========================" << endl;

	

}

int main(){
	int T;
	
	cin >> T;
	
	for(int i=0;i<T;i++){
		run();
	}
	
	return 0;
}
