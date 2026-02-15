#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, T;
#define R second
#define L first

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	string s, ans;
	cin >> N >> T >> s;
	ans = s;
	vector<pa> wave;
	for (i=1;i<N-1;i++) {
		if (s[i-1] != s[i] && s[i] != s[i+1]) {
			if (wave.empty() || wave.back().R != i-1)
				wave.push_back(pa(i, i));
			else
				wave.back().R = i;
		}
	}
	for (auto [l, r] : wave) {
		j = (r - l + 1);
		for (i=0;i<min(T, (j+1)/2);i++) {
			ans[l+i] = s[l-1];
			ans[r-i] = s[r+1];
		}
		if (T & 1 && j > T * 2) {
			for (k=l+T;k<=r-T;k++) {
				ans[k] = ans[k] == 'A' ? 'B' : 'A';
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
