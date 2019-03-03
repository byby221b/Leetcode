#include <iostream> 
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;


/*

*/
struct TwitterPost {
  int userId,tweetId;
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        TwitterPost *newTwitter = new TwitterPost; 
        newTwitter->userId = userId;
        newTwitter->tweetId = tweetId;
        Records.push_back(newTwitter);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        bool followFlag = false;
        set<int> followees;
        if(followMap.find(userId)!=followMap.end()){
            followFlag = true;
            followees = followMap[userId];
        }
        
//        for(set<int>::iterator it=followees.begin();it!=followees.end();it++){
//        	cout << *it << "\t";
//		}
//		cout << endl;
        
        vector<int> result;
        
        int count = 0;
        for(int i=Records.size()-1;i>=0;i--){
            int tmpUser = (Records[i])->userId;
            if(tmpUser==userId || (followFlag && followees.find(tmpUser)!=followees.end())){
                result.push_back((Records[i])->tweetId);
                count ++;
            }
            
            if(count==10)
                break;
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followMap.find(followerId)==followMap.end()){
            set<int> r;
            followMap[followerId] = r;
        }
        
        followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followMap.find(followerId)==followMap.end() || followMap[followerId].find(followeeId)==followMap[followerId].end()){
            return;
        }
        
        followMap[followerId].erase(followMap[followerId].find(followeeId));
        
    }
    
private:
    unordered_map<int,set<int> > followMap;
    vector<TwitterPost *> Records;
};


void output(vector<int> a){
	for(int i=0;i<a.size();i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}

int main(){
	Twitter twitter;
	twitter.postTweet(1,6765);
	twitter.postTweet(5,671);
	twitter.postTweet(3,2868);
	twitter.postTweet(4,8148);
	twitter.postTweet(4,386) ;
	twitter.postTweet(3,6673);
	twitter.postTweet(3,7946);
	twitter.postTweet(3,1445);
	twitter.postTweet(4,4822);
	twitter.postTweet(1,3781);
	twitter.postTweet(4,9038);
	twitter.postTweet(1,9643);
	twitter.postTweet(3,5917);
	twitter.postTweet(2,8847);
	twitter.follow(1,3);
	twitter.follow(1,4);
	twitter.follow(4,2);
	twitter.follow(4,1);
	twitter.follow(3,2);
	twitter.follow(3,5);
	twitter.follow(3,1);
	twitter.follow(2,3);
	twitter.follow(2,1);
	twitter.follow(2,5);
	twitter.follow(5,1);
	twitter.follow(5,2);
//	vector<int> query27 = twitter.getNewsFeed(1);
	vector<int> query28 = twitter.getNewsFeed(2);
//	vector<int> query29 = twitter.getNewsFeed(3);
//	vector<int> query30 = twitter.getNewsFeed(4);
//	vector<int> query31 = twitter.getNewsFeed(5);
	output(query28);
	return 0;
}
