class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // Agar endWord hi dictionary me nahi hai
        if(wordSet.find(endWord) == wordSet.end())
            return 0;

        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);

        int level = 1;   // beginWord bhi sequence me count hota hai

        while(!q.empty()) {

            int n = q.size();

            while(n--) {

                string curr = q.front();
                q.pop();

                if(curr == endWord)
                    return level;

                for(int i = 0; i < curr.length(); i++) {

                    char original = curr[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        if(ch == original)
                            continue;

                        curr[i] = ch;

                        if(wordSet.find(curr) != wordSet.end() &&
                           visited.find(curr) == visited.end()) {

                            visited.insert(curr);
                            q.push(curr);
                        }
                    }

                    // Original character wapas kar do
                    curr[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};