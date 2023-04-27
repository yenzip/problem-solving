class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        
        String s1 = Integer.toString(a) + Integer.toString(b);
        String s2 = Integer.toString(b) + Integer.toString(a);
        
        answer = Math.max(Integer.valueOf(s1), Integer.valueOf(s2));
        
        return answer;
    }
}