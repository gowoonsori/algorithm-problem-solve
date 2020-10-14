#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int M_x, M_y;
int D_x, D_y;
bool arrive = false;
vector<vector<char>> answer;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>> map, vector<vector<bool>> &visit, int x, int y)
{
    if (y == D_y && x == D_x)
    {
        arrive = true;
        answer = map;
        return;
    }
    if (map[y][x] != 'M')
        map[y][x] = 'x';
    visit[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int next_x = (x + dir[i][0] + C) % C;
        int next_y = (y + dir[i][1] + R) % R;

        if ((map[next_y][next_x] == '.' || map[next_y][next_x] == 'D') && visit[next_y][next_x] == false)
        {
            visit[next_y][next_x] == true;
            dfs(map, visit, next_x, next_y);
        }
    }
    return;
}

int main()
{
    cin >> R >> C;
    vector<vector<char>> arr(R, vector<char>(C, '0'));
    vector<vector<bool>> visit(R, vector<bool>(C, false));
    string str;

    for (int i = 0; i < R; i++)
    {
        int j = 0;
        cin >> str;
        for (auto c : str)
        {
            arr[i][j] = c;
            if (arr[i][j] == 'M')
            {
                M_x = j;
                M_y = i;
            }
            if (arr[i][j] == 'D')
            {
                D_x = j;
                D_y = i;
            }
            j++;
        }
    }

    dfs(arr, visit, M_x, M_y);
    if (arrive)
    {
        cout << "YES" << endl;
        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = 0; j < answer[i].size(); j++)
            {
                cout << answer[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
