#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, i, p;
	cin >> n >> k;
	vector<int> q;
	for (i=1;i<=n;i++) {
		q.push_back(i);
	}
	cout << "<";
	p = -1;
	while(q.size() > 1) {
		p = (p + k) % q.size();
		cout << q[p] << ", ";
		q.erase(q.begin()+p);
		p = (p + q.size()-1) % q.size();
	}
	cout << q[0] << ">\n";
	return 0;
}
