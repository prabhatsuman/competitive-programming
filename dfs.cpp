#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
void dfs(vector<vector<int>> &image, int i, int j, int color, int newColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != color)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image, i + 1, j, color, newColor);
    dfs(image, i - 1, j, color, newColor);
    dfs(image, i, j + 1, color, newColor);
    dfs(image, i, j - 1, color, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
    {
        return image;
    }
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}
void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    int res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
