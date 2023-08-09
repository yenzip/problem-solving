import java.util.*;

class Solution {
    static Map<Character, Integer> hm = new HashMap<>();
    
    public String solution(String[] survey, int[] choices) {
        
        for(int i = 0; i < survey.length; i++) {
            char c = survey[i].charAt(0);
            int score = Math.abs(choices[i] - 4);
            
            if(choices[i] == 4) {
                continue;
            }
            else if(choices[i] > 4) {
                c = survey[i].charAt(1);
            }
            
            hm.put(c, hm.getOrDefault(c, 0) + score);
        }
        
        StringBuilder sb = new StringBuilder();
        sb.append(hm.getOrDefault('R', 0) >= hm.getOrDefault('T', 0) ? 'R' : 'T');
        sb.append(hm.getOrDefault('C', 0) >= hm.getOrDefault('F', 0) ? 'C' : 'F');
        sb.append(hm.getOrDefault('J', 0) >= hm.getOrDefault('M', 0) ? 'J' : 'M');
        sb.append(hm.getOrDefault('A', 0) >= hm.getOrDefault('N', 0) ? 'A' : 'N');
        
        return sb.toString();
    }
}