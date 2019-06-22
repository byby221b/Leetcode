/*
	Name: 
	Copyright: 
	Author: 	BY
	Date: 20/06/19 17:01
	Description: 百练/并查集 
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class QU{
public:
	int count;
	int *sz;
	int *id;
	
	QU(int n){
		count = 0;
		sz = new int[n];
		id = new int[n];
		for(int i=0;i<n;i++){
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	~QU(){
		delete[] sz;
		delete[] id;
	}
	
	int find(int p){
		int temp = p;
		while(p!=id[p]){
			p = id[p];
		}
		id[temp] = p;
		return p;
	}
	
	
	void Union(int p,int q){
		
		int idp = find(p);
		int idq = find(q);
//	
		
		if(idp==idq){
			return;
		}
		
		if(sz[idp]<sz[idq]){
			id[idp] = idq;
			sz[idq] += sz[idp];
		}else{
			id[idq] = idp;
			sz[idp] += sz[idq];
		}
	}
	
};

int transXY(int i,int j,int w){
	return i*w + j;
}

bool isLegal(int i,int j,int h,int w){
	return ((i>=0) && (i<h) && (j>=0) &&(j<w));
}

bool isDice(int ch){
	return (ch=='X' || ch=='*');
}

bool run(int count){
	int w,h;
	cin >> w >> h;
	if(w==0 && h==0){
		return false;
	}
	
	QU qu_helper = QU(w*h);
	QU dots_helper = QU(w*h);
	
	string blank;
	getline(cin,blank);
	//读入数据 
	char *data = new char[w*h];
	for(int i=0;i<h;i++){
		string buf;
		getline(cin,buf);
		for(int j=0;j<w;j++){
			data[transXY(i,j,w)] = buf[j];
		}
	}
	
	//求联通子图
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(isDice(data[transXY(i,j,w)]) && isLegal(i+1,j,h,w) && isDice(data[transXY(i+1,j,w)])){
				qu_helper.Union(transXY(i,j,w),transXY(i+1,j,w));
			}
			if(isDice(data[transXY(i,j,w)]) && isLegal(i,j+1,h,w) && isDice(data[transXY(i,j+1,w)])){
				qu_helper.Union(transXY(i,j,w),transXY(i,j+1,w));
			}
			if(data[transXY(i,j,w)]=='X' && isLegal(i,j+1,h,w) && data[transXY(i,j+1,w)]=='X'){
				dots_helper.Union(transXY(i,j,w),transXY(i,j+1,w));
			}
			if(data[transXY(i,j,w)]=='X' && isLegal(i+1,j,h,w) && data[transXY(i+1,j,w)]=='X'){
				dots_helper.Union(transXY(i,j,w),transXY(i+1,j,w));
			}							
		}
	}
	
	//数筛子数
	map<int,int> dots;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int posi = transXY(i,j,w);
			if(data[posi]=='X' && dots_helper.find(posi)==posi){
				int id = qu_helper.find(transXY(i,j,w));
				if(dots.find(id)==dots.end()){
					dots[id] = 0;
				}
				dots[id] ++;
			}
		}
	}
	
	cout << "Throw " << count << endl;
	
	vector<int> numbers;
	map<int,int>::iterator it = dots.begin();
	while(it!=dots.end()){
		numbers.push_back(it->second);
		it ++;
	}
	sort(numbers.begin(),numbers.end());
	
	for(int i=0;i<numbers.size();i++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	return true;
}

int main(){
	int count = 1;
	while(run(count)){
		count ++;
	};
	return 0;
}
 
