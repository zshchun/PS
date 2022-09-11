#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	string s, e;
	vector<char> q;
	cin >> s >> e;
	n = e.size();
	int j;
	for(i=0;i<s.size();i++) {
		q.push_back(s[i]);

		if (q.size() < n) continue;
		for (j=0;j<n;j++)
			if (q[q.size()-n+j] != e[j]) break;
		if (j == n)
			q.erase(q.end()-n, q.end());
	}
	if (q.empty())
		cout << "FRULA\n";
	else
		cout << string(q.begin(), q.end()) << '\n';
	return 0;
}

