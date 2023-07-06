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
        vector<int> nums(n);
        vector<int> num1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            num1[i] = nums[i];
        }
        vector<int> odd;
        vector<int> odd1;
        vector<pair<int, int>> res;
        vector<pair<int, int>> res1;
        int count = 0, count1 = 0;
        int it = 0, it1 = 0;
        int temp = -1, temp1 = -1;
        
        int flag = 0;
        int l = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1 == 1)
            {
                odd.push_back(i);
                odd1.push_back(i);
                if (odd.size() == 2)
                {
                    break;
                }
            }
        }
        // for (auto &g : odd)
        // {
        //     cout<<g<<" ";
        // }
        // cout<<'\n';

        if (odd.size() == 0)
        {
            cout << "-1" << '\n';
        }
        else if (n == 2 && odd.size() == 2)
        {
            cout << "1" << '\n';
            cout << "1"
                 << " "
                 << "2" << '\n';
        }
        else if (n == 2 && odd.size() == 1)
        {
            cout << count << '\n';
        }
        else
        {
            if (nums[0] % 2 == nums[1] % 2 && nums[1] % 2 == nums[2] % 2)
            {

                flag = 1;
                while (l < 2)
                {
                    if (l == 0)
                    {
                        it = odd[0];
                        nums[1] ^= nums[it];
                        res.push_back(make_pair(2, it + 1));
                        count++;
                        if (nums[1] % 2 != 0)
                        {
                            odd[0] = 1;
                        }
                        temp = nums[2] % 2;
                        for (int i = 3; i < n; i++)
                        {
                            if (temp == nums[i] % 2)
                            {
                                it = odd[0];
                                nums[i] ^= nums[it];
                                temp = nums[i] % 2;
                                count++;
                                res.push_back(make_pair(i + 1, odd[0] + 1));
                            }
                            else
                            {
                                temp = nums[i] % 2;
                            }
                        }
                    }
                    else if (l == 1)
                    {
                        if (odd1[0] != 0)
                        {
                            it1 = odd1[0];
                            num1[0] ^= num1[it1];
                            odd1[0] = 0;
                            count1++;
                            res1.push_back(make_pair(1, it1 + 1));
                            it1 = odd1[0];
                            num1[2] ^= num1[it1];
                            count1++;
                            res1.push_back(make_pair(3, it1 + 1));
                            temp1 = num1[2] % 2;
                            for (int i = 3; i < n; i++)
                            {
                                if (temp1 == num1[i] % 2)
                                {
                                    it1 = odd1[0];
                                    num1[i] ^= num1[it1];
                                    temp1 = num1[i] % 2;
                                    count1++;
                                    res1.push_back(make_pair(i + 1, odd1[0] + 1));
                                }
                                else
                                {
                                    temp1 = num1[i] % 2;
                                }
                            }
                        }
                        else
                        {
                            it1 = odd1[1];
                            num1[0] ^= num1[it1];
                            odd1[0] = it1;
                            count1++;
                            res1.push_back(make_pair(1, it1 + 1));
                            it1 = odd1[0];
                            num1[2] ^= num1[it1];
                            count1++;
                            res1.push_back(make_pair(3, it1 + 1));
                            temp1 = num1[2] % 2;
                            for (int i = 3; i < n; i++)
                            {
                                if (temp1 == num1[i] % 2)
                                {
                                    it1 = odd1[0];
                                    num1[i] ^= num1[it1];
                                    temp1 = num1[i] % 2;
                                    count1++;
                                    res1.push_back(make_pair(i + 1, odd1[0] + 1));
                                }
                                else
                                {
                                    temp1 = num1[i] % 2;
                                }
                            }
                        }
                    }
                    l++;
                }
                if (count1 > count)
                {
                    cout << count << "\n";
                    // for (auto &t : nums)
                    // {
                    //     cout << t << " ";
                    // }
                    // cout << endl;
                    for (auto &m : res)
                    {
                        cout << m.first << " " << m.second << '\n';
                    }
                    cout << '\n';
                }
                else
                {
                    cout << count1 << "\n";
                    // for (auto &t : num1)
                    // {
                    //     cout << t << " ";
                    // }
                    // cout << endl;
                    for (auto &m : res1)
                    {
                        cout << m.first << " " << m.second << '\n';
                    }
                    cout << '\n';
                }
            }
            else if (nums[0] % 2 == nums[1] % 2 && nums[1] % 2 != nums[2] % 2)
            {
                if (odd[0] != 0)
                {
                    it = odd[0];
                    nums[0] ^= nums[it];

                    res.push_back(make_pair(1, it + 1));
                    count++;
                    if (nums[0] % 2 != 0)
                    {
                        odd[0] = 0;
                    }
                }
                else if (odd[0] == 0 && odd.size() > 1)
                {
                    it = odd[1];
                    nums[0] ^= nums[it];
                    odd[0] = it;
                    res.push_back(make_pair(1, it + 1));
                    count++;
                }
            }
            else if (nums[0] % 2 != nums[1] % 2 && nums[1] % 2 == nums[2] % 2)
            {
                it = odd[0];
                nums[2] ^= nums[it];

                res.push_back(make_pair(3, it + 1));
                count++;
            }

            if (flag == 0)
            {
                temp = nums[2] % 2;
                for (int i = 3; i < n; i++)
                {
                    if (temp == nums[i] % 2)
                    {
                        it = odd[0];
                        nums[i] ^= nums[it];
                        temp = nums[i] % 2;
                        count++;
                        res.push_back(make_pair(i + 1, odd[0] + 1));
                    }
                    else
                    {
                        temp = nums[i] % 2;
                    }
                }
                cout << count << '\n';
                // for (auto &t : nums)
                // {
                //     cout << t << " ";
                // }
                // cout << endl;
                for (auto &m : res)
                {
                    cout << m.first << " " << m.second << '\n';
                }
            }
        }
    }
    return 0;
}
