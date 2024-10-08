class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto& r : mp) {
            ret.push_back(r.second);
        }
        return ret;
    }
};