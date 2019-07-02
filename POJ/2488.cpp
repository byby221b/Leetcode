/*
	Name: 
	Copyright: 
	Author: 
	Date: 01/07/19 16:41
	Description: dfs 
				lexicographically:×ÖµäÐò 
*/

#include <iostream>
#include <cstring>

using namespace std;

int flag = false;
int offset[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

int toIdx(int i,int j,int q){
	return (i*q+j);
}

int isLegal(int i,int j,int p,int q){
	return (i>=0 && i<p && j>=0 && j<q);
}

void output(int *path,int level,int q,int count){
	cout << "Scenario #" << count << ":"  << endl;
	for(int i=0;i<level;i++){
		int curr_i = path[i] / q;
		int curr_j = path[i] % q;
		char letter = 'A' + curr_j;
		char number = '1' + curr_i;
		cout << letter << number;
	}
	cout << endl << endl;
}

void dfs(int *board,int *path,int level,int curr_i,int curr_j,int p,int q,int count){
	
	if(flag || level>p*q){
		return;
	}
	
	if(level==p*q){
		flag = true;
		output(path,p*q,q,count);
		return;
	}
	
	for(int i=0;i<8;i++){
		int next_i = curr_i + offset[i][0];
		int next_j = curr_j + offset[i][1];
		if(isLegal(next_i,next_j,p,q) && !board[toIdx(next_i,next_j,q)]){
			board[toIdx(next_i,next_j,q)] = 1;
			path[level] = toIdx(next_i,next_j,q);
//			output(path,level+1,q,count);
			dfs(board,path,level+1,next_i,next_j,p,q,count);
			board[toIdx(next_i,next_j,q)] = 0;
		}
	}
}

void run(int count){
	int p,q;
	cin >> p >> q; 
	
	int *board = new int[p*q+5];
	int *path = new int[p*q+5];
	memset(board,0,sizeof(int)*(p*q+5));
	memset(path,0,sizeof(int)*(p*q+5));
	flag = false;
	
	for(int i=0;i<p;i++){
		if(flag) break;
		for(int j=0;j<q;j++){
			if(flag) break;
			path[0] = toIdx(i,j,q);
			board[toIdx(i,j,q)] = 1;
			dfs(board,path,1,i,j,p,q,count);
			board[toIdx(i,j,q)] = 0;
		}
	}
	
	if(!flag){
		cout << "Scenario #" << count << ":"  << endl;
		cout << "impossible" << endl << endl;
	}
	
}

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		run(i);
	}
	return 0;
} 
