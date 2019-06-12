#include <iostream>
#include <vector>
using namespace std;

// main 정의
int main() {
	int n, k;
	int temp; // 배열 입력받을때 사용할 변수
	cin >> n >> k;
	vector<int> ary; // 배열이 들어갈 자리

	//배열 벡터 a 생성
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ary.push_back(temp);
	}

	// 테이블 만들기
	int** subset = new int*[n];
	for (int i = 0; i < n; ++i)
		subset[i] = new int[n] {0}; // n by n 이차원배열 생성

	// 테이블 채우기 : subset[i][j]은 a[i]부터 a[j]까지의 합을 구함
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) { //배열의 오른쪽 상단부분만 사용
			if (i == j)
				subset[i][j] = ary[i]; // 대각성분 채우기
			else
				subset[i][j] = subset[i][j - 1] + ary[j]; //DP
		}
	}

	// 최대값 찾기
	int maxnb = subset[0][0];
	for (int i = 0; i <= n - k; i++) {
		for (int j = k - 1; i + j < n; j++) { // 테이블에서 검색할때 k의 값 활용하여 순회 최소한으로
			if (maxnb < subset[i][i + j])
				maxnb = subset[i][i + j];
		}
	}
	//만약 음수가 나오면 아무것도 더하지 않고 0이라는 값을 냄
	if (maxnb < 0)
		maxnb = 0;
	// 최대값 출력
	cout << endl << maxnb << endl;

	//동적할당받은 공간 삭제
	delete[] subset;

	return 0;
}