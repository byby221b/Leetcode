/*
	Name: 
	Copyright: 
	Author: 
	Date: 05/07/19 13:53
	Description: ��С��������=������
				�����Ҫ��long long�� (ע��𰸷�Χ) 
				������������������Ҳ��ʱ�䣬ÿ�εݹ鶼����(TLE)��ֻ����һ��(AC)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int *data;
int n;
int *tmp;

long long mergeSort(int left,int right){
	if(left==right){
		return 0;
	}
	
	int mid = (left + right)/2;
	long long leftRes = mergeSort(left,mid);
	long long rightRes = mergeSort(mid+1,right);
	
	
	int p = left,q = mid + 1,r = left;
	long long count = 0;
	while(p<=mid && q<=right){
		if(data[p]>data[q]){
			count += (mid - p + 1);
			tmp[r++] = data[q];
			q++;
		}else{
			tmp[r++] = data[p];
			p ++;
		}
	}
	
	while(p<=mid){
		tmp[r++] = data[p++];
	}
	
	while(q<=right){
		tmp[r++] = data[q++];
	}
	
	for(r=left;r<=right;r++){
		data[r] = tmp[r];
	}
	
	return (leftRes + rightRes + count);
}

bool run(){
	scanf("%d",&n);
	if(n==0) return false;
	
	data = new int[n+5];
	tmp = new int[n+5];
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	
	long long res = mergeSort(0,n-1);
	
	printf("%lld\n",res);
	
	delete [] data;
	delete [] tmp;
	return true;
}


int main(){
	while(run());
	return 0;
}

