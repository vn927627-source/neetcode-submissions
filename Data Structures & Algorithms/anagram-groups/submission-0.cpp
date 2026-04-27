class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> key;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            bool check = false;

            for (int j = 0; j < key.size(); j++) {
                if (temp == key[j]) {
                    ans[j].push_back(strs[i]);
                    check = true;
                    break;
                }
            }

            if (check == false) {
                key.push_back(temp);
                ans.push_back({strs[i]});
            }
        }

        return ans;
    }
};