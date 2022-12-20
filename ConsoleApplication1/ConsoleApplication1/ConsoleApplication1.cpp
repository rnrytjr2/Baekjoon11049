// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int N, x, y;
pair<int, int> matrixs[501];
long long DP[501][501];
long long sum[501];
long long Max = 1000000000;
int main()
{
	collection;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		matrixs[i] = (make_pair(x, y));
	}

	for (int i = 1; i < N; i++)
	{

		for (int j = 1; i + j <= N; j++)
		{
			DP[j][j + i] = Max;
			for (int k = j; k <= i + j; k++)
			{
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + matrixs[j].first * matrixs[k].second * matrixs[i + j].second);
			}
		}
	}
	cout << DP[1][N] << '\n';
}
