import java.util.*;

class Solution {
    public int[] solution(String[] intStrs, int k, int s, int l) {
        int[] answer;
        
        List<Integer> list = new ArrayList<>();
        for(String intStr : intStrs) {
            int n = Integer.parseInt(intStr.substring(s, s + l));
            if(n > k) {
                list.add(n);
            }
        }
        answer = list.stream().mapToInt(i -> i).toArray();

        return answer;
    }
}