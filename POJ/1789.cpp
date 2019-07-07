/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 13:40
	Description: 最小生成树 Prime算法
				注意维护low_dis[j]记录标记点集到点j的最短距离
				单纯for循环或者使用优先队列会超时 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 0x3f3f3f3f
using namespace std;

int graph[2005][2005];
char code[2005][10];
int mark[2005];
int low_dis[2005];
int n;

void idx2point(int &from,int &to,int idx){
	from = idx / n;
	to = idx % n;
}

int point2idx(int from,int to){
	return from * n + to;
}

struct cmp{
	bool operator()(int a,int b){
		int a_from,a_to,b_from,b_to;
		idx2point(a_from,a_to,a);
		idx2point(b_from,b_to,b);
		return (graph[a_from][a_to] > graph[b_from][b_to]);
	}
};

int dis(char *a,char *b){
	int res = 0;
	char *p = a,*q = b;
	
	while(*p){
		if(*p!=*q){
			res ++;
		}
		p++;
		q++;
	}
	
	return res;
}

bool run(){
	
	scanf("%d",&n);
	
	if(n==0){
		return false;
	}
	
	for(int i=0;i<n;i++){
		scanf("%s",code[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int tmp = dis(code[i],code[j]);
			graph[i][j] = tmp;
			graph[j][i] = tmp;
		}
	}	
	
	
	for(int i=0;i<n;i++){
		mark[i] = 0;
		low_dis[i] = MAX;
	}
	
	//low_dis[j] 到点j最近的边 
	mark[0] = true;
	int flag = true;
	int src = 0;
	int sum = 0;
	while(flag){
		flag = false;
		int minDis,minIdx;
		for(int i=1;i<n;i++){
			if(!mark[i] && graph[src][i]<low_dis[i]){
				low_dis[i] = graph[src][i];
			}
			if(!mark[i] && (!flag || minDis > low_dis[i])){
				minDis = low_dis[i];
				minIdx = i;
				flag = true;
			}
		}
		
		if(flag){
			mark[minIdx] = true;
			sum += minDis;
			src = minIdx;
		}
	}
	
	printf("The highest possible quality is 1/%d.\n",sum);
	
	return true;
}


int main(){
	
	while(run());
	
	return 0;
}

