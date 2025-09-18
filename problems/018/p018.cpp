#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    auto startTime = chrono::high_resolution_clock::now();

    bool debug = false;

    string content = "3\n"
                     "7 4\n"
                     "2 4 6\n"
                     "8 5 9 3";

    content = "75\n"
              "95 64\n"
              "17 47 82\n"
              "18 35 87 10\n"
              "20 04 82 47 65\n"
              "19 01 23 75 03 34\n"
              "88 02 77 73 07 63 67\n"
              "99 65 04 28 06 16 70 92\n"
              "41 41 26 56 83 40 80 70 33\n"
              "41 48 72 33 47 32 37 16 94 29\n"
              "53 71 44 65 25 43 91 52 97 51 14\n"
              "70 11 33 28 77 73 17 78 39 68 17 57\n"
              "91 71 52 38 17 14 91 43 58 50 27 29 48\n"
              "63 66 04 68 89 53 67 30 73 16 69 87 40 31\n"
              "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

    int content_length = content.length();

    vector<vector<int>> tables;
    vector<int> row;

    int position[2] = {0, 0};
    string token = "";
    int digits = 0;
    int maxDigits = 0;
    for (int i = 0; i < content_length; i++)
    {
        char n = content[i];
        int code = static_cast<int>(n);

        if (code == 10)
        {
            // cout << "n: " << token << " p: " << position[0] << "-" << position[1] << endl;

            int temp = stoi(token);

            row.push_back(temp);

            tables.push_back(row);

            row.clear();

            if (digits > maxDigits)
            {
                maxDigits = digits;
            }
            digits = 0;

            token = "";
            position[0]++;
            position[1] = 0;
        }
        else if (code == 32)
        {
            // cout << "n: " << token << " p: " << position[0] << "-" << position[1] << endl;

            int temp = stoi(token);

            row.push_back(temp);

            if (digits > maxDigits)
            {
                maxDigits = digits;
            }
            digits = 0;

            token = "";
            position[1]++;
        }
        else if (code >= 48 || code <= 57)
        {
            digits++;
            token = token + n;
        }

        if (i == (content_length - 1) && !token.empty())
        {

            // cout << "n: " << token << " p: " << position[0] << "-" << position[1] << endl;

            int temp = stoi(token);

            row.push_back(temp);

            tables.push_back(row);

            row.clear();
        }

        // cout << n << " -> " << code << endl;
    }

    const int tableSize = tables.size();

    cout << "tableSize=" << tableSize << endl;

    cout << "maxDigits=" << maxDigits << endl;

    int maxValue = 10;
    for (int i = 1; i < maxDigits; i++)
    {
        maxValue *= 10;
    }
    maxValue -= 1;

    cout << "maxValue=" << maxValue << endl;

    // for (int i = 0; i < tableSize ; i++)
    // {

    //     vector<int> table_row = tables.at(i);

    //     for (int j = 0; j < table_row.size(); j++)
    //     {

    //         cout << "i=" << i << "j=" << j << "n=" << table_row.at(j) << endl;
    //     }
    // }

    vector<int> currentPath(tableSize, 0);

    // for(int i = 0; i < tableSize; i++){
    //     cout << i << "-" << currentPath.at(i) << endl;
    // }

    int pathsCount = 1;
    for (int i = 1; i < tableSize; i++)
    {
        int temp = pathsCount;
        pathsCount = temp + temp;
    }

    cout << "pathsCount=" << pathsCount << endl;

    int pathSumMax = 0;
    int pathSum = 0;

    int interactions = 0;

    vector<int> bestPath(tableSize, 0);
    vector<int> bestPathSumHistory(tableSize, 0);

    vector<int> currentPathHistory(tableSize, 0);
    vector<int> currentPathSumHistory(tableSize, 0);

    for (int j = 0; j < pathsCount; j++)
    {

        if (debug)
        {
            for (int i = 0; i < tableSize; i++)
            {
                cout << currentPath.at(i) << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < tableSize; i++)
        {
            interactions++;
            int n = tables.at(i).at(currentPath.at(i));

            currentPathHistory.at(i) = n;

            pathSum += n;

            currentPathSumHistory.at(i) = pathSum;

            int bestPathDiff = pathSum - bestPathSumHistory.at(i);

            int remainingDown = tableSize - i - 1;
            int possibleSum = pathSum;
            int possibleWin = 1;
            if (remainingDown > 0 && i > 0)
            {
                possibleSum = pathSum + (remainingDown * maxValue);
                if (possibleSum > pathSumMax)
                {
                    possibleWin = 1;
                }
                else
                {
                    possibleWin = 0;
                }
            }

            if (debug)
            {
                cout << n << "(" << pathSum << ")" << "(" << bestPathSumHistory.at(i) << ")" << "(" << bestPathDiff << ")" << "(" << pathSumMax << ")" << "(" << possibleSum << ")" << "(" << possibleWin << ") ";
            }

            if (possibleWin == 0 && true)
            {
                pathSum = 0;

                if (debug)
                {
                    cout << endl;
                }

                for (int z = tableSize - 1; z > 0; z--)
                {
                    int w = z - 1;

                    if (currentPath.at(z) == currentPath.at(w))
                    {
                        int temp = currentPath.at(z) + 1;
                        for (int y = z; y < tableSize; y++)
                        {
                            currentPath.at(y) = temp;
                        }
                        break;
                    }
                }
                break;
            }
        }

        if (pathSumMax < pathSum)
        {
            pathSumMax = pathSum;
            bestPath = currentPathHistory;
            bestPathSumHistory = currentPathSumHistory;
        }

        pathSum = 0;

        if (debug)
        {
            cout << endl;
        }

        for (int z = tableSize - 1; z > 0; z--)
        {
            int w = z - 1;

            if (currentPath.at(z) == currentPath.at(w))
            {
                int temp = currentPath.at(z) + 1;
                for (int y = z; y < tableSize; y++)
                {
                    currentPath.at(y) = temp;
                }
                break;
            }
        }
    }

    cout << "-----------------------------" << endl;
    cout << "pathSumMax=" << pathSumMax << endl;

    cout << "best path" << endl;

    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath.at(i) << " ";
    }
    cout << endl;

    cout << "best path sum history" << endl;

    for (int i = 0; i < bestPathSumHistory.size(); i++)
    {
        cout << bestPathSumHistory.at(i) << " ";
    }
    cout << endl;

    cout << "interactions=" << interactions << endl;

    auto endTime = chrono::high_resolution_clock::now();

    auto duration = endTime - startTime;

    auto durationMs = chrono::duration_cast<chrono::milliseconds>(duration).count();

    cout << durationMs << "ms" << endl;

    return 0;
}