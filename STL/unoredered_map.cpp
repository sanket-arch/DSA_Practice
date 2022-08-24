#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    //everthing in inordered map is same as ordered map, the main doffernce is it will return value not in ordered.
    // Time complexity of every function is O(1);
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