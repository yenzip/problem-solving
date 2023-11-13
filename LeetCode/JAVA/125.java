class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;

        while(i < j) {
            Character a = s.charAt(i);
            Character b = s.charAt(j);

            if(!Character.isLetter(a) && !Character.isDigit(a)) {
                i++;
            } else if(!Character.isLetter(b) && !Character.isDigit(b)) {
                j--;
            } else {
                if(Character.toLowerCase(a) != Character.toLowerCase(b)) {
                    return false;
                }
                i++;
                j--;
            }
        }

        return true;
    }
}