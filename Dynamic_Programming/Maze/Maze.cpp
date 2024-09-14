#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution, vector<vector<vector<int>>>& allSolutions) {
    int rows = maze.size();
    int cols = maze[0].size();

    if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == 0 || solution[x][y] == 1) {
        return;
    }

    // 如果到达右下角，则保存解决方案并返回
    if (x == rows - 1 && y == cols - 1) {
        solution[x][y] = 1;
        allSolutions.push_back(solution);
        solution[x][y] = 0;
        return;
    }

    // 标记当前单元格为1，表示这个单元格是路径的一部分
    solution[x][y] = 1;

    // 向四个方向尝试
    dfsMaze(maze, x - 1, y, solution, allSolutions); // 上
    dfsMaze(maze, x + 1, y, solution, allSolutions); // 下
    dfsMaze(maze, x, y - 1, solution, allSolutions); // 左
    dfsMaze(maze, x, y + 1, solution, allSolutions); // 右

    // 回溯，取消标记当前单元格
    solution[x][y] = 0;
}

// 使用动态规划计算路径总数的函数：
int countPathsInMazeDP(vector<vector<int>>& maze) {
    if (maze.empty() || maze[0].empty() || maze[0][0] == 0) return 0;

    int rows = maze.size();
    int cols = maze[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // 初始化起点
    dp[0][0] = 1;

    // 初始化第一行和第一列
    for (int i = 1; i < rows; ++i) {
        if (maze[i][0] == 1) dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < cols; ++j) {
        if (maze[0][j] == 1) dp[0][j] = dp[0][j - 1];
    }

    // 计算到达每个单元格的路径数
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (maze[i][j] == 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    // 返回到达终点的路径数
    return dp[rows - 1][cols - 1];
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    vector<vector<vector<int>>> allSolutions;
    vector<vector<int>> solution(maze.size(), vector<int>(maze[0].size(), 0));

    dfsMaze(maze, 0, 0, solution, allSolutions);

    cout << "Number of paths in the maze (DP): " << countPathsInMazeDP(maze) << endl;
    cout << "All paths in the maze (DFS):" << endl;
    for (const auto& sol : allSolutions) {
        for (const auto& row : sol) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
