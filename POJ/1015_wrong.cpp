/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/06/19 09:52
	Description: Wrong Answer
*/

#include <iostream>
#include <cstring>
#define MAGIC 400

using namespace std;

int dp[25][805];
int path[25][805];

int idxMap(int idx){
	return (idx+MAGIC);
}

bool isLegal(int idx){
	return (idx >= -MAGIC && idx <= MAGIC);
}

bool select(int level,int d,int j,int *diff){
	int res;
	
	while(level>0 && path[level][d]!=j){
		d -= diff[path[level][d]];
		level --;
	}
	
	return (level > 0) ? true : false;
}

bool run(int count){
	
	int n,m;
	
	cin >> n >> m;
	
	if(n==0 && m==0){
		return false;
	}
	
	int *diff = new int[n+5];
	int *sum = new int[n+5];
	
	diff[0] = 0;
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		int a,b;
		cin >> a >> b;
		diff[i] = a - b;
		sum[i] = a + b;
	}
	
	
	memset(dp,-1,sizeof(dp));
	memset(path,0,sizeof(path));
	
	dp[0][idxMap(0)] = 0;
	
	for(int i=1;i<=m;i++){
		for(int d=-MAGIC;d<=MAGIC;d++){
			if(dp[i-1][idxMap(d)]<0) continue;
			
			for(int j=1;j<=n;j++){
				if(!isLegal(d+diff[j])) continue;
				int tmp = dp[i-1][idxMap(d)] + sum[j];
			
				if(tmp > dp[i][idxMap(d+diff[j])] && !select(i-1,d,j,diff)){
					dp[i][idxMap(d+diff[j])] = tmp;
					path[i][idxMap(d+diff[j])] = j;
				}
			}
		}
		
//		for(int j=-2;j<=4;j++){
//			cout << dp[i][idxMap(j)] << " ";
//		}
//		cout << endl;
	}
	
	int resDiff,resSum;
	for(int j=0;j<=MAGIC;j++){
		bool negFlag = (dp[m][idxMap(-j)] >= 0);
		bool posFlag = (dp[m][idxMap(j)] >= 0);
		
		if(negFlag || posFlag) {
			resDiff = (dp[m][idxMap(-j)] > dp[m][idxMap(j)]) ? -j : j;
			resSum = dp[m][idxMap(resDiff)];
			break;
		}
	}
	
//	cout << resDiff << "\t" << resSum << endl;
	
	int PJ = (resDiff + resSum) / 2;
	int DJ = (resSum - resDiff) / 2;
	int *select = new int[n+5];
	int res;
	memset(select,0,sizeof(int)*(n+5));
	while(m>0){
		res = path[m][idxMap(resDiff)];
		select[res] = 1;
		m -- ;
		resDiff -= diff[res];
	}
	
	cout << "Jury #" << count << endl;
	cout << "Best jury has value " << PJ << " for prosecution and value " << DJ <<" for defence: " << endl;
	for(int i=1;i<=n;i++){
		if(select[i]){
			cout << " " << i;
		}
	}
	cout << endl << endl;
	
	delete [] select;
	delete [] diff;
	delete [] sum;
	return true;
}


int main(){
	
	int count = 1;
	while(run(count)){
		count ++;
	}
	
	return 0;
}
