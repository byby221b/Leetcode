/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/06/19 10:56
	Description: ²¢²é¼¯ 
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
	
    void solve(vector<vector<char>>& board) {
		if(board.empty() || board[0].empty()){
			return;
		}
		
		row = board.size();
		col = board[0].size();
		
		id = new int[row*col*2];
		sz = new int[row*col*2];
		border = new bool[row*col*2];
		
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				id[trans(i,j)] = trans(i,j);
				sz[trans(i,j)] = 1;
				border[trans(i,j)] = ((isBorder(i,j) && (board[i][j]=='O')));
//				cout << i << " " << j << " " << board[i][j] << " " << border[trans(i,j)] << endl;
			}
		}
		
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(board[i][j]=='O'){
					if(isLegal(i+1,j) && board[i+1][j]=='O'){
						Union(trans(i,j),trans(i+1,j),(isBorder(i,j) || (isBorder(i+1,j))));
					}
					if(isLegal(i,j+1) && board[i][j+1]=='O'){
						Union(trans(i,j),trans(i,j+1),(isBorder(i,j) || (isBorder(i,j+1))));
					}
				}
			}
		}
		
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(board[i][j]=='O'){
					int id = find(trans(i,j));
					if(!border[id]){
						board[i][j] = 'X';
					}
				}
				
//				cout << board[i][j] << " ";
			}
//			cout << endl;
		}
		
		delete [] id;
		delete [] sz;
		delete [] border;
    }
    
private:
	int *id;
	int *sz;
	bool *border;
	int row,col;
	
	int trans(int i,int j){
		return (i*col + j);
	}
	
	bool isBorder(int i,int j){
		return (i==0 || i==row-1 || j==0 || j==col-1);
	}
	
	bool isLegal(int i,int j){
		return (i>=0 && i<row && j>=0 && j<col);
	}
	
	int find(int p){
		int temp = p;
		while(p!=id[p]){
			p = id[p];
		}
		
		id[temp] = p;
		
		return p;
	}
	
	void Union(int p,int q,bool isBord){
		int idp = find(p);
		int idq = find(q);
		
		if(idp == idq){
			return;
		}
		
		if(sz[idp]<sz[idq]){
			id[idp] = idq;
			sz[idq] += sz[idp];
			border[idq] = (border[idq] || border[idp] || isBord);
		}else{
			id[idq] = idp;
			sz[idp] += sz[idq];
			border[idp] = (border[idq] || border[idp] || isBord);
		}
		
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

