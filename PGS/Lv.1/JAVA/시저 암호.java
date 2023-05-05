class Solution {
    public String solution(String s, int n) {

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(Character.isUpperCase(c)) {
                c = (char)('A' + (c - 'A' + n) % 26);
            }
            else if(Character.isLowerCase(c)) {
                c = (char)('a' + (c - 'a' + n) % 26);
            }
            sb.append(c);
        }
        
        return sb.toString();
    }
}