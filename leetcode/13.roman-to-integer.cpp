// leetgo: dev
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int romanToInt(string s) {
	    int ret = 0;
	    char prev = ' ';
	    for (int i=s.size()-1;i >= 0; i--) {
		    char c = s[i];
		    int num = 0;
		    switch (c) {
			    case 'I':
				    num = 1;
				    if (prev == 'V' || prev == 'X')
					    num = -num;
				    break;
			    case 'V':
				    num = 5;
				    break;
			    case 'X':
				    num = 10;
				    if (prev == 'L' || prev == 'C')
					    num = -num;
				    break;
			    case 'L':
				    num = 50;
				    break;
			    case 'C':
				    num = 100;
				    if (prev == 'D' || prev == 'M')
					    num = -num;
				    break;
			    case 'D':
				    num = 500;
				    break;
			    case 'M':
				    num = 1000;
				    break;
		    }
		    prev = c;
		    ret += num;
	    }
	    return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.romanToInt(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
