class Solution {
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        Map<Character, Character> bracket = new HashMap<>();
        bracket.put(')', '(');
        bracket.put('}', '{');
        bracket.put(']', '[');

        for(char c : s.toCharArray()) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if(stk.isEmpty()) {
                    return false;
                }

                if(stk.peek() == bracket.get(c)) {
                    stk.pop();
                } else return false;
            }
        }

        return stk.isEmpty();
    }
}