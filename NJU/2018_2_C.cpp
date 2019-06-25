/*
	Name: 
	Copyright: 
	Author: 
	Date: 25/06/19 11:13
	Description: 最长递增子序列
				注意：递增序列和递减序列可能没有公共点，例如1,2,2答案应该是0 
*/

#include <iostream>

using namespace std; 

int main(){
	int n;
	cin >> n;
	
	double *height = new double[n];
	
	for(int i=0;i<n;i++){
		cin >> height[i];
	}
	
	int *dp1 = new int[n];
	int *dp2 = new int[n];
	
	dp1[0] = 1;
	for(int i=1;i<n;i++){
		int maxL = 1;
		for(int j=0;j<i;j++){
			if((height[j] < height[i]) && (dp1[j] + 1 > maxL)){
				maxL = dp1[j] + 1;
			}
			
		}
		dp1[i] = maxL;
	}
	
	dp2[n-1] = 1;
	for(int i=n-1;i>=0;i--){
		int maxL = 1;
		for(int j=n-1;j>i;j--){
			if((height[j]<height[i]) && (dp2[j]+1 > maxL)){
				maxL = dp2[j] + 1;
			}
		}
		dp2[i] = maxL;
	}
	
	for(int i=0;i<n;i++){
		cout << dp2[i] << " " ;
	}
	cout << endl;
	
	int maxL = 0;
	for(int i=0;i<n;i++){
		int tmp = dp1[i] + dp2[i] - 1;
		if(tmp>maxL) {
			maxL = tmp;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int tmp = dp1[i] + dp2[j];
			if(tmp > maxL){
			maxL = tmp;
			}	
		}
	}
	
	cout << n - maxL << endl;
	
	delete [] dp1;
	delete [] dp2;
	delete [] height;
		
	return 0;
}
