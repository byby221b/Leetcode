/*
	Name: 
	Copyright: 
	Author: 
	Date: 08/07/19 22:19
	Description: 
				棋盘比较小，bfs枚举所有状态
				用32位int的低16位记录棋盘状态,高16位记录翻转过的格子 
*/


#include <iostream>
#include <cstring>
#include <queue>
#define SIZE 4
using namespace std;

typedef unsigned int UINT;

int state[65550];

char board[5][5];

int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int point2idx(int i,int j){
	return (i*SIZE+j);
}

void idx2point(int idx,int &i,int &j){
	i = idx / SIZE;
	j = idx % SIZE;
}

bool isLegal(int i,int j){
	return (i>=0 && i<SIZE && j>=0 && j<SIZE);
}

void output(int a){
	cout << a << ":";
	
	for(int i=0;i<16;i++){
		int digt = (a & (1 << i))>>i;
		cout << digt << " ";
	}
	cout << endl;
}

void bfs(){
	queue<UINT> q;
	q.push(0);	
	state[0] = 0;
	
	int next;
	int row,col;
	int next_row,next_col;
	int idx;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int i=0;i<SIZE*SIZE;i++){
			if(!(curr & (1<<(16 + i)))){
				next = curr ^ (1 << i);
				idx2point(i,row,col);
				for(int j=0;j<4;j++){
					next_row = row + offset[j][0];
					next_col = col + offset[j][1];
					if(isLegal(next_row,next_col)){
						idx = point2idx(next_row,next_col);
						next = next ^ (1 << idx);
					}
				}
			}
			
			int currId = curr & 0xffff;
			int nextId = next & 0xffff;
			
			if(state[nextId]==-1){
				state[nextId] = state[currId] + 1;
				q.push((next | ( 1 << (i + 16))));
			}
		}
	}
	
}

int min(int a,int b){
	return (a<b)?a:b;
}

int main(){
	
	int target = 0;
	int digt;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			cin >> board[i][j];
			digt = (board[i][j]=='b') ? 1 : 0;
			target = target | (digt << point2idx(i,j));
		}
	}
	
	memset(state,-1,sizeof(state));
	
	bfs();
	
	int adj_target = target ^ 65535;
	
//	cout << target << endl;
//	output(target);
//	cout << adj_target << endl;
//	output(adj_target);
//	cout << state[adj_target] << " " << state[target] << endl;
	
	if(state[adj_target]==-1){
		if(state[target]==-1){
			cout << "Impossible" << endl;
		}else{
			cout << state[target] << endl;
		}
	}else{
		if(state[target]==-1){
			cout << state[adj_target] << endl;
		}else{
			cout << min(state[adj_target],state[target]) << endl;
		}
	}
	
	return 0;
}
