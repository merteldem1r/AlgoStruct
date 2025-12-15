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

// Time: O(F × T × log(F × T)) F: number of followees, T: tweets per followee || Space: O(n)
class TwitterSolution1
{
private:
    long long time;
    std::unordered_map<int, std::unordered_set<int>> followingMap;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap;

    struct Comparator
    {
        bool operator()(std::pair<int, int> a, std::pair<int, int> b)
        {
            return a.second < b.second;
        }
    };

public:
    TwitterSolution1()
    {
        this->time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweetMap[userId].emplace_back(tweetId, time);
        if (tweetMap[userId].size() > 10)
        {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        ++time;
    }

    // Time: O(F × T × log(F × T)) F: number of followees, T: tweets per followee || Space: O(n)
    std::vector<int> getNewsFeed(int userId)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            Comparator>
            maxHeap;
        std::vector<int> res;

        // 1. personal tweets
        for (auto &tweet : tweetMap[userId])
        {
            maxHeap.push(tweet);
        }

        // 2. friends tweets
        for (int followeeId : followingMap[userId]) // O(F) - only followed users
        {
            for (auto &tweet : tweetMap[followeeId]) // O(T)
            {
                maxHeap.push(tweet); // O(log heap_size)
            }
        }

        // 3. collect mru tweets
        while (!maxHeap.empty() && res.size() < 10) // O(10 × log heap_size)
        {
            res.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        followingMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        if (followingMap[followerId].count(followeeId) > 0)
        {
            followingMap[followerId].erase(followeeId);
        }
    }

    bool areFollowing(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        return followingMap[followerId].count(followeeId) > 0;
    }
};

// ******************************* Solution OOP Design *******************************

// Time: O(F × logF) Space: O(F) F: number of followees
class Twitter
{
private:
    long long time = 0;

    struct Tweet
    {
        int id;
        int timestamp;
        Tweet *next;

        Tweet(int id, int timestamp)
            : id(id), timestamp(timestamp), next(nullptr) {}
    };

    struct User
    {
        int id;
        std::unordered_set<int> followed;
        Tweet *tweetHead;

        User(int id) : id(id), tweetHead(nullptr)
        {
            follow(id); // follow self
        }

        void follow(int followeeId) { followed.insert(followeeId); }

        void unfollow(int followeeId)
        {
            if (followeeId != id)
                followed.erase(followeeId);
        }

        void post(int tweetId, int time)
        {
            Tweet *newTweet = new Tweet(tweetId, time);
            newTweet->next = tweetHead;
            tweetHead = newTweet;
        }
    };

    struct Comparator
    {
        bool operator()(Tweet *a, Tweet *b)
        {
            return a->timestamp < b->timestamp;
        }
    };

    std::unordered_map<int, User *> userMap;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) // Time: O(1) Space: O(1)
    {
        if (!isUser(userId))
            createUser(userId);

        userMap[userId]->post(tweetId, time++);
    }

    std::vector<int> getNewsFeed(int userId) // Time: O(F × logF) Space: O(F) F: number of followees
    {
        std::vector<int> res;
        if (!isUser(userId))
            return res;

        std::priority_queue<Tweet *, std::vector<Tweet *>, Comparator> maxHeap;

        auto &users = userMap[userId]->followed;
        for (int uid : users)
        {
            if (userMap.count(uid) && userMap[uid]->tweetHead != nullptr)
                maxHeap.push(userMap[uid]->tweetHead);
        }

        int n = 0;
        while (!maxHeap.empty() && n < 10) // O(10 × logF)
        {
            Tweet *top = maxHeap.top();
            maxHeap.pop();

            res.push_back(top->id);
            n++;

            if (top->next != nullptr)
                maxHeap.push(top->next);
        }

        return res;
    }

    void follow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        checkUser(followerId);
        checkUser(followeeId);
        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) // Time: O(1) Space: O(1)
    {
        if (!isUser(followerId) || !isUser(followeeId))
            return;
        userMap[followerId]->unfollow(followeeId);
    }

private:
    bool isUser(int userId) { return userMap.count(userId) > 0; } // Time: O(1) Space: O(1)

    void createUser(int userId) { userMap[userId] = new User(userId); } // Time: O(1) Space: O(1)

    void checkUser(int userId) // Time: O(1) Space: O(1)
    {
        if (!isUser(userId))
            createUser(userId);
    }
};

int main()
{
    return 0;
}