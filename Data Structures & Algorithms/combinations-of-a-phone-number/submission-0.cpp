class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> pad = {
            "abc","def","ghi","jkl",
            "mno","pqrs","tuv","wxyz"
        };

        queue<string> q;
        q.push("");

        for (char d : digits) {
            int sz = q.size();

            while (sz--) {
                string cur = q.front();
                q.pop();

                for (char c : pad[d - '2']) {
                    q.push(cur + c);
                }
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};