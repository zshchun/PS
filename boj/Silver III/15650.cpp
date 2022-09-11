#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j;
	cin >> N >> M;
	vector<int> v;
	for (i=0;i<M;i++) {
		v.push_back(1);
	}
	for (i=0;i<N-M;i++) {
		v.push_back(0);
	}
	do {
		for (i=0;i<N;i++) {
			if (v[i])
				cout << i+1 << ' ';
		}
		cout << '\n';
	} while (prev_permutation(v.begin(), v.end()));
	return 0;
}

