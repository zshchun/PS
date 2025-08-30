#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF 123456789
int ans, idx;
string s;

int pop_number(int n) {
	bool found = false;
	vector<char> t;
	while (n) {
		t.push_back('0' + (n % 10));
		n /= 10;
	}
	reverse(t.begin(), t.end());
	for (char &c : t) {
		if (c == s[idx]) {
			found = true;
			idx++;
		}
	}
	return found;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> s;
	while (idx < s.size()) {
		for (i=ans+1;i<=100000;i++) {
			if (pop_number(i)) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
