#include <set>
#include <map>
#include <queue>
#include <utility>
#include <iostream>

using namespace std; 

/* -------- Subject --------  
Implement a simplified version of Twitter which allows users to post tweets, follow/unfollow each other, and view the 10 most recent tweets within their own news feed.
Users and tweets are uniquely identified by their IDs (integers).
Implement the following methods:
    - Twitter() Initializes the twitter object.
    - void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. You may assume that each tweetId is unique.
    - List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent tweet IDs in the user's news feed. Each item must be posted by users who the user is following or by the user themself. Tweets IDs should be ordered from most recent to least recent.
    - void follow(int followerId, int followeeId) The user with ID followerId follows the user with ID followeeId.
    - void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId. */ 

class Twitter 
{
    private:
    int timestamp; //A counter to simulate the timestamp of tweets. 
    map<int, vector<pair<int, int>>> tweets; //UserID -> [(timestamp, tweetId)]. 
    map<int, set<int>> following; //UserID -> Set of followed user IDs.

    public:
    Twitter() : timestamp(0) {} 
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({timestamp++, tweetId}); //Add tweet with current timestamp. 
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int, int>> pq; // Max-heap to get the most recent tweets
        
        for (const pair<int, int>& tweet : tweets[userId])  //Add user's own tweets
        {
            pq.push(tweet);
        }
        
        for (const int& followeeId : following[userId]) //Add tweets from followed users
        {
            for (const pair<int,int>& tweet : tweets[followeeId]) 
            {
                pq.push(tweet);
            }
        }
        
        vector<int> newsFeed;
        int count = 0;
        while (!pq.empty() && count < 10) //Get at most 10 most recent tweets.
        {
            newsFeed.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId) //Prevent users from following themselves. 
        { 
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        following[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter twitter; 
    twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
    twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
    twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
    twitter.getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
    twitter.follow(1, 2);     // User 1 follows user 2.
    twitter.getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
    twitter.getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
    twitter.unfollow(1, 2);   // User 1 follows user 2.
    twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
    
    return 0; 
}