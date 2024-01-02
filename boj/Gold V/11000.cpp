#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	cin >> N;
	vector<pa> a(N);
	for (i=0;i<N;i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	priority_queue<int, vector<int>, greater<int>> pq;

	for (i=0;i<N;i++) {
		pq.push(a[i].second);
		if (pq.top() <= a[i].first)
			pq.pop();
	}

	cout << pq.size() << endl;
	return 0;
}
