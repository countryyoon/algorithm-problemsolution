#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include<string>
using namespace std;

// pair에서 second 기준 오름차순 정렬
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

// 좌표에서 원점과 이은 점과 수평선을 기준으로한 각으로 오름차순 정렬
bool cmpg(const pair<int, int> &a, const pair<int, int> &b) {	
	return atan2(a.second, a.first) < atan2(b.second, b.first);
}

// 다각형 내부 외부 판별 (반직선 사용)
bool isInside(const pair<int, int> &p, const vector<pair<int, int>> &ch) {
	int crosscnt = 0;
	int lench = ch.size();
	for (int i = 0; i < lench; i++) {
		int j = (i + 1) % ch.size();
		if ((ch[i].second > p.second) != (ch[j].second > p.second)) {
			double cdot = (ch[j].first - ch[i].first)*(p.second - ch[i].second) / (ch[j].second - ch[i].second) + ch[i].first;
			if (p.first < cdot)
				crosscnt++;
		}
	}
	return crosscnt % 2 > 0;
}

// 시계방향 판별 (외적 사용하기)
int ccw(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
	int temp = a.first*b.second + b.first*c.second + c.first*a.second;
	temp = temp - a.second*b.first - b.second*c.first - c.second*a.first;
	if (temp > 0)
		return 1; //반시계
	else if (temp < 0)
		return -1; //시계
	else
		return 0; //일직선
}


int main() {

	// 보석과 cctv 개수 받기
	int n, m;
	cin >> n >> m;

	// 저장할 변수 선언
	pair<int, int> dot;
	vector<pair<int, int>> jewel;
	vector<pair<int, int>> cam;

	// 보석의 좌표 받기
	for (int i = 0; i < n; i++) {
		cin >> dot.first >> dot.second;
		jewel.push_back(dot);
	}
	// cctv의 좌표 받기
	for (int j = 0; j < m; j++) {
		cin >> dot.first >> dot.second;
		cam.push_back(dot);
	}
	
	// y좌표 기준 정렬
	sort(cam.begin(), cam.end(), cmp);
	pair<int, int> std = cam[0]; // 최저점을 기준으로 설정함

	vector<pair<int, int>> cam_re; // 최저점과 이루는 점을 계산하기 위해 상대적 좌표를 저장할 배열

	// 기준점을 원점으로 상대적 좌표 설정하여 cam_re에 넣기
	for (int i = 0; i < m - 1; i++) {
		dot.first = cam[i+1].first - cam[0].first;
		dot.second = cam[i+1].second - cam[0].second;
		cam_re.push_back(dot);
	}
	//각 기준 정렬
	sort(cam_re.begin(), cam_re.end(), cmpg);
	// 상대적 좌표를 원좌표로 복원
	for (int i = 0; i < m - 1; i++) {
		cam[i+1].first = cam_re[i].first + cam[0].first;
		cam[i+1].second = cam_re[i].second + cam[0].second;
	}
	
	// 컨벡스헐 생성
	vector<pair<int, int>> hull;
	hull.push_back(cam[0]);
	hull.push_back(cam[1]);
	int next = 2;
	while (next < m) {
		int ccwnb = ccw(cam[next - 2], cam[next - 1], cam[next]);
		if (ccwnb >= 0) {
			hull.push_back(cam[next]);
		}
		else if (ccwnb < 0) {
			hull.pop_back();
			hull.push_back(cam[next]);
		}
		next++;
	}

	cout << endl;
	for (auto a : hull) {
		cout << a.first << " " << a.second << endl;
	}

	vector<string> yn; //결과 넣을 함수
	// 내부 외부 판별
	for (int i = 0; i < n; i++) {
		string judge;
		if (isInside(jewel[i], hull))
			judge = "Y";
		else
			judge = "N";
		yn.push_back(judge);
	}

	// 결과출력
	cout << endl;
	for (auto a:yn) {
		cout << a;
	}

	return 0;
}
