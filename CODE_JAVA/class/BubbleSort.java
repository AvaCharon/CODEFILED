public class BubbleSort
{
    public static void main(String[] args)
    {
        int[] a=new int[]{1,6,9,4,3,2,5,8,7};
        for(int i=0;i<=a.length-1;i++)
            for(int j=0;j<=a.length-2;j++)
            {
                if(a[j]>a[j+1])
                {
                    int tmp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=tmp;
                }
            }
        for(int i=0;i<=a.length-1;i++)
            System.out.print(a[i]+" ");
    }
}