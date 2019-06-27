#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
#include <vector>
 
using namespace std;
 
void test(vector<int> v){
	v.push_back(1);
}
int main() {
//	 int p1[50][50];
//	 int *p2 = new int[2500];
//	 
//	 cout << "p1: " << sizeof(p1) << endl;
//	 cout << "p2: " << 2500*sizeof(int) << endl;
//	 
//	 
//	 delete [] p2;
	vector<int> v_test;
	test(v_test);
	cout << v_test.size() << endl;
	return 0;
}
