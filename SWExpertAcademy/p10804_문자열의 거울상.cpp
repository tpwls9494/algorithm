#include <iostream>

using namespace std;
char var[1001];

int main(int argc, char** argv)
{
    char reverse[1001];
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> var;
        //int size = strlen(var);
        int size;
        for (size = 0; size < 1001; size++) {
            if (var[size] == '\0') break;
        }
        for (int i = 0; i < size; i++) {
            reverse[i] = var[size - i - 1];
            if (reverse[i] == 'b') reverse[i] = 'd';
            else if (reverse[i] == 'd') reverse[i] = 'b';
            else if (reverse[i] == 'p') reverse[i] = 'q';
            else if (reverse[i] == 'q') reverse[i] = 'p';
            else
                continue;
        }
        cout << '#' << test_case << ' ';
        for (int i = 0; i < size; i++) cout << reverse[i];
        cout << '\n';
    }
    return 0;
}