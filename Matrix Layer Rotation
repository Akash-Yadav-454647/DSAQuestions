#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int layers = min(m, n) / 2;

    for (int layer = 0; layer < layers; layer++) {
        vector<int> elements;

        int rowStart = layer;
        int rowEnd = m - 1 - layer;
        int colStart = layer;
        int colEnd = n - 1 - layer;

        // Top edge
        for (int j = colStart; j <= colEnd; j++)
            elements.push_back(matrix[rowStart][j]);

        // Right edge
        for (int i = rowStart + 1; i <= rowEnd - 1; i++)
            elements.push_back(matrix[i][colEnd]);

        // Bottom edge
        for (int j = colEnd; j >= colStart; j--)
            elements.push_back(matrix[rowEnd][j]);

        // Left edge
        for (int i = rowEnd - 1; i >= rowStart + 1; i--)
            elements.push_back(matrix[i][colStart]);

        int len = elements.size();
        int rot = r % len;

        vector<int> rotated(len);
        for (int i = 0; i < len; i++)
            rotated[i] = elements[(i + rot) % len];

        // Put back rotated values
        int idx = 0;

        // Top edge
        for (int j = colStart; j <= colEnd; j++)
            matrix[rowStart][j] = rotated[idx++];

        // Right edge
        for (int i = rowStart + 1; i <= rowEnd - 1; i++)
            matrix[i][colEnd] = rotated[idx++];

        // Bottom edge
        for (int j = colEnd; j >= colStart; j--)
            matrix[rowEnd][j] = rotated[idx++];

        // Left edge
        for (int i = rowEnd - 1; i >= rowStart + 1; i--)
            matrix[i][colStart] = rotated[idx++];
    }

    // Print final matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
