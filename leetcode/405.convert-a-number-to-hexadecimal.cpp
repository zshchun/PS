class Solution {
public:
    string toHex(int num) {
	    if (num == 0) return "0";
	    string result;
	    unsigned i = num;
	    while (i) {
		    unsigned int nibble = i & 15;
		    if (nibble <= 9) {
			    result += nibble+'0';
		    } else {
			    result += nibble-10+'a';
		    }
		    i = i >> 4;
	    }
	    reverse(result.begin(), result.end());
	    return result;
    }
};
