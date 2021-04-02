bool contentheap(vector<int> input, int k, int len)
{
    if (2 * k + 1 <= len)
    {
        if (input[k] > input[2 * k] || input[k] > input[2 * k + 1])
            return false;
        contentheap(input, 2 * k, len);
        contentheap(input, 2 * k + 1, len);
    }
    else if (2 * k == len)
    {
        if (input[k] > input[2 * k])
            return false;
        contentheap(input, 2 * k, len);
    }
    return true;
}
void heaprun(vector<int> &input, int k, int len)
{
    if (2 * k + 1 <= len)
    {
        if (input[2 * k] < input[2 * k + 1])
        {
            int tmp = input[k];
            input[k] = input[2 * k];
            input[2 * k] = tmp;
            heaprun(input, 2 * k, len);
        }
        else
        {
            int tmp = input[k];
            input[k] = input[2 * k + 1];
            input[2 * k + 1] = tmp;
            heaprun(input, 2 * k + 1, len);
        }
    }
    if (2 * k == len)
    {
        if (input[2 * k] < input[2 * k + 1])
        {
            int tmp = input[k];
            input[k] = input[2 * k];
            input[2 * k] = tmp;
            heaprun(input, 2 * k, len);
        }
    }
    return;
}
void initheap(vector<int> input,int len)
{
    for(int i=len/2;i>=0;i--)
    {
        heaprun(input,i,len);
    }
    return ;
}