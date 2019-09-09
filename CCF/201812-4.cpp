#include <iostream>
#include <cstdio>
#include <cstring>
/*
	Name: 
	Copyright: 
	Author: 
	Date: 09/09/19 09:40
	Description: 未通过(思路有误) 
*/


using namespace std;

struct Node{
	int id;
	int time;
	Node* next;
	Node(int i,int t) : id(i),time(t), next(NULL) {}
};

Node *graph[10005];
int mark[10005];
long long dist[10005];
int path[10005];

void readGraph(int n,int m){
	for(int i=1;i<=n;i++){
		graph[i] = new Node(i,0);
	}
	
	int v,u,t;
	Node *ptr,*newPtr;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v,&u,&t);
		ptr = graph[v];
		newPtr = new Node(u,t);
		newPtr->next = ptr->next;
		ptr->next = newPtr;
		
		ptr = graph[u];
		newPtr = new Node(v,t);
		newPtr->next = ptr->next;
		ptr->next = newPtr;
	}
}

int main(){
	
	int n,m,root;
	scanf("%d%d%d",&n,&m,&root);
	
	readGraph(n,m);
	
//	for(int i=1;i<=n;i++){
//		Node *ptr = graph[i];
//		cout << i << ":\t" ;
//		while(ptr->next){
//			cout << (ptr->next->id) << "--" << (ptr->next->time) << "\t";
//			ptr = ptr->next;
//		}
//		cout << endl;
//	}
	
	memset(mark,0,sizeof(mark));
	memset(dist,-1,sizeof(dist));
	memset(path,-1,sizeof(path));
	
	mark[root] = true;
	dist[root] = 0;
	Node *ptr = graph[root];
	while(ptr->next){
		dist[ptr->next->id] = ptr->next->time;
		path[ptr->next->id] = root;
		ptr = ptr->next;
	}
	
	bool flag = true;
	
	while(flag){
		flag = false;
		
		int minVal = -1,minIdx = -1;
		for(int i=1;i<=n;i++){
			if(!mark[i] && dist[i]>0 && (!flag || dist[i]<minVal)){
				flag = true;
				minVal = dist[i];
				minIdx = i;
			}
		}
		
		if(flag){
			mark[minIdx] = true;
			ptr = graph[minIdx];
			int currId;
			while(ptr->next){
				currId = ptr->next->id;
				if(dist[currId]<0 || (dist[currId]>minVal+(ptr->next->time))){
					dist[currId] = minVal+(ptr->next->time);
					path[currId] = minIdx;
				}
				ptr = ptr->next;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout << dist[i] << "\t";
	}
	cout << endl;
	
	int maxDist = 0;
	for(int i=1;i<=n;i++){
		if(path[i]!=-1){
			ptr = graph[path[i]];
			while(ptr->next && (ptr->next->id)!=i){
				if(ptr->next && (ptr->next->time)>maxDist){
					maxDist = ptr->next->time;
				}
				ptr = ptr->next;
			}
		}
	}
	
	printf("%d\n",maxDist);
	return 0;
}
