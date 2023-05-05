class Solution {
    public int solution(int n) {
        
        String str = Integer.toString(n, 3);    // 1. 정수 -> 3진법 문자열
        String reversed = new StringBuilder(str).reverse().toString();  // 2. 3진법 문자열 뒤집기
        int answer = Integer.parseInt(reversed, 3);   // 3. 3진법 문자열 -> 정수
        
        return answer;
    }
}