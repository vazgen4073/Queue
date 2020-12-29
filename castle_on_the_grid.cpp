#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
struct Coordinates {

    Coordinates(int x_, int y_, int steps_)
        : x(x_)
        , y(y_)
        , steps(steps_)
    {
    }

    int x, y, steps = 0;
};

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    int I = grid.size();
    int J = grid[0].size();
    vector<vector<bool>> visited(I, vector<bool>(J));
    queue<Coordinates> q;
    Coordinates p(startX, startY, 0);

    q.push(p);

    while (!q.empty()) {
        Coordinates cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int val = cur.steps + 1;

        while (++y < J && grid[x][y] != 'X') {

            if (!visited[x][y]) {
                visited[x][y] = 1;
                q.push(Coordinates(x, y, val));
            }
            if (x == goalX && y == goalY)
                return val;
        }
        y = cur.y;

        while (++x < I && grid[x][y] != 'X') {
            if (!visited[x][y]) {
                visited[x][y] = 1;
                q.push(Coordinates(x, y, val));
            }
            if (x == goalX && y == goalY)
                return val;
        }
        x = cur.x;

        while (--y >= 0 && grid[x][y] != 'X') {

            if (!visited[x][y]) {
                visited[x][y] = 1;
                q.push(Coordinates(x, y, val));
            }
            if (x == goalX && y == goalY)
                return val;
        }
        y = cur.y;

        while (--x >= 0 && grid[x][y] != 'X') {
            if (!visited[x][y]) {
                visited[x][y] = 1;
                q.push(Coordinates(x, y, val));
            }
            if (x == goalX && y == goalY)
                return val;
        }
    }

    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

