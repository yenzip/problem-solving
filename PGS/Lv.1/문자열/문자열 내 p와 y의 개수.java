class Solution {
    boolean solution(String s) {
        
        s = s.toLowerCase();
        int p = s.length() - s.replace("p", "").length();   // p 제거 후 두 문자열 길이의 차
        int y = s.length() - s.replace("y", "").length();   // y 제거 후 두 문자열 길이의 차

        return p == y;
    }
}