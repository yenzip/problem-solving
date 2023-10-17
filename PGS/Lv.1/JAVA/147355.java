class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int pLen = p.length();
        long pVal = Long.parseLong(p);
        
        for(int i = 0; i <= t.length() - pLen; i++) {
            long tVal = Long.parseLong(t.substring(i, i + pLen));
            
            if(tVal <= pVal) {
                answer++;
            }
        }
        
        return answer;
    }
}