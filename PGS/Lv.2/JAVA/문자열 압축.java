import java.util.*;

class Solution {
    public int solution(String s) {
        
        int answer = Integer.MAX_VALUE; 
        for(int i = 1; i <= s.length(); i++) {
            List<String> list = new ArrayList<>();  // 해당 길이로 자른 문자열 저장
            for(int sIdx = 0; sIdx < s.length(); sIdx += i) {
                int eIdx = sIdx + i;
                if(eIdx > s.length()) { // 문자열 범위 밖 처리
                    eIdx = s.length();
                }
                list.add(s.substring(sIdx, eIdx));
            }
            
            StringBuilder sb = new StringBuilder(); // 문자열 압축
            int count = 1;
            String prev = "";
            for(String now : list) {
                if(now.equals(prev)) {
                    count++;
                }
                else {
                    if(count > 1) sb.append(count);
                    sb.append(prev);
                    prev = now;
                    count = 1;
                }
            }
            if(count > 1) sb.append(count);
            sb.append(prev);
            
            answer = Math.min(answer, sb.toString().length());
        }
        
        return answer;
    }
}