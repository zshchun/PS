#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;
vector<int> a;
vector<int> b;

vector<int> solve(vector<int> a, vector<int> b, vector<int> ans) {
	if (a.empty() || b.empty()) {
		return ans;
	}
	auto ita = max_element(a.begin(), a.end());
	auto itb = max_element(b.begin(), b.end());
	int mxa = *ita;
	int mxb = *itb;
	if (mxa == mxb) {
		a.erase(a.begin(), ita+1);
		b.erase(b.begin(), itb+1);
		ans.push_back(mxa);
		return solve(a, b, ans);
	} else if (mxa > mxb) {
		a.erase(ita);
		return solve(a, b, ans);
	} else {
		b.erase(itb);
		return solve(a, b, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, x;
	vector<int> ans;

	cin >> N;
	a.resize(N);
	for (i=0;i<N;i++)
		cin >> a[i];

	cin >> M;
	b.resize(M);
	for (i=0;i<M;i++)
		cin >> b[i];

	ans = solve(a, b, vector<int>());

	cout << ans.size() << endl;
	for (int q: ans)
		cout << q << " ";
	cout << endl;

	return 0;
}
