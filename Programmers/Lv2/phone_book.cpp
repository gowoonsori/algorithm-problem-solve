#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for(int i = 0; i < phone_book.size()-1 ; i++){
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].size())) return false;
    }
    return answer;
}
int main(){
    vector<string> phone_book= {"119","11","14","15","97", "97674223", "1195524421"};
    cout << solution(phone_book);
}