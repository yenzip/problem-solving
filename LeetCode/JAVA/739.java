class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<Integer> stk = new Stack<>();
        stk.push(0);

        for(int i = 1; i < temperatures.length; i++) {
            while(!stk.isEmpty() && temperatures[stk.peek()] < temperatures[i]) {
                answer[stk.peek()] = i - stk.peek();
                stk.pop();
            }
            stk.push(i);
        }

        return answer;
    }
}