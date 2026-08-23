bool sumGame(char* num)
{
    int n = strlen(num);
    int half = n / 2;

    int s1 = 0, s2 = 0;
    int q1 = 0, q2 = 0;

    
    for (int i = 0; i < half; i++)
    {
        if (num[i] == '?')
        {
            q1++;
        }
        else
        {
            s1 += num[i] - '0';
        }
    }

    
    for (int i = half; i < n; i++)
    {
        if (num[i] == '?')
        {
            q2++;
        }
        else
        {
            s2 += num[i] - '0';
        }
    }

    
    if ((q1 + q2) % 2 == 1)
    {
        return true;
    }

    
    if (s1 - s2 == 9 * (q2 - q1) / 2)
    {
        return false;
    }

    return true;
}