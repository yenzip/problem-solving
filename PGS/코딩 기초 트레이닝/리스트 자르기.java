class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        int[] answer;
        
        int s, e, k = 1;
        if(n == 1) {
            s = 0; e = slicer[1];
            answer = new int[e - s + 1];
        }
        else if(n == 2) {
            s = slicer[0]; e = num_list.length - 1;
            answer = new int[e - s + 1];
        }
        else if(n == 3) {
            s = slicer[0]; e = slicer[1];
            answer = new int[e - s + 1];
        }
        else {
            s = slicer[0]; e = slicer[1]; k = slicer[2];
            answer = new int[(e - s) / k + 1];
        }
        
        for(int i = s, idx = 0; i <= e; i += k, idx++) {
            answer[idx] = num_list[i];
        }
        
        return answer;
    }
}