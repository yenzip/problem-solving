class Solution {
    public int solution(String[] spell, String[] dic) {
        
        for(String d : dic) {
            boolean isContain = true;
            
            for(String s : spell) {
                if(!d.contains(s)) {
                    isContain = false;
                    break;
                }
            }
            
            if(isContain) {
                return 1;
            }
        }
        
        return 2;
    }
}