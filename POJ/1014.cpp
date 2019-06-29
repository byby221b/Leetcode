/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/06/19 18:34
	Description: 多重背包问题，采用O(Vn)方法求解 
				问题转化：将物品放到容量为sum/2的背包中,能够恰好装满说明可以平分 
*/

#include <iostream>

using namespace std;

bool run(int count){
	int sum = 0;
	int num[10];
	
	for(int i=1;i<=6;i++){
		cin >> num[i];
		sum += (num[i] * i);
	}
	
	if(sum==0){
		return false;
	}
	
	if(sum%2==1){
		cout << "Collection #"<< count <<":" << endl;
		cout << "Can't be divided." << endl << endl;
		return true;
	}
	
	int *dp = new int[sum/2+5];
	
	dp[0] = 0;
	for(int i=1;i<=(sum/2);i++){
		dp[i] = -1;
	}
	
	for(int i=1;i<=6;i++){
		for(int j=0;j<=(sum/2);j++){
			if(dp[j]>=0){
				dp[j] = num[i];
			}else{
				dp[j] = -1;
			}
		}
		
		for(int j=0;j<=(sum/2-i);j++){
			if(dp[j]>0){
				dp[j+i] = (dp[j+i] > dp[j] - 1) ? dp[j+i] : dp[j] - 1;
			}
		}
	}
	
	cout << "Collection #"<< count <<":" << endl;
	if(dp[sum/2]>=0){
		cout << "Can be divided." << endl << endl;
	}else{
		cout << "Can't be divided." << endl << endl;
	}
	
	delete [] dp;
	
	return true;
}


int main(){
	
	int count = 1;
	while(run(count)){
		count ++;
	}
	
	return 0;
}
