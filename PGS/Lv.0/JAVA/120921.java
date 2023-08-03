class Solution {
    public int solution(String A, String B) {
        int answer;
        String s = A;
        
        for(answer = 0; answer < A.length(); answer++) {
            if(s.equals(B)) {
                return answer;
            }
            
            char c = s.charAt(A.length() -1);
            s = c + s.substring(0, A.length() -1);
        }
        
        return -1;
    }
}