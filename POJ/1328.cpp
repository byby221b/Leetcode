/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/07/19 10:25
	Description: 贪心合并区间
				注意double变量不要设成int 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct section{
	double left,right;
} Sec;

Sec island[1005];

bool cmp(Sec a,Sec b){
	return (a.left <= b.left);
}

bool run(int count){
	int n,d;
	scanf("%d%d",&n,&d);
	
	if(n==0 && d==0){
		return false;
	}
	
//	bool flag = (d>=0);
	bool flag = true;
	int x,y;
	
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(flag){
			if(y>d){
				flag = false;
				continue;
			}
			double x_delta = sqrt((double)d*d - (double)y*y);
			island[i].left = (double)x - x_delta;
			island[i].right = (double)x + x_delta;
		}
	}
	
	if(!flag){
		printf("Case %d: -1\n",count);
		return true;
	}
	
	sort(island,island+n,cmp);
	
	double curr = island[0].right;
	int pCount = 1;
	for(int i=1;i<n;i++){
		if(island[i].left > curr){
			pCount ++;	
			curr = island[i].right;
		}else{
			if(island[i].right<curr){
				curr = island[i].right;
			}
		}
	}
	
	printf("Case %d: %d\n",count,pCount);
	
	return true;
}

int main(){
	int count = 1;
	while(run(count)){
		count ++;
	}
	return 0;
}
