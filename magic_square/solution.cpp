#include <vector>
#include <iostream>
#include <limits>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
vector<vector<int> > all_magic_squares = {
            {8, 1, 6, 3, 5, 7, 4, 9, 2},
            {6, 1, 8, 7, 5, 3, 2, 9, 4},
            {4, 9, 2, 3, 5, 7, 8, 1, 6},
            {2, 9, 4, 7, 5, 3, 6, 1, 8},
            {8, 3, 4, 1, 5, 9, 6, 7, 2},
            {4, 3, 8, 9, 5, 1, 2, 7, 6},
            {6, 7, 2, 1, 5, 9, 8, 3, 4},
            {2, 7, 6, 9, 5, 1, 4, 3, 8}
    };
    vector<int> expanded;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j)
            expanded.push_back(s[i][j]);
    }
    int min_distance=100;
    for (int i=0;i<all_magic_squares.size();++i) {
        int cur_dist=0;
        for (int j=0;j<9;++j) {
            cur_dist+=abs(expanded[j]-all_magic_squares[i][j]);
        }
        if (cur_dist<min_distance)min_distance=cur_dist;
    }
    return min_distance;
}

int main()
{
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}

