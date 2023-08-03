class Solution {
    static String[] babblingArr = {"aya", "ye", "woo", "ma"};
    
    public int solution(String[] babbling) {
        int answer = 0;
        
        for(String b : babbling) {
            for(String s : babblingArr) {
                b = b.replaceFirst(s, " ");
            }
            
            if(b.replaceAll(" ", "").equals("")) {
                answer++;
            }
        }
        
        return answer;
    }
}