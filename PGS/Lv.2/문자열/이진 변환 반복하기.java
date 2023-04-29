class Solution {
    public int[] solution(String s) {
        
        int count = 0;
        int zero = 0;
        while(!s.equals("1")) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '1') {
                    sb.append('1');
                }
            }
            int c = sb.toString().length();
            zero += s.length() - c;
            s = Integer.toString(c, 2);
            count++;
        }

        return new int[]{count, zero};
    }
}