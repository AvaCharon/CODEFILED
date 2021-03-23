//快排
import java.util.*;

import javax.crypto.interfaces.PBEKey;

public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可 将给定数组排序
     * 
     * @param arr int整型一维数组 待排序的数组
     * @return int整型一维数组
     */
    public int[] MySort(int[] arr) {
        int len = arr.length;
        quicksort(0, len - 1, arr);
        return arr;
    }

    public void quicksort(int start, int last, int[] arr) {
        if (start >= last)
            return;
        int i = start, j = last, a = start;
        while (i < j) {
            while (i < j && arr[j] >= arr[a])
                j--;
            while (i < j && arr[i] <= arr[a])
                i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        int tmp = arr[i];
        arr[i] = arr[a];
        arr[a] = tmp;
        quicksort(start, i, arr);
        quicksort(j + 1, last, arr);
        return;
    }
}