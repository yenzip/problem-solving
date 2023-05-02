class Solution {
    public String[] solution(String[] picture, int k) {
        String[] answer = new String[picture.length * k];
        
        for(int i = 0, idx = 0; i < picture.length; i++) {
            StringBuilder sb = new StringBuilder();
            for(char c : picture[i].toCharArray()) {
                sb.append(Character.toString(c).repeat(k));
            }
            for(int j = 0; j < k; j++) {
                answer[idx++] = sb.toString();
            }
        }
        return answer;
    }
}