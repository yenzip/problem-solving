class Solution {
    public int solution(int i, int j, int k) {
        int answer = 0;
        String c = Integer.toString(k);
        
        for(int a = i; a <= j; a++) {
            String s = Integer.toString(a);
            answer += s.length() - s.replace(c, "").length();
        }
        
        return answer;
    }
}