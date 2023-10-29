import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Deque<Integer> dq = new ArrayDeque<>();
        
        dq.add(arr[0]);
        
        for(int i = 1; i < arr.length; i++) {
            if(dq.peekLast() == arr[i]) {
                continue;
            }
            dq.add(arr[i]);
        }
        
        int[] answer = dq.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
}