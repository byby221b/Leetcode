/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 19:43
	Description: 
*/

#include <iostream> 
#include <cstdio>
#include <cstring>
#define MAX 0x3f3f3f3f
using namespace std;

int graph[105][105];
bool mark[105];
int low_dis[105];

bool run(){
	int n;
	if(scanf("%d",&n)==EOF){
		return false;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		mark[i] = false;
		low_dis[i] = MAX;
	}
	
	int src = 0;
	mark[0] = true;
	bool flag = true;
	int sum = 0;
	while(flag){
		flag = false;
		int minDis,minIdx;
		for(int i=1;i<n;i++){
			if(!mark[i] && low_dis[i]>graph[src][i]){
				low_dis[i] = graph[src][i];
			}
			
			if(!mark[i] && (!flag || minDis>low_dis[i])){
				flag = true;
				minDis = low_dis[i];
				minIdx = i;
			}
		}
		
		if(flag){
			mark[minIdx] = true;
			src = minIdx;
			sum += minDis;
		}
	}
	
	printf("%d\n",sum);
	
	return true;
}


int main(){
	
	while(run());
	
	return 0;
}

