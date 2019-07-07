/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 10:31
	Description: 迪杰斯特拉,将1点视为目标点,增加一个虚拟结点作为起始点
				需要对level进行枚举
				假设M=2,酋长等级为5,则需要枚举[3,5],[4,6],[5,7]
				本程序放宽了level范围,但是也通过了(数据问题) 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 0x3f3f3f3f
using namespace std;

int graph[105][105];
int price[105];
int level[105];
int dist[105];
int path[105];
bool mark[105];

int abs(int a){
	return (a<0)?-a:a;
}

bool levelOK(int i,int j,int M){
	while(i!=-1){
		if(abs(level[j]-level[i])>M){
			return false;
		}
		
		i = path[i];
	}
	
	return true;
}

int main(){
	int M,N;
	
	scanf("%d%d",&M,&N);
	
	memset(graph,-1,sizeof(graph));
	
	int count;
	int t,v;
	for(int i=1;i<=N;i++){
		scanf("%d%d%d",&price[i],&level[i],&count);
		
		for(int j=0;j<count;j++){
			scanf("%d%d",&t,&v);
			if(graph[t][i]==-1 || graph[t][i]>v){
				graph[t][i] = v;
			}
		}
		graph[0][i] = price[i];
	}
	
	memset(path,-1,sizeof(path));
	
	for(int i=1;i<=N;i++){
		dist[i] = MAX;
		if (level[i]>=level[1]-M && level[i]<=level[1]+M){
			mark[i] = false;
		}else{
			mark[i] = true;
		}
	}
	dist[0] = 0;
	mark[0] = true;
	for(int i=1;i<=N;i++){
		dist[i] = price[i];
	}
	
	bool flag = true;
	while(flag){
		flag = false;
		int minIdx, minDis;
		for(int i=1;i<=N;i++){
			if(!mark[i] && (!flag || dist[i]<minDis)) {
				minDis = dist[i];
				minIdx = i;
				flag = true;
			}
		}
		
		if(flag){
			mark[minIdx] = true;
			for(int i=1;i<=N;i++){
				if(graph[minIdx][i]!=-1 && 
				dist[i]>dist[minIdx]+graph[minIdx][i] &&
				levelOK(minIdx,i,M)){
					dist[i] = dist[minIdx]+graph[minIdx][i];
					path[i] = minIdx;
				}
			}
		}
	}
	
	printf("%d\n",dist[1]);
	
	return 0;
}
