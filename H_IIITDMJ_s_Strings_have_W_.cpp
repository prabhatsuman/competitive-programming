#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin >> w;
    int ch=0;
    string str;
    cin >> str;
    string res = "";
    int len = str.length();
    int freq[26] = {0};
    int count[26]={0};

    // hashing to count the aperance of each character
    for (int i = 0; i < len; i++)
    {
        freq[str[i] - 'a']++;
    }
    
    for (int i = 0; i < len; i++)
    {
        if (freq[str[i] - 'a'] % w == 0)
        {
            count[str[i]-'a']++;
            if(count[str[i]-'a']==1)
            {
                if(freq[str[i] - 'a']==w)
                {
                    res+=str[i];
                }
                else
                {
                    int n=(freq[str[i] - 'a'])/w;
                    for(int k=1; k<=n;k++)
                    {
                        res+=str[i];
                    }
                }
            }
        }
        else
        {
            cout << "-1" << endl;
            ch=1;
            break;
        }
    }
    if(ch==0)
    {
        string temp=res;
        for(int k=1; k<w;k++)
        {
            res+=temp;
        }
        cout<<res<<endl;
    }

    return 0;
}
