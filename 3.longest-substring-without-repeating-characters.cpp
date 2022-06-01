class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	    int m[128];
	    int l = 0, r = 0, maxCount = 0;
	    fill_n(m, 128, -1);
	    while (r < s.size()) {
		    char c = s[r];
		    if (m[c] != -1 && m[c] >= l && m[c] < r) {
			    l = m[c] + 1;
		    }
		    maxCount = max(maxCount, r - l + 1);
		    m[c] = r;
		    r++;
	    }
	    return maxCount;
    }
};
