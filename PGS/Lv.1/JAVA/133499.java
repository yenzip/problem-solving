class Solution {
    static String[] babblingArr = {"aya", "ye", "woo", "ma"};
    
    public int solution(String[] babbling) {
        int answer = 0;
        
        for(String b : babbling) {
            if(b.contains("ayaaya") || b.contains("yeye") || b.contains("woowoo") || b.contains("mama")) {
                continue;   // 연속 발음 예외처리
            }
            
            for(String a : babblingArr) {
                b = b.replace(a, " ");
            }
            
            if(b.replaceAll(" ", "").isEmpty()) {
                answer++;
            }
        }
        
        return answer;
    }
}