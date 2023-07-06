#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> n1(n);
        vector<int> n2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> n1[i];
            n2[i] = n1[i];
        }
        vector<int> odd1;
        vector<int> odd2;
        vector<pair<int, int>> res1;
        vector<pair<int, int>> res2;
        int count1 = 0, count2 = 0;
        int it1 = -1, it2 = -1;
        int temp1 = -1, temp2 = -1;

        int l = 0;
        for (int i = 0; i < n; i++)
        {
            if (n1[i] & 1 == 1)
            {
                odd1.push_back(i);
                odd2.push_back(i);
                if (odd1.size() == 2)
                {
                    break;
                }
            }
        }
        if (odd1.size() == 0)
        {
            cout << "-1" << '\n';
        }
        else if (odd1[0] == 0 && odd1.size() == 1)
        {

            temp1 = n1[0] % 2;
            for (int i = 1; i < n; i++)
            {
                if (temp1 == n1[i] % 2)
                {
                    it1 = odd1[0];
                    n1[i] ^= n1[it1];
                    count1++;
                    res1.push_back(make_pair(i + 1, it1 + 1));
                    temp1 = n1[i] % 2;
                }
                else
                {
                    temp1 = n1[i] % 2;
                }
            }
            cout << count1 << '\n';
            for (auto &i : res1)
            {
                cout << i.first << " " << i.second << '\n';
            }
        }
        else
        {

            while (l < 2)
            {
                if (l == 0)
                {
                    // 1st even
                    // changing 1st element
                    if (n1[0] % 2 == 0)
                    {

                        it1 = odd1[0];
                        n1[0] ^= n1[it1];
                        count1++;
                        odd1[0] = 0;
                        res1.push_back(make_pair(1, it1 + 1));
                        temp1 = n1[0] % 2;
                        for (int i = 1; i < n; i++)
                        {
                            if (temp1 == n1[i] % 2)
                            {
                                it1 = odd1[0];
                                n1[i] ^= n1[it1];
                                count1++;
                                res1.push_back(make_pair(i + 1, it1 + 1));
                                temp1 = n1[i] % 2;
                            }
                            else
                            {
                                temp1 = n1[i] % 2;
                            }
                        }
                    }
                    else
                    {
                        it1 = odd1[1];
                        n1[0] ^= n1[it1];
                        count1++;
                        res1.push_back(make_pair(1, it1 + 1));

                        if (n1[1] % 2 == 0)
                        {
                            n1[1] ^= n1[it1];
                            count1++;
                            res1.push_back(make_pair(2, it1 + 1));
                            odd1[0] = 1;
                        }
                        else
                        {
                            odd1[0] = 1;
                        }
                        temp1 = n1[1] % 2;
                        for (int i = 2; i < n; i++)
                        {
                            if (temp1 == n1[i] % 2)
                            {
                                it1 = odd1[0];
                                n1[i] ^= n1[it1];
                                count1++;
                                res1.push_back(make_pair(i + 1, it1 + 1));
                                temp1 = n1[i] % 2;
                            }
                            else
                            {
                                temp1 = n1[i] % 2;
                            }
                        }
                    }
                }
                // 1st odd
                // 2nd odd too then changing 2nd element

                else if (l == 1)
                {

                    // 1st even
                    // 2nd also even then changing 1st
                    if (n2[0] % 2 == 0)
                    {
                        if (n2[1] % 2 == 0)
                        {
                            it2 = odd2[0];
                            n2[1] ^= n2[it2];
                            count2++;
                            res2.push_back(make_pair(2, it2 + 1));
                            odd2[0] = 1;
                            temp2 = n2[1] % 2;
                            for (int i = 2; i < n; i++)
                            {
                                if (temp2 == n2[i] % 2)
                                {
                                    it2 = odd2[0];
                                    n2[i] ^= n2[it2];
                                    count2++;
                                    res2.push_back(make_pair(i + 1, it2 + 1));
                                    temp2 = n2[i] % 2;
                                }
                                else
                                {
                                    temp2 = n2[i] % 2;
                                }
                            }
                        }
                        else
                        {

                            temp2 = n2[1] % 2;
                            for (int i = 2; i < n; i++)
                            {
                                if (temp2 == n2[i] % 2)
                                {
                                    it2 = odd2[0];
                                    n2[i] ^= n2[it2];
                                    count2++;
                                    res2.push_back(make_pair(i + 1, it2 + 1));
                                    temp2 = n2[i] % 2;
                                }
                                else
                                {
                                    temp2 = n2[i] % 2;
                                }
                            }
                        }
                    }
                    // 1st odd

                    else if (n2[0] % 2 == 1)
                    {

                        temp2 = n2[0] % 2;
                        for (int i = 1; i < n; i++)
                        {
                            if (temp2 == n2[i] % 2)
                            {
                                it2 = odd2[0];
                                n2[i] ^= n2[it2];
                                count2++;
                                res2.push_back(make_pair(i + 1, it2 + 1));
                                temp2 = n2[i] % 2;
                            }
                            else
                            {
                                temp2 = n2[i] % 2;
                            }
                        }
                    }
                }
                l++;
            }

            // cout << count1 << endl;
            // for (auto &i : n1)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;

            // cout << count2 << endl;
            // for (auto &i : n2)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;

            if (count1 > count2)
            {
                cout << count2 << '\n';
                for (auto &p2 : res2)
                {
                    cout << p2.first << " " << p2.second << '\n';
                }
            }
            else
            {
                cout << count1 << '\n';
                for (auto &p1 : res1)
                {
                    cout << p1.first << " " << p1.second << '\n';
                }
            }
        }
    }
    return 0;
}
