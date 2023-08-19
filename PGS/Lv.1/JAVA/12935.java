class Solution {
    public int[] solution(int[] arr) {
        int[] answer = new int[arr.length - 1];
        int minVal = arr[0];
        
        for(int i = 1; i < arr.length; i++) {
            minVal = Math.min(minVal, arr[i]);
        }
        
        int idx = 0;
        
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == minVal) {
                continue;
            }
            answer[idx++] = arr[i];
        }
    
        return answer.length == 0 ? new int[]{-1} : answer;
    }
}