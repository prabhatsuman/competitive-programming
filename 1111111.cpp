#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }
    int i=0;
    int ma = 0;
    do {
        int sum=0;
        int m=0;
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
            sum+=permutation[i]*(i+1);
            m=max(m,permutation[i]*(i+1));
           
        }
         cout<<sum-m<<endl;
         
        ma=max(ma,sum-m);
        i++;
       

        cout << endl;
        if(i==200)
        {
            break;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout<<ma<<endl;
    return 0;
}
