/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/06/19 14:18
	Description: Simple BFS
				(并查集易于理解, 但是并不一定是最简单的解法) 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

class Solution {
public:
	
    void solve(vector<vector<char>>& board) {
		if(board.empty() || board[0].empty()){
			return;
		}
		
		row = board.size();
		col = board[0].size();
		
		int offset[4][2] = {
			{1,0},{-1,0},{0,1},{0,-1}
		};
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(board[i][j]=='O' && isBorder(i,j)){
					board[i][j] = '+';
					queue<int> q;
					q.push(trans(i,j));
					while(!q.empty()){
						int currRow,currCol;
						toPoint(q.front(),currRow,currCol);
						q.pop();
						for(int k=0;k<4;k++){
							int nextRow = currRow+offset[k][0];
							int nextCol = currCol+offset[k][1];
							if(isLegal(nextRow,nextCol) && board[nextRow][nextCol]=='O'){
								board[nextRow][nextCol] = '+';
								q.push(trans(nextRow,nextCol));
							}
						}
					}
				}
			}
		}
		
		
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				board[i][j] = (board[i][j] == '+') ? 'O' : 'X';
			}
		}
    }
    
private:
	int row,col;
	int trans(int i,int j){
		return i * col + j;
	}
	
	bool isBorder(int i,int j){
		return (i==0 || i==row-1 || j==0 || j==col-1);
	}
	
	bool isLegal(int i,int j){
		return (i>=0 && i<row && j>=0 && j<col);
	}
	
	void toPoint(int idx,int &i,int &j){
		j = idx % col;
		i = idx / col;
	}
};

int main(){
//	char data[6][4] = {{'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'}};
	char data[4][6] = {{'X','O','X','O','X','O'},
			 {'O','X','O','X','O','X'},
			 {'X','O','X','O','X','O'},
			 {'O','X','O','X','O','X'}};
	vector<vector<char>> test(4,vector<char>(6));
	int row = 4,col = 6;
//	string buf;
//	ifstream fin("input.txt");
//	for(int i=0;i<row;i++){
//		getline(fin,buf);
////		cout << buf;
//		for(int j=0;j<col;j++){
//			test[i][j] = buf[2*j];
//		}
//	}
//	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			test[i][j] = data[i][j];
		}
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	Solution su = Solution();
	su.solve(test);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

