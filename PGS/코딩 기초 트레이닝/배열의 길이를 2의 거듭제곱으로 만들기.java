import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        
        int size;
        for(size = 0; ;size++) {
            if(arr.length <= (int)Math.pow(2, size)) break;
        }
        
        int[] answer = new int[(int)Math.pow(2, size)];
        Arrays.fill(answer, 0);
        for(int i = 0; i < arr.length; i++) {
            answer[i] = arr[i];
        }
        
        return answer;
    }
}