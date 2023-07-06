#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string king_pos;
    cin >> king_pos;
    int row_k, col_k;
    col_k = (king_pos[0] - 'a') + 1;
    row_k = (king_pos[1] - '0');
    string final_pos;
    cin >> final_pos;
    int col_f = (final_pos[0] - 'a') + 1;
    int row_f = (final_pos[1] - '0');
    vector<string> res;
    string temp = "";
    int count = 0;
    while (((row_k != row_f) && (col_k != col_f))||((row_k != row_f) && (col_k == col_f))||((row_k == row_f) && (col_k != col_f)))
    {
        if (row_k == row_f)
        {
            if (col_k > col_f)
            {
                temp = "L";
                res.push_back(temp);
                col_k--;
                count++;
            }
            else
            {
                temp = "R";
                res.push_back(temp);
                col_k++;
                count++;
            }
        }
        else if (col_k == col_f)
        {
            if (row_k > row_f)
            {
                temp = "D";
                res.push_back(temp);
                row_k--;
                count++;
            }
            else
            {
                temp = "U";
                res.push_back(temp);
                row_k++;
                count++;
            }
        }
        else
        {
            if ((row_k > row_f) && (col_k > col_f))
            {
                temp = "LD";
                res.push_back(temp);
                row_k--;
                col_k--;
                count++;
            }
            else if ((row_k > row_f) && (col_k < col_f))
            {
                temp = "RD";
                res.push_back(temp);
                row_k--;
                col_k++;
                count++;
            }
            else if ((row_k < row_f) && (col_k < col_f))
            {
                temp = "RU";
                res.push_back(temp);
                row_k++;
                col_k++;
                count++;
            }
            else 
            {
                temp = "LU";
                res.push_back(temp);
                row_k++;
                col_k--;
                count++;
            }
        }
    }
    cout<<count<<'\n';
    for(auto it = res.begin(); it!=res.end();it++)
    {
        cout<<*it<<'\n';
    }
    return 0;
}
