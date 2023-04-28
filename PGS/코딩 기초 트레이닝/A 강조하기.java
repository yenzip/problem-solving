class Solution {
    public String solution(String myString) {
        String answer = "";
        
        char[] arr = myString.toCharArray();
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == 'a' || arr[i] == 'A') {
                arr[i] = Character.toUpperCase(arr[i]);
            }
            else {
                arr[i] = Character.toLowerCase(arr[i]);
            }
        }  
        answer = String.copyValueOf(arr);
        
        return answer;
    }
}