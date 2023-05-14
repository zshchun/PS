#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, v, i, ans;
	cin >> N;
	priority_queue<pa, vector<pa>, greater<pa>> pq;
	for (i=1;i<=N;i++) {
		cin >> v;
		while (!pq.empty() && pq.top().first < v) {
			pq.pop();
		}
		if (pq.empty()) {
			cout << 0 << ' ';
		} else {
			cout << pq.top().second << ' ';
		}
		pq.push(pa(v, i));
	}
	cout << endl;

	return 0;
}
