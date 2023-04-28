class Solution {
    public int[] solution(int[] num_list, int n) {
        int size = num_list.length / n + (num_list.length % n == 0 ? 0 : 1);
        int[] answer = new int[size];
        
        for(int i = 0; i < num_list.length; i += n) {
            answer[i / n] = num_list[i];
        }
        
        return answer;
    }
}