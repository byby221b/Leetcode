#include <iostream> 
#include <vector> 
#include <unordered_map>

using namespace std;

unordered_map<int,unordered_map<int,int> > cityMap;
    
int transform(int x,int y,int cols){
    return x*cols + y;
}

int query(int src,int dst){
    if(src==dst){
        return 0;
    }
    
    if(cityMap[src].find(dst)==cityMap[src].end()){
        return 1e6;
    }
    
    return cityMap[src][dst];
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    //process the city map
    
    for(int i=0;i<n;i++){
        unordered_map<int,int> route;
        cityMap[i] = route;
    }
    
    for(int i=0;i<flights.size();i++){
        int s = flights[i][0],d = flights[i][1],di = flights[i][2];
        cityMap[s][d] = di;
    }

    vector<int> dp(n*(K+1));
    
    for(int i=0;i<n;i++){
        dp[transform(0,i,n)] = query(i,dst);
    }
    
    for(int i=1;i<=K;i++){
        for(int j=0;j<n;j++){
            int min_dis = 1e6;
            for(int k=0;k<n;k++){
                int curr_dis = dp[transform(i-1,k,n)] + query(j,k);
                
                if(curr_dis < min_dis) min_dis = curr_dis;
            }
            dp[transform(i,j,n)] = min_dis;
			
        }
    }
    
    if(dp[transform(K,src,n)]>=1e6){
        dp[transform(K,src,n)] = -1;
    }
    
    return dp[transform(K,src,n)];
}

int main(){
	int n = 3,
	src = 0,
	dst = 2,
	k = 1;
//	vector<int> e1 = {0,1,1};
//	vector<int> e2 = {0,2,5};
//	vector<int> e3 = {1,2,1};
//	vector<int> e4 = {2,3,1};
//	vector<vector<int> > edges = {e1,e2,e3,e4};
//	cout << findCheapestPrice(n,edges,src,dst,k);
	
	vector<int> e1 = {0,1,100};
	vector<int> e2 = {1,2,100};
	vector<int> e3 = {0,2,500};
	
	vector<vector<int> > edges = {e1,e2,e3};
	cout << findCheapestPrice(n,edges,src,dst,k);
	
	return 0;
}
