#include <iostream>
#include<map>
using namespace std;

int main()
{
	while (1) {
		// n, k ���� ���� �� �Է� �ޱ�
		int n, k;
		cin >> n >> k;
		// ������ ���� �迭�� ���ڿ� �󵵸� ������ map
		int *list = new int[n];
		map<int, int> m;

		//�����迭 �Է¹ޱ�
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
		}

		//�迭 �о� map ����
		for (auto i = 0; i < n; i++)
		{
			if (!m.count(list[i])) //�迭�� ���� ���� map�� ������
				m.insert(make_pair(list[i], 1)); //�迭 ���� �󵵼�1�� pair�� ���� ������ insert
			else { //�迭�� ���� ���� map�� ������
				int count = m[list[i]]; //������ �󵵼��� �޾�
				count++; // �ѹ� ���� ��
				m[list[i]] = count; //map�� �ش� pair�� value update
			}
		}

		// k�� �̻� ������ �� �߿��� �ּ��� �� ã��
		int findNumber = -1; // �� ã���� -1
		map<int, int>::iterator iter; //map�� ���� �ݺ���
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (findNumber == -1) // ���� k�̻��� ã�� ��������
				if (iter->second >= k)
					findNumber = iter->first; //ã���� �ٷ� ����
			else if (findNumber != -1) // k�̻��̾ �����س��� ���� ������
				if (iter->second >= k && iter->first < findNumber) // map�� �Ǵٸ� k�̻��� ���� �ְ� �� ���� ���� findNumber���� ������ ����
					findNumber = iter->first; 
		}
		cout << findNumber << endl;
		delete[] list;
	}
	return 0;
}