class Solution {
    public String longestPalindrome(String s) {
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); i++) {    // i : Palindrome의 가운데 문자
            int left = i, right = i;  // 홀수 Palindrome
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            }
            int oddLen = right - left - 1;

            left = i; right = i + 1;  // 짝수 Palindrome
            while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
                left--;
                right++;
            }
            int evenLen = right - left - 1;

            int len = Math.max(oddLen, evenLen);

            if (maxLen < len) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        return s.substring(start, start + maxLen);
    }
}