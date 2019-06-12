#include <iostream>
#include<map>
using namespace std;

int main()
{
	while (1) {
		// n, k 변수 선언 후 입력 받기
		int n, k;
		cin >> n >> k;
		// 정수를 받을 배열과 숫자와 빈도를 저장할 map
		int *list = new int[n];
		map<int, int> m;

		//정수배열 입력받기
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
		}

		//배열 읽어 map 생성
		for (auto i = 0; i < n; i++)
		{
			if (!m.count(list[i])) //배열을 읽은 값이 map에 없으면
				m.insert(make_pair(list[i], 1)); //배열 값과 빈도수1을 pair로 새로 생성해 insert
			else { //배열을 읽은 값이 map에 있으면
				int count = m[list[i]]; //기존의 빈도수를 받아
				count++; // 한번 더한 후
				m[list[i]] = count; //map의 해당 pair의 value update
			}
		}

		// k번 이상 나오는 수 중에서 최소인 값 찾기
		int findNumber = -1; // 못 찾으면 -1
		map<int, int>::iterator iter; //map을 읽을 반복자
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (findNumber == -1) // 아직 k이상을 찾지 못했을때
				if (iter->second >= k)
					findNumber = iter->first; //찾으면 바로 저장
			else if (findNumber != -1) // k이상이어서 저장해놓은 값이 있을때
				if (iter->second >= k && iter->first < findNumber) // map에 또다른 k이상인 값이 있고 그 값이 기존 findNumber보다 작으면 저장
					findNumber = iter->first; 
		}
		cout << findNumber << endl;
		delete[] list;
	}
	return 0;
}