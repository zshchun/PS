class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	    int strMap[257] = { 0, };
	    int maxCount = 0;
	    int count = 0;
	    for (int i=1;i<=s.size();i++) {
		    char c = s[i-1];
		    if (strMap[c]) {
			    if (count > maxCount)
				    maxCount = count;
			    count = 0;
			    i = strMap[c];
			    memset(strMap, 0, sizeof(strMap));
			    continue;
		    }
		    strMap[c] = i;
		    count++;
	    }
	    if (count > maxCount)
		    maxCount = count;
	    return maxCount;
    }
};
