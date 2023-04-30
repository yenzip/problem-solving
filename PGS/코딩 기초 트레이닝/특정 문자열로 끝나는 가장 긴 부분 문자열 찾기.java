class Solution {
    public String solution(String myString, String pat) {

        int e = 0;
        for(int i = myString.length() - 1; i >= 0; i--) {
            if(myString.substring(0, i + 1).endsWith(pat)) {
                e = i + 1;
                break;
            }
        }
        
        return myString.substring(0, e);
    }
}