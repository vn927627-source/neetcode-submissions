class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> value;
        vector<int> count;

        for (int i = 0; i < nums.size(); i++) {
            bool check = false;

            for (int j = 0; j < value.size(); j++) {
                if (nums[i] == value[j]) {
                    count[j]++;
                    check = true;
                    break;
                }
            }

            if (check == false) {
                value.push_back(nums[i]);
                count.push_back(1);
            }
        }

        for (int i = 0; i < value.size(); i++) {
            for (int j = i + 1; j < value.size(); j++) {
                if (count[i] < count[j]) {
                    swap(count[i], count[j]);
                    swap(value[i], value[j]);
                }
            }
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(value[i]);
        }

        return ans;
    }
};