class Solution {
public:
    int findLHS(vector<int>& nums) {
	    int mx = 0;
	    map<int,int> range;
	    for (int &x : nums) {
		    range[x]++;
	    }
	    for (auto it = range.begin(); it != range.end(); it++) {
		    int x = (*it).first;
		    if (range.count(x+1) > 0)
			    mx = max(mx, range[x] + range[x+1]);

	    }
	    return mx;
    }
};
