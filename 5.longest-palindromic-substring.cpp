class Solution {
public:
    string longestPalindrome(string s) {
	    int n = s.size()-1;
	    while (n > 0) {
		    for (int i=0;i+n<s.size();i++) {
			    if (isPalindrome(s, i, i+n))
				    return string(s.begin()+i, s.begin()+i+n+1);
		    }
		    n--;
	    }
	    return string(s.begin(), s.begin()+1);
    }
    bool isPalindrome(string &s, int l, int r) {
	    if (l == r) return true;
	    int n = r - l + 1;
	    for (int i=0;i<n/2;i++) {
		    if (s[l+i] != s[r-i])
			    return false;
	    }
	    return true;
    }
};
