#include <iostream>
#include <unordered_set>

// LeetCode: 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.

Example 1:
    Input
        ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
        [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    Output>
        [null, null, [5], null, null, [6, 5], null, [5]]

    Explanation
        Twitter twitter = new Twitter();
        twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
        twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
        twitter.follow(1, 2);    // User 1 follows user 2.
        twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
        twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
        twitter.unfollow(1, 2);  // User 1 unfollows user 2.
        twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.

*/

class TwitterSolutionMinHeap
{
private:
    int tweetPriority = 0;
    std::unordered_map<int, std::unordered_set<int>> followingMap;
    std::unordered_map<int, std::pair<int, int>> priorityUserTweetMap;

    struct Comparator
    {
        bool operator()(std::pair<int, int> a, std::pair<int, int> b) const
        {
            return a.second < b.second;
        }
    };

public:
    TwitterSolutionMinHeap() {}

    void postTweet(int userId, int tweetId) // Time: O(1) Space: O(1)
    {
        priorityUserTweetMap[tweetPriority] = {userId, tweetId};
        ++tweetPriority;
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<std::pair<int, int>> tweets;

        for (auto &entity : priorityUserTweetMap)
        {
            auto [postUserId, postTweetId] = entity.second;

            if (userId == postUserId || areFollowing(userId, postUserId))
            {
                tweets.emplace_back(postTweetId, entity.first);
            }
        }

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, Comparator>
            minHeap(tweets.begin(), tweets.end());
        std::vector<int> resTweets;

        while (minHeap.size() > 0 && resTweets.size() != 10)
        {
            resTweets.emplace_back(minHeap.top().first);
            minHeap.pop();
        }

        return resTweets;
    }

    void follow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        followingMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        if (areFollowing(followerId, followeeId))
        {
            followingMap[followerId].erase(followeeId);
        }
    }

    bool areFollowing(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        return followingMap[followerId].count(followeeId) > 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
    return 0;
}