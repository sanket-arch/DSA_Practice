#include <iostream>
#include <string>
using namespace std;

int getvalue(char ch)
{
    int i = 1, v = 5, x = 10, l = 50, c = 100, d = 500, m = 1000;
    int sum = 0;
    switch (ch)
    {
    case 'I':
        return i;
    case 'V':
        return v;
    case 'X':
        return x;
    case 'L':
        return l;
    case 'C':
        return c;
    case 'D':
        return d;
    case 'M':
        return m;

    default:
        break;
    }
}
int romanToInt(string s)
{
    int nxt, sum = 0, count = 0;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (i != s.length()-1)
        {
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
            {
                nxt = -getvalue(s[i]);
                count++;
            }
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
            {
                nxt = -getvalue(s[i]);
                count++;
            }
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
            {
                nxt = -getvalue(s[i]);
                count++;
            }
        }
        if (count == 0)
        {
            nxt = getvalue(s[i]);
        }
        count = 0;
        sum += nxt;
    }
    return sum;
}

int main()
{
    string S = "MDCCXCIV";
    cout << romanToInt(S);
    return 0;
}