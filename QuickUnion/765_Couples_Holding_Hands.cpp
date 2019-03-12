#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
*  Giggle
*  2019-03-12 21:45:04
*/


class Solution {
public:
    int find(int p){
    	p /= 2;
        int temp = p;
        while(id[p]!=p){
            p = id[p];
        }
        id[temp] = p;
        return p;
    }
    
    bool connected(int p,int q){
    	cout << "p:" << p << "\t" << "idp:" << find(p) << endl;
    	cout << "q:" << q << "\t" << "idq:" << find(q) << endl;
    	cout << "======================================" << endl;
        return find(p)==find(q);
    }
    
    void Union(int p,int q){
        if(!connected(p,q)){
            int idp = find(p);
            int idq = find(q);
            if(sz[idp]<sz[idq]){
                id[idp] = idq;
                sz[idq] += sz[idp];
            }else{
                id[idq] = idp;
                sz[idp] += sz[idq];
            }
            count --;
            swap ++;
        }
    }
    
    int minSwapsCouples(vector<int>& row) {
        size = row.size();
        count = size;
        swap = 0;
        
        for(int i=0;i<size/2;i++){
            id.push_back(i);
            sz.push_back(2);
        }
        
        for(int i=0;i<size;i+=2){
            Union(row[i],row[i+1]);
            if(count==1)
                break;
        }
        
        return swap;
    }
private:
    vector<int> id;
    vector<int> sz;
    int size;
    int count,swap;
};


int main() {
	Solution solution = Solution();
	vector<int> row = {3,2,0,1};
	cout << solution.minSwapsCouples(row) << endl;
	return 0;
}
