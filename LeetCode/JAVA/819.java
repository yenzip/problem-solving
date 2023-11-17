class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.split("[!?',;.\s]+");
        Set<String> s = new HashSet<>();
        Map<String, Integer> m = new HashMap<>();
        int maxFreq = 0;
        String answer = "";
        
        for(String ban : banned) {
            s.add(ban);
        }
        
        for(String word : words) {
            String lower = word.toLowerCase();

            if(s.contains(lower)) {
                continue;
            }
            
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