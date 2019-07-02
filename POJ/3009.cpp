/*
	Name: 
	Copyright: 
	Author: 
	Date: 01/07/19 21:26
	Description: dfs 回溯 剪枝 
*/

#include <iostream>

using namespace std;

int row,col;
int data[25][25];
int minRes;

typedef struct point{
	int x,y;	
}P;

int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool isLegal(P node){
	return (node.x >=0 && node.x < row && node.y>=0 && node.y < col);
}

void dfs(P curr,int step,P end){
	if(step>=10){
		return;
	}
	
	step ++;
	for(int i=0;i<4;i++){
		P next,n_next;
		next.x = curr.x;
		next.y = curr.y;
		n_next.x = curr.x + offset[i][0];
		n_next.y = curr.y + offset[i][1];
		if(!isLegal(n_next) || data[n_next.x][n_next.y]==1){
			continue;
		}
		
		while(true){
			//out
			if(!isLegal(next)){
				break;
			}
			
			//goal 
			if(next.x==end.x && next.y==end.y){
				if(minRes==-1){
					minRes = step;
				}else{
					minRes = (step < minRes) ? step : minRes;
				}
				
				break;
			}
			
			//block
			if(isLegal(n_next) && data[n_next.x][n_next.y]==1){
				//小球滚动停止 并且消去一个block 
				data[n_next.x][n_next.y] = 0;
				dfs(next,step,end);
				data[n_next.x][n_next.y] = 1;
				break;
			}
			
			next.x = n_next.x;
			next.y = n_next.y;
			n_next.x += offset[i][0];
			n_next.y += offset[i][1];
			
		}
	}
	
}

bool run(){
	
	cin >> col >> row;
	
	if(col==0 && row==0){
		return false;
	}
	
	P start,end;
	//input
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin >> data[i][j];
			if(data[i][j]==2){
				start.x = i;
				start.y = j;
			}else if(data[i][j]==3){
				end.x = i;
				end.y = j;
			}
		}
	}
	
	minRes = -1;
	dfs(start,0,end);
	
	cout << minRes << endl;
	
	return true;
}

int main(){
	while(run());
	return 0;
}
