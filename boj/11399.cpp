#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, i,  p, s, t;
	vector<int> ts;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> t;
		ts.push_back(t);
	}
	sort(ts.begin(), ts.end());
	for (i=0, p=0, s=0;i<n;i++) {
		s += ts[i];
		p += s;
	}
	cout << p << "\n";
	return 0;
}

