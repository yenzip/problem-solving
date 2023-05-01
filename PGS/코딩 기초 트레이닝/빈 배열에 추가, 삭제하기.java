import java.util.*;

class Solution {
    public int[] solution(int[] arr, boolean[] flag) {
        
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < arr.length; i++) {
            if(flag[i]) {
                for(int j = 0; j < arr[i] * 2; j++) {
                    s.push(arr[i]);
                }
            }
            else {
                for(int j = 0; j < arr[i]; j++) {
                    s.pop();
                }
            }
        }
        
        return s.stream().mapToInt(Integer::intValue).toArray();
    }
}