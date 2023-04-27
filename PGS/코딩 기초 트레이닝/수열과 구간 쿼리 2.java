class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        int[] answer = new int[queries.length];
        
        for(int i = 0; i < queries.length; i++) {
            int s = queries[i][0], e = queries[i][1] , k = queries[i][2];
            
            int res = 1000000;
            for(int j = s; j <= e; j++){
                if(arr[j] > k) {
                    res = Math.min(res, arr[j]);
                }
            }
            answer[i] = res == 1000000 ? -1 : res;
        }
        
        return answer;
    }
}