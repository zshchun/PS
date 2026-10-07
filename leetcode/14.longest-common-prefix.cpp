// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	    int size = strs[0].size();
	    for (string &s: strs) {
		    int i;
		    for (i = 0; i < size; i++) {
			    if (strs[0][i] != s[i])
				    break;
		    }
		    size = min(i, size);
	    }
	    return strs[0].substr(0, size);
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> strs = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.longestCommonPrefix(strs);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
