class Solution {
public:
    bool isPalindrome(int x) {
	    long rev=0, t=x;
	    if (t < 0) return false;
	    while (t) {
		    rev = (rev * 10) + (t % 10);
		    t /= 10;
	    }
	    return x == rev;
    }
};
