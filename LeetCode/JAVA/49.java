class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>();
        Map<String, List<String>> m = new HashMap<>();  // MultiMap = key(1) : value(N)

        for(String str : strs) {
            String word = str;
            
            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            str = String.valueOf(charArr);
            
            m.computeIfAbsent(str, key -> new ArrayList<String>()).add(word);
        }
        
        for(String key : m.keySet()) {
            answer.add(m.get(key));
        }
        
        return answer;
    }
}