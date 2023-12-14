class Solution {
    public String removeDuplicateLetters(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        boolean[] alphabet = new boolean[26];
        int[] lastIdx = new int[26];

        Arrays.fill(lastIdx, -1);

        for(int i = 0; i < s.length(); i++) {
            lastIdx[s.charAt(i) - 'a'] = i;
        }

        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if(alphabet[c - 'a']) { // 중복 문자
                continue;
            }

            while(!dq.isEmpty() && c < dq.peekLast() && i < lastIdx[dq.peekLast() - 'a']) {
                alphabet[dq.pollLast() - 'a'] = false;
            }

            alphabet[c - 'a'] = true;
            dq.offerLast(c);
        }

        StringBuilder answer = new StringBuilder();

        while(!dq.isEmpty()) {
            answer.append(dq.pollFirst());
        }

        return answer.toString();
    }
}