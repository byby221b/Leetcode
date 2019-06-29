/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/06/19 09:00
	Description: 最长子段和，还需要再熟练一些 
*/

#include <iostream>

using namespace std;

int main(){
	int k;
	cin >> k;
	bool flag = false;
	long long *data = new long long[k+5];
	long long *dp = new long long[k+5];
	long long *left = new long long[k+5];
	
	for(int i=0;i<k;i++){
		cin >> data[i];
		if(data[i]>=0) flag = true;
	}
	
	if(!flag){
		cout << "0 " << data[0] << " " << data[k-1] << endl;
	}else{
		dp[0] = data[0];
		left[0] = data[0];
		for(int i=1;i<k;i++)	{
			if(data[i] > dp[i-1] + data[i]){
				dp[i] = data[i];
				left[i] = data[i];
			}else{
				dp[i] = dp[i-1] + data[i];
				left[i] = left[i-1];
			}
		}
		
		int maxIdx = 0;
		int maxV = dp[0];
		for(int i=0;i<k;i++){
			if(dp[i] > maxV){
				maxIdx = i;
				maxV = dp[i];
			}
		}
		
		cout << dp[maxIdx] << " " << left[maxIdx] << " " << data[maxIdx] << endl;
	}
	
	delete [] data;
	delete [] dp;
	delete [] left;
	
	return 0;
}

