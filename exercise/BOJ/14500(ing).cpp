#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 550;
const int LEFT = 6;
int N, M, hei, wid, bn, sn, ans, board[MAX][MAX];
int tboard[MAX][MAX];

void turn() {


	for (int j = 0; j < hei + LEFT; j++) {
		for (int k = 0; k < wid + LEFT; k++) {
			tboard[k][j] = board[j][wid + LEFT - 1 - k];
		}
	}

	int tmp = hei;
	hei = wid;
	wid = tmp;

	for (int i = 0; i < hei + LEFT; i++)
		for (int j = 0; j < wid + LEFT; j++)
			board[i][j] = tboard[i][j];

}

void rev() {

	for (int i = 0; i < hei + LEFT; i++) {
		for (int j = 0; j < wid + LEFT; j++) {
			tboard[i][j] = board[i][bn + LEFT - 1 - j];
		}
	}

	for (int i = 0; i < hei + LEFT; i++)
		for (int j = 0; j < wid + LEFT; j++)
			board[i][j] = tboard[i][j];
}

void print() {
	for (int i = 0; i < bn + LEFT; i++) {
		for (int j = 0; j < bn + LEFT; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
}


int main() {
	bool tetro[5][4][4] =
	{ {
		{1, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	  },
	  {
		{1, 1, 0, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	  },
	  {
		{1, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0}
	  },
	  {
		{1, 0, 0, 0},
		{1, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 0, 0}
	  },
	  {
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	  } };

	scanf("%d%d", &N, &M);
	bn = (N > M) ? N : M;
	sn = (N <= M) ? N : M;

	for (int i = 3; i < 3 + N; i++) {
		for (int j = 3; j < 3 + M; j++) {
			scanf("%d", &board[i][j]);
		}
	}


	for (int t = 0; t < 4; t++) {
		for (int r = 0; r < 2; r++) {
			for (int k = 0; k < 5; k++) {
				for (int i = 0; i < hei + 6; i++) {
					for (int j = 0; j < wid + 6; j++) {
						int tmp = 0;
						int cnt = 0;
						for (int yy = 0; yy < 4; yy++) {
							for (int xx = 0; xx < 4; xx++) {
								if (tetro[k][yy][xx] && board[i + yy][j + xx]) {
									cnt++;
									tmp += board[i + yy][j + xx];
								}
							}
						}
						if (cnt == 4)
							ans = max(ans, tmp);
					}
				}
			}
			rev();
			printf("reverse ! \n");
			print();
		}
		printf("turn ! \n");
		turn();
		print();
	}

	printf("%d\n", ans);
}