/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 21:02
	Description: 最长公共子序列
				此题使用了滚动数组,正常写法会MLE,递推公式只和相邻几行有关时可以借鉴 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int dp[2][5005];

int main(){
	
	int N;
	string strA;
	
	cin >> N >> strA;
	
	string strB = strA;
	reverse(strB.begin(),strB.end());
	
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(strA[i-1]==strB[j-1]){
				dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
			}else{
				dp[i%2][j] = (dp[(i-1)%2][j] > dp[i%2][j-1]) ? dp[(i-1)%2][j] : dp[i%2][j-1];
			}
		}
	}
	
	cout << N - dp[(N)%2][N] << endl;
	
	return 0;
}
