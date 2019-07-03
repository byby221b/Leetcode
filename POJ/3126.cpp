/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 09:43
	Description: bfs;É¸·¨ÇóËØÊý 
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int cost[10005];
int mark[10005];
int offset[4] = {1,10,100,1000};
int primeAll[10005];

void markPrime(){
	for(int i=0;i<=10000;i++){
		primeAll[i] = 1;
	}
	
	primeAll[0] = 0;
	primeAll[1] = 0;
	for(int i=2;i<=10000;i++){
		if(primeAll[i]){
			for(int j=i;j*i<=10000;j++){
				primeAll[j*i] = 0;
			}
		}
	}
}

bool isPrime(int v){
	return (primeAll[v] == 1);
}

void run(){
	int start,end;
	
	cin >> start >> end;
	
	queue<int> q;
	memset(mark,0,sizeof(mark));
	cost[start] = 0;
	mark[start] = 1;
	q.push(start);
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		if(curr==end){
			cout << cost[curr] << endl;
			return;
		}
		
		for(int i=0;i<4;i++){
			int off = offset[i];
			int digt = (curr / off) % 10;
			for(int j=0;j<=9;j++){
				if(off==1000 && j==0) continue;
				int tmp = curr - digt * off + j * off;
				if(!mark[tmp] && isPrime(tmp)){
					mark[tmp] = 1;
					cost[tmp] = cost[curr] + 1;
//					cout << curr << "-->" << tmp << endl;
					q.push(tmp);
				}
			}
		}
	}
	
	cout << "Impossible" << endl;
}


int main(){
	int n;
	cin >> n;
	
	markPrime();
	
	for(int i=0;i<n;i++){
		run();
	}
	
	return 0;
}

