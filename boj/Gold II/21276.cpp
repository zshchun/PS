#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M;
int p[1001];
int ind[1001];
bool used[1001];
set<string> family;
vector<string> children[1001];
vector<int> descendant[1001];
vector<int> g[1001];
map<string,int> name_to_num;
map<int,string> num_to_name;

void topological_sort() {
	int i;
	queue<int> q;
	for (i=0;i<N;i++)
		if (ind[i] == 0)
			q.push(i);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (g[cur].empty())
			family.insert(num_to_name[cur]);

		for (int &next : g[cur]) {
			ind[next]--;

			if (ind[next] == 0) {
				for (int &des : descendant[next]) {
					if (!used[des]) {
						children[next].push_back(num_to_name[des]);
						used[des] = 1;
					}
				}
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	string s, t;
	cin >> N;
	vector<string> a(N);
	fill_n(p, 1001, -1);

	for (i=0;i<N;i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	for (i=0;i<N;i++) {
		name_to_num[a[i]] = i;
		num_to_name[i] = a[i];
	}

	cin >> M;
	for (i=0;i<M;i++) {
		cin >> s >> t;
		u = name_to_num[s];
		v = name_to_num[t];
		g[u].push_back(v);
		descendant[v].push_back(u);
		ind[v]++;
	}
	topological_sort();

	cout << family.size() << endl;
	for (auto it = family.begin();it != family.end();it++) {
		cout << *it << ' ';
	}
	cout << endl;

	for (i=0;i<N;i++) {
		s = num_to_name[i];
		cout << s << ' ' << children[i].size() << ' ';
		sort(children[i].begin(), children[i].end());
		for (string &x : children[i])
			cout << x << ' ';
		cout << endl;

	}

	return 0;
}
