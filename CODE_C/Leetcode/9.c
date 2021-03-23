bool isPalindrome(int x)
{
    int tx=0,xa=x;
    int itemp;
    if(x==0)return true;
    if(x<0)return false;
    itemp=x%10;
    if(x==0)return false;
    for(;;)
    {
        itemp=x%10;
        x=x-itemp;
        x=x/10;
        if(tx>(INT_MAX/10))return false;
        tx=tx*10+itemp;
        if(x==0)break;
    }
    if(tx==xa)return true;
    return false;
}

//


bool isPalindrome(int x)
{
    if(x<0)return false;
    if(x==0)return true;
    int m[100];
    int i=0,j=0;
    while (x)
    {
        m[i]=x%10;
        x=x/10;
        i++;
    }
    while (j<=(i/2))
    {
        if(m[j]!=m[i-j-1])return false;
        j++;
    }
    return true;
}