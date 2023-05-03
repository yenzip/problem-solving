import java.util.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        
        Map<Integer, Integer> map = new TreeMap<Integer, Integer>();  // {rank, 학생 번호}
        for(int i = 0; i < rank.length; i++) {
            if(attendance[i]) map.put(rank[i], i);
        }
        
        int[] arr = new int[map.size()];
        int idx = 0;
        for(Integer key : map.keySet()) {
            arr[idx++] = map.get(key);
        }
        
        int a = arr[0], b = arr[1], c = arr[2];
        
        return 10000 * a + 100 * b + c;
    }
}