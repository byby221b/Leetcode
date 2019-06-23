/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/06/19 09:52
	Description: 最长子段和的变形，dp
	注意题目数据量，三重for循环也不一定会超时
	POJ 1050
*/

#include <iostream>

using namespace std;

int trans(int i,int j,int n){
	return (i*n + j);
}

int maxRow(int *row,int n){
	int maxV = row[0];
	int dp = row[0];
	for(int i=1;i<n;i++){
		dp = (dp+row[i] > row[i]) ? dp + row[i] : row[i];
		maxV = (maxV > dp) ? maxV : dp;
	}
	
	cout << maxV << endl;
	return maxV;
}

int main(){
	int n;
	cin >> n;
	
	int *data = new int[n*n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> data[trans(i,j,n)];
		}
	}
	
	int *tmp = new int[n];
	int maxValue = -1e6;
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			tmp[k] = 0;
		}
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				tmp[k] += data[trans(j,k,n)];
			}
//			cout << i << " " << j << " " ;
			int res = maxRow(tmp,n);
			maxValue = (maxValue > res) ? maxValue : res;
		}
	}
	
	delete [] tmp;
	delete [] data;
	
	cout << maxValue << endl;
	
	return 0;
}

