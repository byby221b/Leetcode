/*
	Name: 
	Copyright: 
	Author: 
	Date: 12/08/19 16:37
	Description: 
*/

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

//class Solution {
//public:
//    int climbStairs(int n) {
//       record = new int[n+5];
//       memset(record,-1,sizeof(int)*(n+5));
//       record[1] = 1;
//       record[2] = 2;
//       
//       int res = run(n);
//       
//       delete [] record;
//       
//       return res;
//    }
//    
//    int run(int n){
//		if(record[n]==-1){
//		   	record[n] = run(n-1)+run(n-2);
//		}
//		return record[n];
//	}
//    
//private:
//	int *record;
//};


class Solution {
public:
    int climbStairs(int n) {
       int a0 = 1,a1 = 1;
       int tmp;
       for(int i=2;i<=n;i++){
			tmp = a1;
			a1 = a0 + a1;
			a0 = tmp;
	   }
       
       return a1;
    }
    
};

int main(){
	Solution su = Solution();
	
	int test = 44;
	
	cout << su.climbStairs(test) << endl;
	
	return 0;
}
