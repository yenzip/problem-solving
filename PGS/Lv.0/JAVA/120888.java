class Solution {
    public String solution(String my_string) {
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < my_string.length(); i++) {
            char c = my_string.charAt(i);
            
            if(my_string.indexOf(c) == i) {
                sb.append(c);
            }
        }
        
        return sb.toString();
    }
}