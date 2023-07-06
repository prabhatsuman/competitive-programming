if (odd == 1)
    {
        ll g = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                g = __gcd(g, a[i]);
            }
        }
        if (g != 1)
        {
            cout << "NO" << nline;
            return;
        }
    }