/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/08/19 09:53
	Description: 
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        if(N==0){
        	return 0;
		}
		
		unordered_map<int,int> record;
		int tmp;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				tmp = A[i] + B[j];
				if(record.find(tmp)==record.end()){
					record[tmp] = 0;
				}
				record[tmp] ++;
			}
		}
		
		int count = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				tmp = -(C[i] + D[j]);
				if(record.find(tmp)!=record.end()){
					count += record[tmp];
				}
			}
		}
		
		return count;
    }
};

int main(){
	vector<int> A = {1,2};
	vector<int> B = {-2,-1};
	vector<int> C = {-1,2};
	vector<int> D = {0,2};
	
	Solution su = Solution();
	
	int res = su.fourSumCount(A,B,C,D);
	
	cout << res << endl;
	return 0;
}
