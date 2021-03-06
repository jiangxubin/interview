﻿// Interview.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma once
#include <iostream>
#include <vector>

using namespace std;

int N;
vector< vector<char> > maps;
int best_res;

bool judge(int x, int y) {
	for (int i = x; i >= 0; --i) {
		if (maps[i][y] == 'E') return false;
		else if (maps[i][y] == 'X') break;
	}
	for (int j = y; j >= 0; --j) {
		if (maps[x][j] == 'E') return false;
		else if (maps[x][j] == 'X') break;
	}
	return true;
}

void DFS(int index, int total) {
	if (index == N * N) {
		if (total > best_res) {
			best_res = total;
			return;
		}
	}
	else {
		int x = index / N;
		int y = index % N;
		if (judge(x, y) && maps[x][y] == '.') {
			maps[x][y] = 'E';
			DFS(index + 1, total + 1);
			maps[x][y] = '.';
		}
		DFS(index + 1, total);
	}
}

int main() 
{
	while (cin >> N && N) {
		char temp;
		for (int i = 0; i < N; i++) {
			vector<char> row;
			for (int j = 0; j < N; j++) {
				cin >> temp;
				row.push_back(temp);
			}
			maps.push_back(row);
		}
		DFS(0, 0);
		cout << best_res << endl;
		maps.clear();
		best_res = 0;
	}
	return 0;
}
