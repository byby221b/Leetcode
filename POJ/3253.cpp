/*
	Name: 
	Copyright: 
	Author: 
	Date: 06/07/19 10:23
	Description: 哈夫曼树 : 结点的权越小,离根节点越远 
				注意long long 
					
*/

#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(){
	
	int n;
//	scanf("%d",&n);
	cin >> n;
	
	priority_queue<long long,vector<long long>,greater<long long> > q;
	
	long long tmp;
	for(int i=0;i<n;i++){
//		scanf("%lld",&tmp);
		cin >> tmp;
		q.push(tmp);
	}
	
	long long sum = 0;
	long long a,b;
	while(q.size()>1){
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		q.push(a+b);
		sum += (a+b);
	}
	
//	printf("%lld\n",sum);
	cout << sum << endl;
	
	return 0;
}

