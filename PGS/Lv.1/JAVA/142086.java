import java.util.*;

class Solution {
    static Map<Character, Integer> hm = new HashMap<>();
    
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        char[] arr = s.toCharArray();
        
        for(int i = 0; i < arr.length; i++) {
            if(hm.containsKey(arr[i])) {
                answer[i] = i - hm.get(arr[i]);
                hm.replace(arr[i], i);
            }
            else {
                answer[i] = -1;
                hm.put(arr[i], i);
            }
        }
        
        return answer;
    }
}