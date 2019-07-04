/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 13:52
	Description: ×î¶ÌÂ·--->bfs
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int L,R,C;
char *maze;

int toIdx(int l,int r,int c){
	return (l*R*C + r*C + c);
}

int offset[6][3] = {{0,0,-1},{0,0,1},{0,-1,0},{0,1,0},{-1,0,0},{1,0,0}};

bool isLegal(int l,int r,int c){
	return (l>=0 && l<L && r>=0 && r<R && c>=0 &&c<C);
}

bool canGo(int l,int r,int c){
	return (maze[toIdx(l,r,c)]=='.' || maze[toIdx(l,r,c)]=='E');
}

bool run(){
	
	cin >> L >> R >> C;
	
	if(L==0 && R==0 && C==0){
		return false;
	}
	
	maze = new char[L*R*C+5];
	int *mark = new int[L*R*C+5];
	int *dis = new int[L*R*C+5];
	memset(mark,0,sizeof(int)*(L*R*C+5));
	memset(dis,-1,sizeof(int)*(L*R*C+5));
	
	int s,e;
	string buf;
	
	for(int i=0;i<L;i++){
		getline(cin,buf);
		for(int j=0;j<R;j++){
			getline(cin,buf);
			for(int k=0;k<C;k++){
				maze[toIdx(i,j,k)] = buf[k];
				if(buf[k]=='S') s = toIdx(i,j,k);
				if(buf[k]=='E') e = toIdx(i,j,k);
			}
		}
	}
	
	queue<int> q;
	q.push(s);
	mark[s] = 1;
	dis[s] = 0;
	bool flag = false;
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		if(curr==e){
			cout << "Escaped in " << dis[curr] << " minute(s)." << endl;
			flag = true;
			break;
		}
		
		int l = curr / (R*C);
		int r = (curr - l*R*C) / C;
		int c = curr - l*R*C - r*C;
		
		for(int i=0;i<6;i++){
			int l_n = l + offset[i][0];
			int r_n = r + offset[i][1];
			int c_n = c + offset[i][2];
			
			if(isLegal(l_n,r_n,c_n) && canGo(l_n,r_n,c_n) && !mark[toIdx(l_n,r_n,c_n)]){
				mark[toIdx(l_n,r_n,c_n)] = 1;
				dis[toIdx(l_n,r_n,c_n)] = dis[toIdx(l,r,c)] + 1;
				q.push(toIdx(l_n,r_n,c_n));
			}
		}
	}
	
	if(!flag){
		cout << "Trapped!" << endl;
	}
	
	delete [] mark;
	delete [] dis;
	delete [] maze;
	return true;
}


int main(){
	while(run());
	return 0;
}
