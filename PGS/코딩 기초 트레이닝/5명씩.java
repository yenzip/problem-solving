class Solution {
    public String[] solution(String[] names) {
        int size = names.length / 5 + (names.length % 5 == 0 ? 0 : 1);
        String[] answer = new String[size];
        
        for(int i = 0, idx = 0; i < names.length; i+=5, idx++) {
            answer[idx] = names[i];
        }
        
        return answer;
    }
}