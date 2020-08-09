#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int y_w, y_h;

    for(int i=1; i<=yellow; i++){
        y_w = i;
        if(yellow % y_w == 0){
            y_h = yellow/y_w;
            if( brown == 2*y_h + 2*y_w + 4 ){
                answer.push_back(y_h+2);
                answer.push_back(y_w+2);
                break;
            }
        }
    }

    return answer;
}
