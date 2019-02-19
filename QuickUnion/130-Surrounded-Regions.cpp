#include <iostream> 
#include <fstream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> id;
    int count;
    
    int transform(int x,int y,int cols){
        return x*cols + y;
    }
    
    int find(int p){
        while(p!=id[p]){
            p = id[p];
        }
        return p;
    }
    
    bool connected(int p,int q){
        return find(p)==find(q);
    }
    
    void Union(int p,int q){
        int idp = find(p);
        int idq = find(q);
        if(!connected(p,q)){
            id[idp] = idq;
            count --;
        }
    }
    
    bool isBorder(int i,int j,int rows,int cols){
        return (i==0 || j==0 || i==rows-1 || j==cols-1);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()){
            return;
        }
        
        set<int> border_o;
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0;i<rows*cols;i++){
            id.push_back(i);
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i+1<rows && board[i][j]==board[i+1][j]){
                    Union(transform(i,j,cols),transform(i+1,j,cols));
                }
                if(j+1<cols && board[i][j]==board[i][j+1]){
                    Union(transform(i,j,cols),transform(i,j+1,cols));
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 if(isBorder(i,j,rows,cols) && board[i][j]=='O'){
                    border_o.insert(find(transform(i,j,cols)));
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O'){
                    int tmp = find(transform(i,j,cols));
                    if(border_o.find(tmp)==border_o.end()){
						board[i][j]='X';
                    }
                }
            }
        }
    }
};

void output(vector<vector<char> > board){
	int rows = board.size();
	int cols = board[0].size();
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	Solution solution;
	ifstream input("input.txt");
	vector<vector<char> > board;
	for(int i=0;i<4;i++){
		vector<char> tmp;
		for(int j=0;j<4;j++){
			char data;
			input >> data;
//			cout << data;
			tmp.push_back(data);
		}
		board.push_back(tmp)	;
	}
	output(board);
	cout << "==============================" << endl;
	solution.solve(board);
	output(board);
	return 0;
}
