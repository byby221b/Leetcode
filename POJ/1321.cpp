/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/07/19 13:36
	Description: dfs 八皇后问题
				注意处理对应行不放棋子的情况 
*/

#include <iostream>
#include <cstring>
using namespace std;

int board[10][10];
int mark[10];
int n,k;
int method;


void dfs(int row,int number,int *mark){
	if(number==k){
		method ++;
		return;
	}
	
	if(row>=n){
		return;
	}
	
	for(int j=0;j<n;j++){
		if(!mark[j] && board[row][j]==1){
			mark[j] = 1;
			dfs(row+1,number+1,mark);
			mark[j] = 0;
		}
	}
	//此行不放棋子 
	dfs(row+1,number,mark);
}

bool run(){
	
	cin >> n >> k;
	
	if(n==-1 && k==-1){
		return false;
	}
	
	memset(board,0,sizeof(board));
	memset(mark,0,sizeof(mark));
	
	string buf;
	getline(cin,buf);
	for(int i=0;i<n;i++){
		getline(cin,buf);
		for(int j=0;j<n;j++){
			if(buf[j]=='#'){
				board[i][j] = 1;
			}
		}
	}
	
	method = 0;
	for(int j=0;j<n;j++){
		if(board[0][j]==1){
			mark[j] = 1;
			dfs(1,1,mark);
			mark[j] = 0;
		}
	}
	dfs(1,0,mark);
	
	cout << method << endl;
	
	return true;
}

int main(){
	
	while(run());
	
	return 0;
}
