class Solution {
    public int check(int num) {
        int count = 0;
        while(num > 1) {
            if(num % 2 == 1) {
                num -= 1;
            }
            num /= 2;
            count++;
        }
        return count;
    }
    
    public int solution(int[] num_list) {
        int answer = 0;
        
        for(int i = 0; i < num_list.length; i++) {
            answer += check(num_list[i]);
        }
        
        return answer;
    }
}