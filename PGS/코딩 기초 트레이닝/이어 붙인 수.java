class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        
        String odd = "", even = "";
        for(int i = 0; i < num_list.length; i++) {
            if(num_list[i] % 2 == 1) {
                odd += Integer.valueOf(num_list[i]);
            }
            else {
                even += Integer.valueOf(num_list[i]);
            }
        }
        answer = Integer.parseInt(odd) + Integer.parseInt(even);
        
        return answer;
    }
}