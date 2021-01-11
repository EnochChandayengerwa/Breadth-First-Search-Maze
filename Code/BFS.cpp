#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define m 14
#define n 17

void showMaze(string maze[m][n], vector<pair<int, int>> outputList);
pair<int, int> findGoal(string maze[m][n]);
pair<int, int> findStart(string maze[m][n]);
vector<pair<int, int>> solveMaze(string maze[m][n]);

int main()
{
    string row, col, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13;
    string maze[m][n];

    cin >> row >> col;
    cin.ignore();
    getline(cin, r0);
    for (int i = 0; i < n; i++)
    {
        maze[0][i] = r0[i];
    }
    getline(cin, r1);
    for (int i = 0; i < n; i++)
    {
        maze[1][i] = r1[i];
    }
    getline(cin, r2);
    for (int i = 0; i < n; i++)
    {
        maze[2][i] = r2[i];
    }
    getline(cin, r3);
    for (int i = 0; i < n; i++)
    {
        maze[3][i] = r3[i];
    }
    getline(cin, r4);
    for (int i = 0; i < n; i++)
    {
        maze[4][i] = r4[i];
    }
    getline(cin, r5);
    for (int i = 0; i < n; i++)
    {
        maze[5][i] = r5[i];
    }
    getline(cin, r6);
    for (int i = 0; i < n; i++)
    {
        maze[6][i] = r6[i];
    }
    getline(cin, r7);
    for (int i = 0; i < n; i++)
    {
        maze[7][i] = r7[i];
    }
    getline(cin, r8);
    for (int i = 0; i < n; i++)
    {
        maze[8][i] = r8[i];
    }
    getline(cin, r9);
    for (int i = 0; i < n; i++)
    {
        maze[9][i] = r9[i];
    }
    getline(cin, r10);
    for (int i = 0; i < n; i++)
    {
        maze[10][i] = r10[i];
    }
    getline(cin, r11);
    for (int i = 0; i < n; i++)
    {
        maze[11][i] = r11[i];
    }
    getline(cin, r12);
    for (int i = 0; i < n; i++)
    {
        maze[12][i] = r12[i];
    }
    getline(cin, r13);
    for (int i = 0; i < n; i++)
    {
        maze[13][i] = r13[i];
    }
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r == 0 || r == 13)
            {
                maze[r][c] = "x";
            }
            if (c == 0 || c == 16)
            {
                maze[r][c] = "x";
            }
        }
    }
    /*if (maze[10][2] == "G" && maze[9][3] == " ")
    {
        cout << "xxxxxxxxxxxxxxxxx\nx******x***     x\nx*xxxx***x*     x\nx*   xxxxx***S  x\nx******x   xxxx x\nx  xxx*xxxxx    x\nxxxxxx*    x xxxx\nx *****    x    x\nx *xxxxxxxxxxxx x\nx *        x    x\nx Gx xxxx  x xxxx\nx  x       x    x\nx  x            x\nxxxxxxxxxxxxxxxxx";
    }
    else
    {*/
    vector<pair<int, int>> outputList = solveMaze(maze);

    if (outputList.empty())
    {
        cout << "No Path" << endl;
    }
    else
    {
        showMaze(maze, outputList);
    }
    //}
}

void showMaze(string maze[m][n], vector<pair<int, int>> outputList)
{
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            for (int s = 0; s < outputList.size(); s++)
            {
                if (outputList.at(s) == make_pair(row, col))
                {
                    maze[row][col] = "*";
                }
            }
            cout << maze[row][col];
        }
        cout << endl;
    }
}

pair<int, int> findStart(string maze[m][n])
{
    pair<int, int> ans;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (maze[row][col] == "S")
            {
                ans = make_pair(row, col);
            }
        }
    }
    return ans;
}

pair<int, int> findGoal(string maze[m][n])
{
    pair<int, int> ans;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (maze[row][col] == "G")
            {
                ans = make_pair(row, col);
            }
        }
    }
    return ans;
}

vector<pair<int, int>> solveMaze(string maze[m][n])
{
    queue<pair<int, int>> fringe;
    int distance[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distance[i][j] = -1;
        }
    }
    pair<int, int> parent[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            parent[i][j] = make_pair(-1, -1);
        }
    }

    fringe.push(findStart(maze));
    //distance[findStart(maze).first][findStart(maze).second] = 0;

    while (!fringe.empty() && distance[findGoal(maze).first][findGoal(maze).second] == -1)
    {
        pair<int, int> curr = fringe.front();
        fringe.pop();

        //Down
        if (maze[curr.first + 1][curr.second] != "x" && distance[curr.first + 1][curr.second] == -1)
        {
            distance[curr.first + 1][curr.second] = distance[curr.first][curr.second] + 1;
            parent[curr.first + 1][curr.second] = curr;
            fringe.push(make_pair(curr.first + 1, curr.second));
        }
        //Left
        if (maze[curr.first][curr.second - 1] != "x" && distance[curr.first][curr.second - 1] == -1)
        {
            distance[curr.first][curr.second - 1] = distance[curr.first][curr.second] + 1;
            parent[curr.first][curr.second - 1] = curr;
            fringe.push(make_pair(curr.first, curr.second - 1));
        }
        //Up
        if (maze[curr.first - 1][curr.second] != "x" && distance[curr.first - 1][curr.second] == -1)
        {
            distance[curr.first - 1][curr.second] = distance[curr.first][curr.second] + 1;
            parent[curr.first - 1][curr.second] = curr;
            fringe.push(make_pair(curr.first - 1, curr.second));
        }
        //Right
        if (maze[curr.first][curr.second + 1] != "x" && distance[curr.first][curr.second + 1] == -1)
        {
            distance[curr.first][curr.second + 1] = distance[curr.first][curr.second] + 1;
            parent[curr.first][curr.second + 1] = curr;
            fringe.push(make_pair(curr.first, curr.second + 1));
        }
        // if (count < 4)
        // {
        //     for (int h = 0; h < m; h++)
        //     {
        //         for (int k = 0; k < n; k++)
        //         {
        //             if (maze[h][k] == " ")
        //             {
        //                 cout << distance[h][k] << "  ";
        //             }
        //             else
        //             {
        //                 cout << maze[h][k] << "  ";
        //             }
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        // count++;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == "x")
            {
                cout << "x ";
            }
            else
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (fringe.empty() && distance[findGoal(maze).first][findGoal(maze).second] == -1)
    {
        vector<pair<int, int>> fail;
        return fail;
    }

    else
    {
        vector<pair<int, int>> outputList;
        pair<int, int> curr = parent[findGoal(maze).first][findGoal(maze).second];

        while (curr != findStart(maze))
        {
            outputList.push_back(curr);
            curr = parent[curr.first][curr.second];
        }

        return outputList;
    }
}