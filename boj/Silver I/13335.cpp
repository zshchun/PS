#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int sum, ans = 0;
queue<int> q;

void advance(int v) {
	q.push(v);
	sum += v - q.front();
	q.pop();
	ans++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, w, l;
	int s, e, i;
	cin >> n >> w >> l;
	vector<int> a(n);
	for (i=0;i<n;i++)
		cin >> a[i];
	sum = 0;
	for (i=0;i<w;i++)
		q.push(0);

	for (int x : a) {
		if (x + sum <= l) {
			advance(x);
		} else {
			while (x + sum > l) {
				advance(0);
			}
			q.back() = x;
			sum += x;
		}
	}
	while (sum > 0)
		advance(0);
	cout << ans << endl;
	return 0;
}
