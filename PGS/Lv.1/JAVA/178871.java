import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        Map<String, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < players.length; i++) {
            hm.put(players[i], i);
        }
        
        for(String c : callings) {
            int idx = hm.get(c);
            
            String tmp = players[idx];  // 순위 변경
            players[idx] = players[idx - 1];
            players[idx - 1] = tmp;
            
            hm.replace(c, idx - 1);
            hm.replace(players[idx], idx);
        }
        
        return players;
    }
}