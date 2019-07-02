/*
	Name: 
	Copyright: 
	Author: 
	Date: 01/07/19 20:18
	Description: 	DFS/BFS
					对于没有负边权的最短路BFS即可，无需SPFA 
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char maze[45][45];

struct point{
	int x,y,direction;
};

typedef struct point P;

int leftFirst[4][4] = {{3,0,1,2},{0,1,2,3},{1,2,3,0},{2,3,0,1}};
int rightFirst[4][4] = {{1,0,3,2},{2,1,0,3},{3,2,1,0},{0,3,2,1}};
int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int row,col;

bool isLegal(int i,int j){
	return (i>=0 && i<row && j>=0 && j<col);
}

bool canGo(int i,int j){
	return (maze[i][j]=='.' || maze[i][j]=='E');
}

int findPath(int rule[4][4],P start,P end){
	int step = 1;
	P tmp;
	for(int i=0;i<4;i++){
		int next_i = start.x + offset[i][0];
		int next_j = start.y + offset[i][1];
		if(isLegal(next_i,next_j) && canGo(next_i,next_j)){
			tmp.x = next_i;
			tmp.y = next_j;
			tmp.direction = i;
		}
	}
	
	while(!(tmp.x==end.x && tmp.y==end.y)){
		step ++ ;
		for(int i=0;i<4;i++){
			int cur_off = rule[tmp.direction][i];
			int next_i = tmp.x + offset[cur_off][0];
			int next_j = tmp.y + offset[cur_off][1];
			if(isLegal(next_i,next_j) && canGo(next_i,next_j)){
				tmp.x = next_i;
				tmp.y = next_j;
				tmp.direction = cur_off;
				break;
			}
		}
	}
	
	return step+1;
}

int shortPath(P start,P end){
	int mark[45][45];
	int dis[45][45];
	memset(mark,0,sizeof(mark));
	memset(dis,-1,sizeof(dis));
	
	queue<P> q;
	
	dis[start.x][start.y] = 0;
	mark[start.x][start.y] = 1;
	q.push(start);
	
	while(!q.empty()){
		P curr = q.front();
		q.pop();
		bool flag = false;
		for(int i=0;i<4;i++){
			int next_i = curr.x + offset[i][0];
			int next_j = curr.y + offset[i][1];
			if(isLegal(next_i,next_j) && canGo(next_i,next_j) && !mark[next_i][next_j]){
				P tmp;
				tmp.x = next_i;
				tmp.y = next_j;
				q.push(tmp);
				dis[next_i][next_j] = dis[curr.x][curr.y] + 1;
				mark[next_i][next_j] = 1; 
				if(next_i == end.x && next_j==end.y){
					flag = true;
					break;
				}
			}
		}
		
		if(flag){
			break;
		}
	}
	
	return dis[end.x][end.y]+1;
}

void run(){
	
	cin >> col >> row;
	
	P start,end;
	
	string buf;
	getline(cin,buf);
	for(int i=0;i<row;i++){
		getline(cin,buf);
		for(int j=0;j<col;j++){
			maze[i][j] = buf[j];
			if(buf[j]=='S') {
				start.x = i;
				start.y = j;
			}else if(buf[j]=='E'){
				end.x = i;
				end.y = j;
			}
		}
	}
	
	int leftRes = findPath(leftFirst,start,end);
	int rightRes = findPath(rightFirst,start,end);
	int shortRes = shortPath(start,end);
	cout << leftRes << " " <<  rightRes << " " << shortRes << endl;
}


int main(){
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		run();
	}
	return 0;
}

