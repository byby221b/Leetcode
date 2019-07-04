/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/07/19 20:45
	Description: dfs枚举了所有情况
				 平面图,使用四色定理 
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
int graph[30][30];
int colorMark[30];
int maxNum = -1;

bool colorAlloc(int p,int color) {
	for(int i=0;i<p;i++){
		if(graph[p][i] && colorMark[i]==color){
			return false;
		}
	}
	
	return true;
}

void dfs(int level,int maxColor){
	if(level>=n){
		if(maxNum==-1 || maxColor<maxNum){
			maxNum = maxColor;
		}
		return;
	}
	
	for(int i=1;i<=4;i++){
		if(colorAlloc(level,i)){
			colorMark[level] = i;
			int maxTmp = (maxColor > i) ? maxColor : i;
			dfs(level+1,maxTmp);
		}
	}
}

bool run(){
	cin >> n;
	
	if(n==0) {
		return false;
	}
	
	memset(graph,0,sizeof(graph));
	memset(colorMark,0,sizeof(colorMark));
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
	dfs(0,0);
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
