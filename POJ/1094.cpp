/*
	Name: 
	Copyright: 
	Author: 
	Date: 07/07/19 20:27
	Description: 拓扑排序
				维护一个入度为0的顶点的队列
				如果出队的数目小于顶点数,说明存在环
				如果同时出现多个入度为0的顶点,说明顺序不能确定 
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int graph[30][30];
int inDeg[30];
int inDegCopy[30];
int record[30];
bool cirFlag,finFlag;
queue<int> q;

int n,m;

int topSort(){
	while(!q.empty()) q.pop();
	
	for(int i=0;i<n;i++){
		inDegCopy[i] = inDeg[i];
		if(!inDegCopy[i]) q.push(i);
	}
	
	bool multi = false;
	int count = 0;
	while(!q.empty()){
		if(q.size()>1){
			multi = true;
		}
		
		int size = q.size();
		for(int i=0;i<size;i++){
			int curr = q.front();
			q.pop();
			record[count++] = curr;
			for(int j=0;j<n;j++){
				if(graph[curr][j]){
					inDegCopy[j] --;
					if(inDegCopy[j]==0){
						q.push(j);
					}
				}
			}
		}
	}
	
	//circle
	if(count<n){
		return -1;
	}
	
	//not sure
	if(multi){
		return 0;
	}
	
	//finish
	return 1;
}

bool run(){
	
	scanf("%d%d",&n,&m);
	if(n==0 && m==0){
		return false;
	}
	
	memset(graph,0,sizeof(graph));
	memset(inDeg,0,sizeof(inDeg));
	char buf[5];
	bool flag = false;
	for(int i=0;i<m;i++){
		scanf("%s",buf);
		if(!flag){
			int src = buf[0] - 'A';
			int dst = buf[2] - 'A';
			graph[src][dst] = 1;
			inDeg[dst] ++;
			int res = topSort();
			if(res==-1){
				printf("Inconsistency found after %d relations.\n",i+1);
				flag = true;
			}else if(res==1){
				printf("Sorted sequence determined after %d relations: ",i+1);
				for(int j=0;j<n;j++){
					printf("%c",record[j]+'A');
				}
				printf(".\n");
				flag = true;
			}
		}
	}
	
	if(!flag){
		printf("Sorted sequence cannot be determined.\n");
	}
	
	return true;
}

int main(){
	while(run());
	return 0;
}
