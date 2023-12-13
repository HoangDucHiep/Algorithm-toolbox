    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        while(toNum(a[j-1], a[j]) < toNum(a[j], a[j-1]) && j-1>=0)
        {
            swap(a[j], a[j-1]);
            j--;
        }
    }