import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[][] intervals) {
        int[] answer;
        
        List<Integer> list = new ArrayList<>();
        for(int[] interval : intervals) {
            int a = interval[0], b = interval[1];
            List<Integer> tmp = new ArrayList<>();
            for(int i = a; i <= b; i++) {
                tmp.add(arr[i]);
            }
            list.addAll(tmp);
        }
        answer = list.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}