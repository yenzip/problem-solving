class Solution {
    public int solution(int[] array) {
        int[] A = new int[1000];
        int max = 0;
        
        for(int i = 0; i < array.length; i++) {
            A[array[i]]++;
            max = Math.max(max, A[array[i]]);
        }
        
        int answer = 0;
        int maxCnt = 0;
        
        for(int i = 0; i < 1000; i++) {
            if(A[i] == max) {
                answer = i;
                maxCnt++;
            }
            if(maxCnt > 1) {
                return -1;
            }
        }

        return answer;
    }
}