#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
 
using namespace std;
 
int main() {
	 int p1[50][50];
	 int *p2 = new int[2500];
	 
	 cout << "p1: " << sizeof(p1) << endl;
	 cout << "p2: " << 2500*sizeof(int) << endl;
	 
	 
	 delete [] p2;
	 return 0;
}
