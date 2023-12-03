class Solution {

    public static class Letter {
        String idx;
        String str;
        
        public Letter(String idx, String str) {
            this.idx = idx;
            this.str = str;
        }
    }
    
    public static String[] reorderLogFiles(String[] logs) {
        List<String> digit = new ArrayList<>();
        List<Letter> letter = new ArrayList<>();
        List<String> answer = new ArrayList<>();

        for(String log : logs) {
            int blank = log.indexOf(" ");
            String idx = log.substring(0, blank);
            String str = log.substring(blank + 1);
            
            if(Character.isDigit(str.charAt(0))) {
                digit.add(log);
            } else {
                letter.add(new Letter(idx, str));
            }
        }

        Collections.sort(letter, new Comparator<Letter>(){ 		
			@Override 		
			public int compare(Letter a, Letter b) {
                if(a.str.equals(b.str)) {
                    return a.idx.compareTo(b.idx);
                }
                return a.str.compareTo(b.str);
            }
        });
        
        for(int i = 0; i < letter.size(); i++) {
            String log = letter.get(i).idx + " " + letter.get(i).str;
            answer.add(log);
        }
        
        answer.addAll(digit);
        
        return answer.toArray(String[]::new);
    }
}