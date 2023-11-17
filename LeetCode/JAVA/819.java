class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.split("[!?',;.\s]+");
        Map<String, Boolean> bm = new HashMap<>();
        Map<String, Integer> m = new HashMap<>();
        int maxFreq = 0;
        String answer = "";
        
        for(String ban : banned) {
            bm.put(ban, true);
        }
        
        for(String word : words) {
            if(bm.containsKey(word)) {
                continue;
            }
            String lower = word.toLowerCase();
            m.put(lower, m.getOrDefault(lower, 0) + 1);
            maxFreq = Math.max(maxFreq, m.get(lower));
        }
        
        for(String key : m.keySet()) {
            if(m.get(key) == maxFreq) {
                answer = key;
                break;
            }
        }
        
        return answer;
    }
}