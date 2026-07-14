class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> tr;
        int n=beginWord.size();
        string bw=beginWord;
        for(int i=0;i<n;i++){
            char temp=beginWord[i];
            beginWord[i]='*';
            tr[beginWord].push_back(bw);
            beginWord[i]=temp;
        }
        for(auto a:wordList){
            auto tm=a;
            for(int i=0;i<n;i++){
                char temp=a[i];
                a[i]='*';
                tr[a].push_back(tm);
                a[i]=temp;
            }
        }
        unordered_set<string> visit{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return res;
                }
                for (int j = 0; j < word.size(); ++j) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (const string& neiWord : tr[pattern]) {
                        if (visit.find(neiWord) == visit.end()) {
                            visit.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                    tr[pattern].clear();
                }
            }
            ++res;
        }
        return 0;

    }
};
