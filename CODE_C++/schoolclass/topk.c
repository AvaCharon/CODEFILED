#include <stdio.h>
#include <stdlib.h>

void AdjustDown(int *a, int n, int root)
{
    int child = root * 2 + 1;
    int parent = root;
    while (child < n)
    {
        if ((child + 1 < n) && (a[child + 1] < a[child]))
            child++;
        if (a[parent] > a[child])
        {
            int temp = a[child];
            a[child] = a[parent];
            a[parent] = temp;
            ;
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}

void HeapTopK(int *a, int n, int k)
{
    int num = n;
    int i = (k - 2) / 2;
    for (; i >= 0; i--)
    {
        AdjustDown(a, k, i);
    }
    for (i = k; i < num; i++)
    {
        if (a[i] > a[0])
        {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            AdjustDown(a, k, 0);
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d\n", a[i]);
    }
    return;
}

int main()
{
    int arr[10] = {1, 23, 43, 45, 65, 76, 78, 98, 90, 123};
    HeapTopK(arr, 10, 5);
    system("pause");
    return 0;
}

//大顶堆
void Adjust(int *nums, int k, int len)
{
    int i;
    nums[0] = nums[k];
    for (i = 2 * k; i <= len; i *= 2)
    {
        if (i < len && nums[i] < nums[i + 1])
            i++;
        if (nums[0] >= nums[i])
            break;
        else
        {
            nums[k] = nums[i];
            k = i;
        }
    }
    nums[k] = nums[0];
    return;
}
void BuildMaxHeap(int *nums, int len)
{
    int i;
    for (i = len / 2; i > 0; i--)
        Adjust(nums, i, len);
    return;
}

int *solve2(int *nums, int numsSize, int k)
{
    int *ans = (int *)malloc(sizeof(int) * k);
    int cnt = k - 1;
    int *lnums = (int *)malloc(sizeof(int) * (numsSize + 1));
    int i;
    for (i = numsSize - 1; i >= 0; i--)
        lnums[i + 1] = nums[i];
    BuildMaxHeap(lnums, numsSize); //建立大顶堆
    for (i = 1; i <= k; i++)
    {
        int t = lnums[1];
        lnums[1] = lnums[numsSize - i + 1];
        lnums[numsSize - i + 1] = t;
        ans[cnt--] = t;
        Adjust(lnums, 1, numsSize - i);
    }
    return ans;
}