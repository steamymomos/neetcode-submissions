class Twitter {
public:
    int count;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    unordered_map<int,unordered_set<int>> followmap;
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count,tweetId});
        if(tweetmap[userId].size()>10){
            tweetmap[userId].erase(tweetmap[userId].begin());
        }
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followmap[userId].insert(userId);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        if(followmap[userId].size()>=10){
            priority_queue<vector<int>> maxheap;
            for(auto f:followmap[userId]){
                if(!tweetmap.count(f))continue;
                int idx=tweetmap[f].size()-1;
                auto &p=tweetmap[f][idx];
                maxheap.push({-p.first,p.second,f,idx-1});
                if(maxheap.size()>10)maxheap.pop();
            }
            while(!maxheap.empty()){
                auto t=maxheap.top();
                maxheap.pop();
                minheap.push({-t[0],t[1],t[2],t[3]});
            }
        }
        else{
            for(auto f:followmap[userId]){
                if(!tweetmap.count(f))continue;
                int idx=tweetmap[f].size()-1;
                auto &p=tweetmap[f][idx];
                minheap.push({p.first,p.second,f,idx-1});
            }
        }
        while(!minheap.empty() && res.size()<10){
            auto t=minheap.top();
            minheap.pop();
            res.push_back(t[1]);
            int idx=t[3];
            if(idx>=0){
                auto &p=tweetmap[t[2]][idx];
                minheap.push({p.first,p.second,t[2],idx-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followmap[followerId].count(followeeId)){
            followmap[followerId].erase(followeeId);
        }
    }
};
