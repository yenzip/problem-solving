import java.util.*;

class Song implements Comparable<Song> {
    int idx;
    int plays;
    
    Song(int idx, int plays) {
        this.idx = idx;
        this.plays = plays;
    }
    
    @Override
    public int compareTo(Song other) {
        if (plays == other.plays) {
            return Integer.compare(idx, other.idx);
        }
        return Integer.compare(other.plays, plays);
    }
}

class Genre {
    String name;
    int totalPlays;
    
    Genre(String name, int totalPlays) {
        this.name = name;
        this.totalPlays = totalPlays;
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> answer = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();   // {장르명, 총 재생 횟수}
        Map<String, List<Song>> mm = new HashMap<>();   // MultiMap {장르명, {고유번호, 재생횟수}}
        
        for(int i = 0; i < genres.length; i++) {
            m.put(genres[i], m.getOrDefault(genres[i], 0) + plays[i]);
            mm.computeIfAbsent(genres[i], key -> new ArrayList<Song>()).add(new Song(i, plays[i]));
        }
        
        PriorityQueue<Genre> pq = new PriorityQueue<>((g1, g2) -> g2.totalPlays - g1.totalPlays);
        
        for(String key : m.keySet()) {
            pq.add(new Genre(key, m.get(key)));
        }
        
        while(!pq.isEmpty()) {
            String genre = pq.poll().name;
            List<Song> songList = mm.get(genre);

            Collections.sort(songList);

            answer.add(songList.get(0).idx);

            if (songList.size() >= 2) {
                answer.add(songList.get(1).idx);
            }
        }
         
        return answer.stream().mapToInt(i->i).toArray();
    }
}