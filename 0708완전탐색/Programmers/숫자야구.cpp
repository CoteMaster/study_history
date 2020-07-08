#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int strike = 0;
    int ball = 0;
    string num = "";
    string qnum = "";

    for (int i = 123; i <= 987; i++) {
        num = to_string(i);
        if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) continue;
        else if (num[0] == '0' || num[1] == '0' || num[2] == '0') continue;

        bool flag = true;
        for (int j = 0; j < baseball.size(); j++) {
            qnum = to_string(baseball[j][0]);
            strike = 0; ball = 0;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    if (a == b && num[a] == qnum[b]) strike++;
                    else if (a != b && num[a] == qnum[b]) ball++;
                }
            }
            if (strike != baseball[j][1] || ball != baseball[j][2]) flag = false;
        }
        if (flag == true) answer++;
    }
    return answer;
}