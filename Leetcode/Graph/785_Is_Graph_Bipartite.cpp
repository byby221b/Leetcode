#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
/*
*  Giggle
*  2019-03-03 21:00:00
*/

 bool isBipartite(vector<vector<int>>& graph) {
    int size = graph.size();
    int* color = new int[size];
    queue<int> q;
    
    for(int i=0;i<size;i++){
        if(graph[i].empty()){
            color[i] = 1;
        }else{
            color[i] = 0;
        }
    }
    
    while(true){
        int i = 0;
        while(i<size && color[i]!=0) i++;
        if(i>=size){
            return true;
        }
        
        color[i] = 1;
        q.push(i);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int j=0;j<graph[curr].size();j++){
                int tmp = graph[curr][j];
                if(color[tmp] == color[curr]){
                    delete []color;
                    return false;
                }
                    
                else if(color[tmp]==0){
                    color[tmp] = 0 - color[curr];
                    q.push(tmp);
                }
            }
        }
    }
    
    
    delete []color;
    return true;
}

int main(){
	vector<int> node0 = {1,3};
	vector<int> node1 = {0,2};
	vector<int> node2 = {1,3};
	vector<int> node3 = {0,2};
//	vector<int> node4 = {1,3};
	vector<vector<int> > nodes = {node0,node1,node2,node3};
	
	if (isBipartite(nodes)){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	
	return 0;
}
