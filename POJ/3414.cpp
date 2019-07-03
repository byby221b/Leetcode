/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 10:54
	Description: bfs;注意路径的记录方式 
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int path[101*101+5];
int A,B,C;

int toIdx(int i,int j,int col){
	return (i*col + j);
}

void output(int curr){
	int record[101*101+5];
	int count = 0;
	record[count] = curr;
	while(curr!=0){
		count ++;
		curr = path[curr];
		record[count] = curr;
	}
	
	cout << count << endl;
	for(int i=count;i>0;i--){
		int before = record[i];
		int after = record[i-1];
		
		int va_before = before / (B+1);
		int vb_before = before % (B+1);
		int va_after = after / (B+1);
		int vb_after = after % (B+1);
		
		int va_delta = va_after - va_before;
		int vb_delta = vb_after - vb_before;
		
		if(va_delta==0){
			if(vb_delta>0){
				cout << "FILL(2)" <<endl;
			}else{
				cout << "DROP(2)" << endl;
			}
		}else if(va_delta>0){
			if(vb_delta==0){
				cout << "FILL(1)" << endl;
			}else{
				cout << "POUR(2,1)" << endl;
			}
		}else{
			if(vb_delta==0){
				cout << "DROP(1)" << endl;
			}else{
				cout << "POUR(1,2)" << endl;
			}
		}	
	}
}
void run(){
	
	cin >> A >> B >> C;
	
	memset(path,-1,sizeof(path));
	
	path[toIdx(0,0,B+1)] = 0;
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		int va = curr / (B+1);
		int vb = curr % (B+1);
		
		if(va==C || vb==C){
			output(curr);
			return;
		}
		
		//fill
		if(va<A && path[toIdx(A,vb,B+1)]==-1){
			path[toIdx(A,vb,B+1)] = curr;
			q.push(toIdx(A,vb,B+1));
		}
		if(vb<B && path[toIdx(va,B,B+1)]==-1){
			path[toIdx(va,B,B+1)] = curr;
			q.push(toIdx(va,B,B+1));
		}
		
		//drop
		if(va>0 && path[toIdx(0,vb,B+1)]==-1){
			path[toIdx(0,vb,B+1)] = curr;
			q.push(toIdx(0,vb,B+1));
		}
		if(vb>0 && path[toIdx(va,0,B+1)]==-1){
			path[toIdx(va,0,B+1)] = curr;
			q.push(toIdx(va,0,B+1));
		}
		
		//pour
		if(va>0 && vb<B){
			int tmp_va,tmp_vb;
			if(va+vb<=B){
				tmp_va = 0;
				tmp_vb = va + vb;
			}else{
				tmp_va = va - (B - vb);
				tmp_vb = B;
			}
			
			if(path[toIdx(tmp_va,tmp_vb,B+1)]==-1){
				path[toIdx(tmp_va,tmp_vb,B+1)] = curr;
				q.push(toIdx(tmp_va,tmp_vb,B+1));
			}
		}
		
		if(vb > 0 && va < A){
			int tmp_va,tmp_vb;
			if(va+vb<=A){
				tmp_vb = 0;
				tmp_va = va + vb;
			}else{
				tmp_vb = vb - (A - va);
				tmp_va = A;
			}
			
			if(path[toIdx(tmp_va,tmp_vb,B+1)]==-1){
				path[toIdx(tmp_va,tmp_vb,B+1)] = curr;
				q.push(toIdx(tmp_va,tmp_vb,B+1));
			}
		}
		
	}
	
	cout << "impossible" << endl;
}


int main(){
	run();
	return 0;
}

