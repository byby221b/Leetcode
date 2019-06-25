/*
	Name: 
	Copyright: 
	Author: 
	Date: 25/06/19 11:13
	Description: 最长递增子序列(nlogn解法)
				注意：递增序列和递减序列可能没有公共点，例如1,2,2答案应该是0 
*/

#include <iostream>
#include <algorithm>

using namespace std; 

void LIS_LEFT(double *data,int *res,int n){
	double *d = new double[n+1];
	int len = 1;
	
	d[0] = 0;
	d[1] = data[0];
	res[0] = 1;
	
	for(int i=1;i<n;i++){
		if(data[i]>d[len]){
			len++;
			d[len] = data[i];
			res[i] = len;
		}else{
			int pos = lower_bound(d+1,d+len+1,data[i]) - d;
			d[pos] = data[i];
			res[i] = pos;
		}
	}
	
	delete [] d;
}

void LIS_RIGHT(double *data,int *res,int n){
	double *d = new double[n+1];
	int len = 1;
	
	d[0] = 0;
	d[1] = data[n-1];
	res[n-1] = 1;
	
	for(int i=n-2;i>=0;i--){
		if(data[i]>d[len]){
			len++;
			d[len] = data[i];
			res[i] = len;
		}else{
			int pos = lower_bound(d+1,d+len+1,data[i]) - d;
			d[pos] = data[i];
			res[i] = pos;
		}
	}
	
	delete [] d;
}

int main(){
	int n;
	cin >> n;
	
	double *height = new double[n];
	
	for(int i=0;i<n;i++){
		cin >> height[i];
	}
	
	int *dp1 = new int[n];
	int *dp2 = new int[n];
	
	LIS_LEFT(height,dp1,n);
	LIS_RIGHT(height,dp2,n);
	
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
