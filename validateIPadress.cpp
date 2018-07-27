int isValid(char *ip)
{
    int n = strlen(ip);
    string str;
    int dots = 0;
    for(int i = 0; i < n; i++)
    {
        if(ip[i] == '.')
        {
            dots++;
            continue;
        }
        if(ip[i] >= '0' and ip[i] <= '9')
            continue;
        else
            return 0;
    }
    if(dots != 3)
        return 0;
    int i = 0;
    
    while(i < n)
    {
        str = "";
        while(i < n and ip[i] != '.')
            str += ip[i++];
        if(str.length() == 0)
            return 0;
        if(str.length() > 3 or stoi(str) > 255)
                return 0;
        if(str.length() > 1 and stoi(str) == 0)
                return 0;
        if(str.length() > 1 and str[0] == '0')
                return 0;
        if(i < n)
            i++;
    }
    return 1;
}
