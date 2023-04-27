class Solution {
    public int solution(int[] num_list) {

        int mul = 1, sum = 0;
        for(int i = 0; i < num_list.length; i++){
            mul *= num_list[i];
            sum += num_list[i];
        }
        sum = (int)Math.pow(sum, 2);
        
        return mul < sum ? 1 : 0;
    }
}