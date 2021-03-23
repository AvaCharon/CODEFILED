
//LRU
import java.util.*;

public class Solution {
    /**
     * lru design
     * 
     * @param operators int整型二维数组 the ops
     * @param k         int整型 the k
     * @return int整型一维数组
     */
    public int[] LRU(int[][] operators, int k) {
        int ansLength = 0;
        for (int[] it : operators) {
            if (it[0] == 2)
                ansLength++;
        }
        int[] ans = new int[ansLength];
        int index = 0;

        MyLinkedHashMap<Integer, Integer> lhm = new MyLinkedHashMap<Integer, Integer>(k);

        for (int[] it : operators) {
            switch (it[0]) {
            case 1:
                lhm.set(it[1], it[2]);
                break;
            case 2:
                Integer value = lhm.get(it[1]);
                ans[index++] = value == null ? -1 : value;
            }
        }
        return ans;
    }
}

class MyLinkedHashMap extends LinkedHashMap {
    private final int capacity;
    private int count;

    MyLinkedHashMap(int capacity) {
        if (capacity < 1)
            throw new IllegalArgumentException();
        this.capacity = capacity;
    }

    public void set(Integer key, Integer value) {
        if (this.get(key) == null) {
            this.count++;
            if (count <= capacity)
                super.put(key, value);
            else {
                
            }
        }
        return ;
    }
}