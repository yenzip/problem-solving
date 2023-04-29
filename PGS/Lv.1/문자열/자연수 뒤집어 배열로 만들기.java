class Solution {
    public int[] solution(long n) {
        
        String str = Long.toString(n);  // long -> String
        String reversed = new StringBuilder(str).reverse().toString();      // StringBuilder - reverse -> String    
        char[] arr = reversed.toCharArray();    // String -> char[]
        
        int[] answer = new int[arr.length];
        for(int i = 0; i < arr.length; i++) {
            answer[i] = arr[i] - '0';
        }
        
        return answer;
    }
}