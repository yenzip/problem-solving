class Solution {
    public String solution(String s) {

        int idx = 0;
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()) {
            if(!Character.isAlphabetic(c)) {
                idx = 0;
            }
            else {
                c = idx % 2 == 0 ? Character.toUpperCase(c) : Character.toLowerCase(c);
                idx++;
            }
            sb.append(c);
        }
        
        return sb.toString();
    }
}