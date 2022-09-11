#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int N, M;
vector<P> a;
int ans[9];
void dfs(int c) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (i=0;i<N;i++) {
		if (a[i].second <= 0) continue;
		a[i].second--;
		ans[c] = a[i].first;
		dfs(c+1);
		a[i].second++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int v, found;
	for (int i=0;i<N;i++) {
		cin >> v;
		found = false;
		for (int j=0;j<a.size();j++) {
			if (a[j].first == v) {
				a[j].second++;
				found = true;
				break;
			}
		}
		if (!found)
			a.push_back(P(v, 1));
	}
	N = a.size();
	sort(a.begin(), a.end());
	dfs(0);
	return 0;
}

