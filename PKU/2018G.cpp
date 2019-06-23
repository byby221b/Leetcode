/*
	Name: 
	Copyright: 
	Author: 
	Date: 22/06/19 11:42
	Description: 带权并查集 
*/

#include <iostream> 

using namespace std;

/*
*	A,B,0: A equal to B
*	A,B,1: A eat B
*	A,B,2: A eaten by B
*/

//(A,B),(B,C)->(A,C)
int table1[3][3] = {{0,1,2},{1,2,0},{2,0,1}};
//(A,C),(B,C)->(A,B)
int table2[3][3] = {{0,2,1},{1,0,2},{2,1,0}};
//(A,B)->(B,A)
int table3[3] = {0,2,1};
//(A,B),(A,C)->(B,C)
int table4[3][3] = {{0,1,2},{2,0,1},{1,2,0}};

class QU{
public:
	QU(int n){
		id = new int[n+1];
		sz = new int[n+1];
		relation = new int[n+1];
		for(int i=0;i<=n;i++){
			id[i] = i;
			sz[i] = 1;
			relation[i] = 0;
		}
	}
	~QU(){
		delete [] id;
		delete [] sz;
		delete [] relation;
	}
	
	void find(int p,int &findR,int &findP){
		int temp = p;
		int r = 0;
		while(id[p]!=p){
			r = table1[r][relation[p]];
			p = id[p];
			
		}
		id[temp] = p;
		relation[temp] = r;
		findR = r;
		findP = p;
//		return p;
	}
	
	bool connected(int p,int q,int &r){
		int idP,idQ,rP,rQ;
		find(p,rP,idP);
		find(q,rQ,idQ);
		if(idP==idQ){
			r = table2[rP][rQ];
			return true;
		}else{
			r = -1;
			return false;
		}	
	}
	
	void Union(int p,int q,int r){
		int idp,idq,rp,rq;
		find(p,rp,idp);
		find(q,rq,idq);
		
		int rpq = table4[rp][table1[r][rq]];
		
		if(idp==idq){
			return;
		}
		
		if(sz[idp]<sz[idq]){
			id[idp] = idq;
			sz[idq] += sz[idp];
			relation[idp] = rpq;
		}else{
			id[idq] = idp;
			sz[idp] += sz[idq];
			relation[idq] = table3[rpq];
		}

	}
	
private:		
	int *id,*sz,*relation;
};


int main(){
	int N,K;
	cin >> N >> K;
	
	QU quHelper = QU(N);
	int count = 0;
	
	while(K>0){
		K --;
		
		int D,X,Y;
		cin >> D >> X >> Y;
		
		if(X>N || Y>N){
			count ++;
			continue;
		}
		
		int r;
		bool isCon = quHelper.connected(X,Y,r);
		if(!isCon){
			int newR = (D==1) ? 0 : 1;
			quHelper.Union(X,Y,newR);
		}else{
			if(!(D==1 && r==0) && !(D==2 && r==1)){
				count ++;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}

