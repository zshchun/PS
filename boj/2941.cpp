#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int i, cnt=0, step, p;
	vector<string> cr = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string s;
	cin >> s;
	for (p=0;p<s.size();p+=step) {
		step = 1;
		for (string w : cr) {
			if (s.compare(p, w.size(), w) == 0) {
				step = w.size();
				break;
			}
		}
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
