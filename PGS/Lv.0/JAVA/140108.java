class Solution {
    public int solution(String s) {
        int answer = 0;        
        char x = s.charAt(0);
        int xCnt = 0;
        int notXCnt = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(xCnt == notXCnt) {
                answer++;
                x = s.charAt(i);
            }
            
            if(s.charAt(i) == x) {
                xCnt++;
            }
            else {
                notXCnt++;
            }
        }
        
        return answer;
    }
}