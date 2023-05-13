#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N;

bool is_good_seq(string &s) {
	for (unsigned int i=1;i<=s.size()/2;i++) {
		if (s.substr(s.size()-i, i) == s.substr(s.size()-(i*2), i))
			return false;
	}
	return true;
}

string backtrack(string s, int n) {
	char c;
	if (n == N)
		return s;
	string x;
	for (c='1';c<='3';c++) {
		x = s + c;
		if (is_good_seq(x)) {
			x = backtrack(x, n + 1);
			if (x != "")
				return x;
		}
	}
	return "";
}

int main() {
	cin >> N;
	string ans = backtrack("1", 1);
	cout << ans << endl;
	return 0;
}
