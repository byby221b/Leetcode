/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/07/19 19:57
	Description: 图的染色问题中，最少需要的颜色的数量=最大团点的数量（存疑） 
				数据量较小,dfs搜索最大团 
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int graph[30][30];
int mark[30];
int maxNum = -1;

bool isLink(int p){
	for(int i=0;i<n;i++){
		if(mark[i] && !graph[p][i]){
			return false;
		}
	}
	
	return true;
}

void dfs(int level){
	if(level > maxNum){
		maxNum = level;
	}
	
	for(int i=0;i<n;i++){
		if(!mark[i] && isLink(i)){
			mark[i] = 1;
			dfs(level+1);
			mark[i] = 0;
		}
	}
	
}

bool run(){
	cin >> n;
	
	if(n==0) {
		return false;
	}
	
	memset(graph,0,sizeof(graph));
	memset(mark,0,sizeof(mark));
	string buf;
	getline(cin,buf);
	for(int i=0;i<n;i++){
		getline(cin,buf);
		string::iterator it = buf.begin() + 2;
		while(it!=buf.end()){
			graph[i][(*it)-'A'] = 1;
			it++;
		}
	}
	
	maxNum = -1;
	dfs(0);
	if(maxNum==1){
		cout << "1 channel needed." << endl;
	}else{
		cout << maxNum << " channels needed." << endl;
	}
	return true;
}


int main(){
	while(run());
	return 0;
}

