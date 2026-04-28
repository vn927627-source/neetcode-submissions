class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> a;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            bool check = false;

            for (int j = 0; j < a.size(); j++) {
                if (a[j].first == nums[i]) {
                    a[j].second++;
                    check = true;
                    break;
                }
            }

            if (check == false) {
                a.push_back({nums[i], 1});
            }
        }

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a[i].second < a[j].second) {
                    swap(a[i], a[j]);
                }
            }
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(a[i].first);
        }

        return ans;
    }
};