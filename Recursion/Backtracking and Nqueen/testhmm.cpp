#include <bits/stdc++.h>
using namespace std;

const int N = 0;

int isSafe(int x, int y, int board[10][10],int n)
{
	return (x >= 0 && x < n && y >= 0 && y < n
			&& board[x][y] == -1);
}

bool knightTour(int board[10][10], int x, int y, int count, int *xmove, int *ymove, int n) {
	if (count == n*n ) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	for (int k = 0; k < 8; k++) {
		int nextx = x + xmove[k];
		int nexty = y + ymove[k];
		if (nextx<n && nexty<n && nextx>=0 && nexty>=0 && board[nextx][nexty]==(-1)) {
			board[nextx][nexty] = count;
			if (knightTour(board, nextx, nexty, count + 1, xmove, ymove, n)) {
				return true;
			}
			else
			board[nextx][nexty] = -1;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int board[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = -1;
		} 
	}
    
	board[0][0] = 0;
	int xmove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	knightTour(board, 0, 0, 1, xmove, ymove, n);
	return 0;
}