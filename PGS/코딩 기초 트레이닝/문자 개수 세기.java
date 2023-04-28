class Solution {
    public int[] solution(String my_string) {
        int[] answer = new int[52];
        
        for(int i = 0; i < my_string.length(); i++) {
            char c = my_string.charAt(i);
            int idx;
            if(Character.isUpperCase(c)) {
                idx = c - 'A';
            }
            else {
                idx = c - 'a' + 26;
            }
            answer[idx]++;
        }
        return answer;
    }
}