import java.util.*;

class Solution {
    public int solution(int[] array, int n) {
        int answer = 0;
        int diff = 100;

        Arrays.sort(array);
        
        for(int i = 0; i < array.length; i++) {
            int tmp = Math.abs(n - array[i]);
            
            if(diff > tmp) {
                answer = array[i];
                diff = tmp;
            }
            else if(diff == tmp) {
                answer = Math.min(answer, array[i]);
            }
        }

        return answer;
    }
}