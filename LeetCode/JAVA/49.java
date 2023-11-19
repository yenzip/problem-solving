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
            List<String> words = m.get(key);
            Collections.sort(words); // value(List) 알파벳 정렬
            answer.add(words);
        }
        
        answer.sort((a1, a2) -> (a1.size() < a2.size()) ? -1 : (a1.size() == a2.size()) ? 0 : 1);   // List의 크기별 정렬

        return answer;
    }
}