#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

void output(vector<Interval> data){
	for(int i=0;i<data.size();i++){
		cout << data[i].start << " " << data[i].end << endl;
	}
}

bool cmp(Interval a,Interval b){
    return a.start<b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.empty()){
        return intervals;
    }
    sort(intervals.begin(),intervals.end(),[](Interval a,Interval b)->bool{return a.start<b.start;});
    vector<Interval> result;
    for(int i=0;i<intervals.size();i++){
        Interval tmp = intervals[i];
        while(i<intervals.size()-1 && tmp.end >= intervals[i+1].start){
            tmp.end = max(tmp.end,intervals[i+1].end);
//            cout << "cmp:" << intervals[i].end << " " << intervals[i+1].end<< " " << max(intervals[i].end,intervals[i+1].end) << endl;
            i++;
            if(i==intervals.size()) break;
        }
        result.push_back(tmp);
    }
    return result;
}

int main(){
	Interval _a[] = {Interval(2,3),Interval(4,5),Interval(6,7),Interval(8,9),Interval(1,10)};
	vector<Interval> a(_a,_a+sizeof(_a)/sizeof(_a[0]));
//	merge(a);
	output(merge(a));
	return 0;
}

