/*
	Name: 
	Copyright: 
	Author: 
	Date: 04/07/19 18:56
	Description: dfs
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int mark[3][10][10];		//row,col,cell
int data[10][10];
bool flag;
ofstream fout("output.txt");


int cell(int i,int j){
	return (i/3)*3 + (j/3);
}

void output(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << data[i][j];
		}
		cout << endl;
	}
	
}

void dfs(int level){
	
	if(flag) return;
	
	if(level >= 81){
		flag = true;
		output();
		return;
	}
	
//	output();
	
	int row = level / 9;
	int col = level % 9;
	int cellNum = cell(row,col);
	
	if(data[row][col]==0){
		for(int i=1;i<=9;i++){
			if(!mark[0][row][i] && !mark[1][col][i] && !mark[2][cellNum][i]){
				data[row][col] = i;
				mark[0][row][i] = 1;
				mark[1][col][i] = 1;
				mark[2][cellNum][i] = 1;
				dfs(level + 1);
				data[row][col] = 0;
				mark[0][row][i] = 0;
				mark[1][col][i] = 0;
				mark[2][cellNum][i] = 0;
			}
			if(flag) break;
		}
	}else{
		dfs(level + 1);
	}

}

void run(){
	string buf;
	
	memset(mark,0,sizeof(mark));
	
	for(int i=0;i<9;i++){
		getline(cin,buf);
		for(int j=0;j<9;j++){
			int tmp = buf[j] - '0';
			data[i][j] = tmp;
			if(tmp!=0){
				mark[0][i][tmp] = 1;
				mark[1][j][tmp] = 1;
				mark[2][cell(i,j)][tmp] = 1;
			}
		}
	}
	
	flag = false;
	dfs(0);
	
}


int main(){
	int n;
	cin >> n;
	string buf;
	getline(cin,buf);
	for(int i=0;i<n;i++){
		run();
	}
	return 0;
}
