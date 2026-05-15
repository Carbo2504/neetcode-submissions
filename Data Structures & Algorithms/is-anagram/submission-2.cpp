class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> reps;
        int t_size = t.size();
        int s_size = s.size();
        if (s_size != t_size)
            return false;
        for (int i = 0; i < s_size; ++i) {
            reps[s[i]] += 1;
        }

        for (int i = 0; i < t_size; ++i) {
            if (reps[t[i]])
                reps[t[i]] -= 1;
            else return false;
        }
        
        return true;
    }
};
