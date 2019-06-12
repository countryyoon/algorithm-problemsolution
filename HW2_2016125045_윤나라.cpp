#include <iostream>
#include <vector>
using namespace std;

// main ����
int main() {
	int n, k;
	int temp; // �迭 �Է¹����� ����� ����
	cin >> n >> k;
	vector<int> ary; // �迭�� �� �ڸ�

	//�迭 ���� a ����
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ary.push_back(temp);
	}

	// ���̺� �����
	int** subset = new int*[n];
	for (int i = 0; i < n; ++i)
		subset[i] = new int[n] {0}; // n by n �������迭 ����

	// ���̺� ä��� : subset[i][j]�� a[i]���� a[j]������ ���� ����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) { //�迭�� ������ ��ܺκи� ���
			if (i == j)
				subset[i][j] = ary[i]; // �밢���� ä���
			else
				subset[i][j] = subset[i][j - 1] + ary[j]; //DP
		}
	}

	// �ִ밪 ã��
	int maxnb = subset[0][0];
	for (int i = 0; i <= n - k; i++) {
		for (int j = k - 1; i + j < n; j++) { // ���̺��� �˻��Ҷ� k�� �� Ȱ���Ͽ� ��ȸ �ּ�������
			if (maxnb < subset[i][i + j])
				maxnb = subset[i][i + j];
		}
	}
	//���� ������ ������ �ƹ��͵� ������ �ʰ� 0�̶�� ���� ��
	if (maxnb < 0)
		maxnb = 0;
	// �ִ밪 ���
	cout << endl << maxnb << endl;

	//�����Ҵ���� ���� ����
	delete[] subset;

	return 0;
}