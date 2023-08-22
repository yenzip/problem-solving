import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        Map<String, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < name.length; i++) {
            hm.put(name[i], yearning[i]);
        }
        
        int idx = 0;
        
        for(String[] p : photo) {
            for(int i = 0; i < p.length; i++) {
                if(hm.containsKey(p[i])) {
                    answer[idx] += hm.get(p[i]);
                }
            }
            idx++;
        }
        
        return answer;
    }
}