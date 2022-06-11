#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, v, i;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v)
			pq.push(v);
		else
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
	}
	return 0;
}
