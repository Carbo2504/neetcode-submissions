class Solution {
public:
    bool isValid(string s) {
        vector<char> pars = {};
        for (auto c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                pars.push_back(c);
            else {
                if (c == ')') {
                    if (pars.empty() || pars[pars.size()-1] != '(')
                        return false;
                    pars.erase(pars.end());
                }
                else if (c == ']') {
                    if (pars.empty() || pars[pars.size()-1] != '[')
                        return false;
                    pars.erase(pars.end());
                }
                else if (c == '}') {
                    if (pars.empty() || pars[pars.size()-1] != '{')
                        return false;
                    pars.erase(pars.end());
                }
            }
        }
        if (pars.size() > 0)
            return false;
        return true;
    }
};
