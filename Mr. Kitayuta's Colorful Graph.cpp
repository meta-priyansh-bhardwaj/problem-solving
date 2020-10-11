#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <set>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <numeric>
using namespace std;
vector < pair<int, int> > vect[101];
int counts;
bool dfs(int vertix , int color , vector <bool> &visited , int lastV) {
	visited[vertix] = true;
	if (vertix == lastV) return true;
	for (int i = 0; i < vect[vertix].size(); i++) {
		pair<int, int> pa = vect[vertix][i];
		if (!visited[pa.first] && pa.second == color) {
			if (dfs(pa.first, pa.second, visited, lastV)) return true;
		}
	}
	return false;
}
int main(void) {
	int edges, vertices;
	cin >> vertices >> edges;
	for (int i = 1; i <= edges; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vect[a].push_back(make_pair(b, c));
		vect[b].push_back(make_pair(a, c));
	}
	int questions;
	cin >> questions;
	for (int i = 0; i < questions; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		counts = 0;
		for (int j = 1; j <= 100; j++) {
			vector <bool> visited(101, 0);
			if (dfs(v1, j, visited, v2)) counts++;
		}
		cout << counts << endl;
	}
	return 0;
}