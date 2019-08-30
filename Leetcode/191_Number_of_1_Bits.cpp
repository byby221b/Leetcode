/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/08/19 11:57
	Description: 
*/

#include <iostream>
using namespace std;

typedef unsigned int uint32_t;

//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int count = 0;
//        while(n!=0){
//        	count += (n & 1);
//        	n = n >> 1;
//		}
//		return count;
//    }
//};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
        	n = n&(n-1);
        	count ++;
		}
		return count;
    }
};

int main(){
	Solution su = Solution();
//	uint32_t test = 0b00000000000000000000000000001011;
	uint32_t test = 0b11111111111111111111111111111101;
	int res = su.hammingWeight(test);
	cout << res << endl;
	return 0;
}
