import java.util.*;

class Solution {
    static Map<String, Integer> hm = new HashMap<>();
    
    public int solution(String[][] clothes) {
        
        for(int i = 0; i < clothes.length; i++) {
            hm.put(clothes[i][1], hm.getOrDefault(clothes[i][1], 0) + 1);
        }
        
        int answer = 1;
        
        for(String key : hm.keySet()) {
            answer *= (hm.get(key) + 1);
        }
        
        return answer - 1;
    }
}