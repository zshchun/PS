int m[20001];
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int i, ans=0;
		int sum = 0;
		unordered_map<int,int> u;
		for (i=0;i<nums.size();i++) {
			sum += nums[i];
			m[i] = sum;
//			for (auto &it : u) {
//				if (k == sum - it.first)
//					ans += it.second;
//			}
			if (u.count(sum-k)) ans += u[sum-k];
			u[sum]++;
			if (sum == k) ans++;
		}
		return ans;
	}
};
