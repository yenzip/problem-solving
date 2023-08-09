import java.util.*;

class Solution {
    static Map<String, Integer> hm = new HashMap<>();
    
    public String solution(String[] participant, String[] completion) {

        for(int i = 0; i < completion.length; i++) {
            hm.put(completion[i], hm.getOrDefault(completion[i], 0) + 1);
        }
        
        for(int i = 0; i < participant.length; i++) {
            if(!hm.containsKey(participant[i]) || hm.get(participant[i]) == 0) { // 예외) 동명이인 처리
                return participant[i];
            }
            hm.put(participant[i], hm.get(participant[i]) - 1);
        } 
        
        return null;
    }
}