#include <iostream>

using namespace std;

int A = 1606;

class TEST{
	public:
		void test(){
			cout << A << endl;
		}
};

int main(){
	TEST test = TEST();
	test.test();
	return 0;
}
