#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string s;
vector<int> g[2501];
int visited[2501];
int N, last;

bool is_palindrome(string &t) {
	string x = t;
	reverse(x.begin(), x.end());
	if (t == x) {
		return true;
	}
	return false;
}

void bfs() {
	int cur, i;
	queue<int> q;
	q.push(0);
	visited[0] = 0;
//	for (i=0;i<N;i++) {
//		string t = s.substr(0, i+1);
//		if (is_palindrome(t)) {
//			q.push(i);
//			visited[i] = 0;
//		}
//	}

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur == N) break;

		for (int next : g[cur]) {
			if (visited[next] <= visited[cur] + 1)
				continue;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans, last;
	cin >> s;
	ans = N = s.size();
	last = N;
	fill(visited, visited+2501, N);

	for (i=0;i<N;i++) {
		for (j=1;i+j<=N;j++) {
			string t = s.substr(i, j);
			if (is_palindrome(t)) {
				g[i].push_back(i+j);
			}
		}
	}

	for (i=N-2;i>=0;i--) {
		string t = s.substr(i, N-i);
		if (is_palindrome(t))
			g[i].push_back(N);
	}

	bfs();

	cout << visited[N] << endl;

	return 0;
}
