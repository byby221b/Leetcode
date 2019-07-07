/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 14:57
	Description: 2019-07-07 15:05:44
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 0x3f3f3f3f
using namespace std;

int graph[505][505];
bool mark[505];
int low_dis[505];

void run(){
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	
	bool flag = true;
	for(int i=0;i<N;i++){
		mark[i] = false;
		low_dis[i] = MAX;
	}
	int src = 0;
	int maxLength = 0;
	mark[0] = true;
	while(flag){
		flag = false;
		int minDis,minIdx;
		for(int i=1;i<N;i++){
			if(!mark[i] && low_dis[i] > graph[src][i]){
				low_dis[i] = graph[src][i];
			}
			
			if(!mark[i] && (!flag || minDis > low_dis[i])){
				flag = true;
				minIdx = i;
				minDis = low_dis[i];
			}
		}
		if(flag){
			mark[minIdx] = true;
			maxLength = (minDis > maxLength) ? minDis : maxLength;
			src = minIdx;
		}
	}
	
	printf("%d\n",maxLength);
}

int main(){
	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		run();
	}
	return 0;
}
