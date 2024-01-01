int findUnique(int *arr, int size)
{
    int m = ((size-1)/2);
    for (int i = 0; i < size; i++)
    {
        int flag1 = 0,flag2 = 0;
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (*(arr + i) ^ *(arr + j))
            {
                flag1++;
            }
        
        }
        if (flag1==2*m)
        {
            return *(arr + i);
        }
    }
}