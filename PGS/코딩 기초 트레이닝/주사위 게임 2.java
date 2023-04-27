class Solution {
    public int solution(int a, int b, int c) {
        
        int answer = 0;
        int s = a + b + c;
        int d = (int)Math.pow(a, 2) + (int)Math.pow(b, 2) + (int)Math.pow(c, 2);
        int t = (int)Math.pow(a, 3) + (int)Math.pow(b, 3) + (int)Math.pow(c, 3);
        
        if(a != b && a != c && b != c) {
            answer = s;
        }
        else if((a == b && a != c) || (a == c && a != b) || (b == c && b != a) ) {
            answer = s * d;
        }
        else if(a == b && a == c) {
            answer = s * d * t; 
        }
        
        return answer;
    }
}