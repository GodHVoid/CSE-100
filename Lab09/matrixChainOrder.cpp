#include <iostream>
#include <climits>

using namespace std;

void parenthesization(int i, int j, int n, int *s, int &name)
{
    if (i == j)
    {
        cout << "A" << name++;
        return;
    }
    cout << "(";
    parenthesization(i, *((s + i * n) + j), n, s, name);
    parenthesization(*((s + i * n) + j) + 1, j, n, s, name);
	cout << ")";

}

void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int s[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    int name = 0;
    cout << m[1][n - 1] << endl;
    parenthesization(1, n - 1, n, (int *)s, name);
    cout << endl;

}

int main()
{
    int n;
    cin >> n;
    int *p = new int[n+1];
    for (int i = 0; i <=n; i++)
    {
        cin >> p[i];
    }
    matrixChainOrder(p,n + 1);
    return 0;

}
