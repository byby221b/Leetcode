/*
	Name: 
	Copyright: 
	Author: 
	Date: 03/07/19 18:56
	Description: dfs+剪枝
				剪枝策略：相同面值的邮票最多要5张(因为答案要求最多四张邮票) 
				题目存在问题,邮票数目可能超过25张,开30的数组会RE 
*/

#include <iostream>
#include <cstring>
using namespace std;

int stamp[10005];
int value_count[10005];
int count = 0;
int result[10005];
int path[10005];
int maxTypes,minTotal,highValue;
bool tied;

int cmp(int types,int total,int highest){
	if(maxTypes == -1){
		return 1;
	}
	
	if(maxTypes < types){
		return 1;
	}else if(maxTypes == types){
		if(minTotal > total){
			return 1;
		}else if(minTotal == total){
			if(highValue < highest){
				return 1;
			}else if(highValue==highest){
				return 0;
			}
		}
	}
	
	return -1;
}

void dfs(int level,int types,int total,int *path,int highest,int value,int target){
	
	if(level>count || value>target || total>4){
		return;
	}
	
	if(value==target){
		int res = cmp(types,total,highest);
		if(res==0){
			tied = true;
		}else if(res==1) {
			for(int i=0;i<count;i++){
				result[i] = path[i];
			}
			maxTypes = types;
			minTotal = total;
			highValue = highest;
			tied = false;
		}
		return;
	}
	
	if(level==count){
		return;
	}
	
	int curr_high = (highest > stamp[level]) ? highest : stamp[level];
	
	dfs(level+1,types,total,path,highest,value,target);
	for(int i=1;i<=4;i++){
		path[level] = i;
		dfs(level+1,types+1,total+i,path,curr_high,value+stamp[level]*i,target);
		path[level] = 0;
	}
}

void output(int target){
	
	if(maxTypes==-1){
		//none
		cout << target << " ---- none" << endl;
	}else if(tied){
		//tie
		cout << target << " " << "(" << maxTypes << "): tie" << endl;
	}else{
		cout << target << " " << "(" << maxTypes << "):";
		for(int i=0;i<count;i++){
			for(int j=0;j<result[i];j++){
				cout << " " << stamp[i];
			}
		}
		cout << endl;
	}
}

bool run(){
	
	count = 0;//邮票种类数 
	int value = -1;
	
	memset(value_count,0,sizeof(value_count));
	
	while(cin>>value){
		if(value==0) break;
		
		if(value_count[value]<5){
			stamp[count] = value;
			count ++;
			value_count[value]++;
		}
	}
	
	if(count==0) return false;
	
	while(true){
		cin >> value;
		if(value==0) break;
		maxTypes = -1;
		minTotal = -1;
		highValue = -1;
		tied = false;	
		memset(path,0,sizeof(path));
		dfs(0,0,0,path,0,0,value);
		output(value);
	}

	return true;
	
}


int main(){
	while(run());
	return 0;
}

