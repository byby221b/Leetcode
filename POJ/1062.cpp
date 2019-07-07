/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 09:22
	Description: ��1�ŵ���ΪԴ��,��Ȩ����Ϊw[i][j] = price[j] - price[i] + �Żݼ�[i][j]
				���ڸ���Ȩ,���ʹ��Bellman-Ford�㷨
				ע����Ҫ�������б�,�ж�level��ֵ 
				���������޷������и��������
				
				�Ͻ�˹����:��Ҫö�ٵȼ� 
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
			if(graph[i][t]==-1 || graph[i][t]>v){
				graph[i][t] = v;
			}
		}
	}
	
	memset(path,-1,sizeof(path));
	
	for(int i=1;i<=N;i++){
		dist[i] = MAX;
	}
	dist[1] = price[1];
	bool flag;
	for(int k=0;k<N;k++){
		flag = false;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(graph[i][j]!=-1 
				&& levelOK(i,j,M) 
				&& (dist[j]>dist[i]-price[i]+graph[i][j]+price[j])){
					path[j] = i;
					dist[j] = dist[i]-price[i]+graph[i][j]+price[j];
					flag = true;
				}
			}
		}
		if(!flag) break;
		
//		for(int i=1;i<=N;i++){
//			cout << dist[i] << "\t";
//		}
//		cout << endl;
	}
	
	int minP = dist[1];
	for(int i=1;i<=N;i++){
		if(dist[i]<minP){
			minP = dist[i];
		}
	}
	
	printf("%d\n",minP);
	
	return 0;
}
