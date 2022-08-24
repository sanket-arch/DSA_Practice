#include <iostream>
using namespace std;
class element
{
public:
    int i;
    int j;
    int k;
};
class sparseMatrix
{
    int m, n, num;
    element *ele;

public:
    sparseMatrix(int M, int N, int Num)
    {
        m = M;
        n = N;
        num = Num;
        ele = new element[num];
    }
    ~sparseMatrix()
    {
        delete[] ele;
    }
    void read();
    void display();
    friend sparseMatrix add(sparseMatrix s1, sparseMatrix s2);
};
void sparseMatrix::read()
{
    cout << "enter elements";
    for (int i = 0; i < n; i++)
    {
        cin >> ele[i].i >> ele[i].j >> ele[i].k;
    }
}

void sparseMatrix::display()
{
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ele[k].i == i && ele[k].j == j)
            {
                cout << ele[k++].k << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
sparseMatrix add(sparseMatrix s1, sparseMatrix s2) // this function is not working and i unable to fix it now, so try it later.
{
    int num = s1.num + s2.num;
    int m = s1.m, n = s1.n;
    sparseMatrix s3(m, n, num);
    int i = 0, j = 0, count = 0;
    while (i < m && j < m)
    {
        if (s1.ele[i].i == s2.ele[i].i && s1.ele[i].j == s2.ele[i].j)
        {
            s3.ele[count].i = s1.ele[i].i;
            s3.ele[count].j == s1.ele[i].j;
            s3.ele[count++].k == s1.ele[i].k + s2.ele[i].k;
            i++;
            j++;
        }
        else if ((s1.ele[i].i < s2.ele[i].i) || (s1.ele[i].i == s2.ele[i].i && s1.ele[i].j < s2.ele[i].j))
        {
            s3.ele[count].i = s1.ele[i].i;
            s3.ele[count].j == s1.ele[i].j;
            s3.ele[count++].k == s1.ele[i].k;
            i++;
        }
        else
        {
            s3.ele[count].i = s2.ele[j].i;
            s3.ele[count].j == s2.ele[j].j;
            s3.ele[count++].k == s2.ele[j].k;
            j++;
        }
    }
    return s3;
}
int main()
{
    sparseMatrix s1(5, 5, 5), s2(5, 5, 5);
    s1.read();
    s2.read();
    s1.display();
    return 0;
}
