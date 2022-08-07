#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> m;
    int x;
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        m[i] = x;
    }
    for (auto &it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}