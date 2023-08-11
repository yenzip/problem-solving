class Solution {
    public String solution(String s, String skip, int index) {
        StringBuilder sb = new StringBuilder();
        
        for(int i =0; i < s.length(); i++) {
            char c = s.charAt(i);
            int count = 0;
            
            while(count < index) {
                c += 1;
                
                if(c > 'z') {
                    c -= 26;
                }
                
                if(skip.contains(c + "")) {
                    continue;
                }
                
                count++;
            }
            
            sb.append(c);
        }
        
        return sb.toString();
    }
}