#include<iostream>
#include<vector>
#include <list>
using namespace std;

void Nhap(vector<vector<long long>>& graph, int& n, int& m) {
	int x, y;
	cin >> n >> m;
	vector<long long>e;
	for (int i = 0; i < n; i++)
		graph.push_back(e);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int j = 0;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

list<long long>* graph;

void Nhap(int& n, int& m) {
	int x, y;
	cin >> n >> m;
	graph = new list<long long>[n];
	list<long long>e;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

void Visit(vector<vector<long long>>graph, bool* visited, int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (visited[graph[v][i]] == false) {
			Visit(graph, visited, graph[v][i]);
		}
	}
}

void Visit(bool* visited, int v) {
	visited[v] = true;
	list<long long>::iterator it;
	for (it = graph[v].begin(); it != graph[v].end();it++) {
		if (visited[*it] == false)
			Visit(visited, *it);
	}
}

int countConnectedComponent(vector<vector<long long>>graph, int n) {
	bool* visited;
	visited = new bool[n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			Visit(graph, visited, i);
			res++;
		}
	}
	return res;
}

int countConnectedComponent(int n) {
	bool* visited;
	visited = new bool[n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			Visit(visited, i);
			res++;
		}
	}
	return res;
}

int main() {
	int m, n;
	vector<vector<long long>>graph1;
	Nhap(n, m);
	cout << countConnectedComponent(n);
	return 0;
}