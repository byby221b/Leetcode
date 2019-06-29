/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/06/19 19:10
	Description: 多重背包问题，二进制拆分 
				复杂度 O(V*log\sum{M_i}) 
*/

#include <iostream> 
#include <cstring>

using namespace std;

void run(int cash,int N){
		
	int *dp = new int[cash+5];
	
	memset(dp,0,sizeof(int) * (cash + 5));
	
	dp[0] = 1;
	
	for(int i=0;i<N;i++){
		int count,value;
		cin >> count >> value;
		
		for(int j=1;j<=count;j*=2){
			int curr_value = j*value;
			for(int k=cash;k>=curr_value;k--){
				if(dp[k]==0 && dp[k-curr_value]==1) dp[k]=1;
			}
			count -= j;
		}
		if(count>0){
			int curr_value = count*value;
			for(int k=cash;k>=curr_value;k--){
				if(dp[k]==0 && dp[k-curr_value]==1) dp[k]=1;
			}
		}
	}
	
	int res = cash;
	while(res>=0){
		if(dp[res]==1) break;
		res --;
	}
	
	delete [] dp;
	
	cout << res << endl;
}

int main(){
	int cash,N;
	
	while(cin >> cash >> N){
		run(cash,N);
	}
	
	return 0;
}

