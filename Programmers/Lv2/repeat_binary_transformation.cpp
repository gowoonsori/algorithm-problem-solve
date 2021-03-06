#include <bits/stdc++.h>

using namespace std;

vector<string> input_func();
vector<int> solution(string s);

int main() {
    string s = "";
    for (int i = 0; i < 150000; i++) {
        s += "1";
    }
    solution(s);
}

vector<string> input_func() {
    vector<string> input;

    string str, item;
    cin >> str;

    return input;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s != "1") {
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                str += s[i];
            } else {
                answer[1]++;
            }
        }

        bitset<150000> bit(str.length());
        s = to_string(stoll(bit.to_string()));

        // //시간복잡도 효율적인 코드
        // s.clear();
        // for(int i=str.length(); i > 0; i/=2){
        //     s.push_back(i%2 + '0');
        // }

        answer[0]++;
    }
    cout << answer[0] << " " << answer[1];
    return answer;
}