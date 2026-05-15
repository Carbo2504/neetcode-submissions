class Solution {
public:

    bool isAnagram(string& s, string& t) {
        unordered_map<char, int> m;
        int s_size = s.size();
        int t_size = t.size();

        if (s_size != t_size)
            return false;

        for (int i = 0; i<s_size; ++i) {
            m[s[i]] += 1;
        }
        for (int i = 0; i<t_size; ++i) {
            if (m[t[i]] > 0)
                m[t[i]] -= 1;
            else return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        int i = 0;
        vector<vector<string>> output;
        unordered_set<int> visited;
        for (int i = 0; i<size; ++i) {
            if (visited.count(i))
                continue;
            vector<string> ams;
            ams.push_back(strs[i]);
            visited.insert(i);
            for (int j = i + 1; j < size; ++j) {
                if (!visited.count(j) && isAnagram(strs[i], strs[j])) {
                    ams.push_back(strs[j]);
                    visited.insert(j);
                }
            }
            output.push_back(ams);
        }
        return output;
    }
};
