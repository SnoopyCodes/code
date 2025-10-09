import java.io.*;
import java.util.*;
import java.util.function.*;
import java.util.stream.Collectors;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
}

class Trie{
    String kb = "QWERTYUIOPASDFGHJKLZXCVBNM";
    Map<Character, Integer> cipher = ((Supplier<Map<Character, Integer>>) () -> {
        int i = 0;
        Map<Character, Integer> ciphe = new HashMap<>();
        for(char c : kb.toCharArray())
            ciphe.put(c, i++);
        return ciphe;
    }).get();
    Map<Integer, Character> decipher = cipher.entrySet().stream().collect(Collectors.toMap(Map.Entry::getValue, Map.Entry::getKey));
    TrieNode root;
    public Trie(){
        root = new TrieNode();
    }
    public void insert(String word){
        TrieNode curr = root;
        for(char ch: word.toCharArray()){
            curr = curr.children.computeIfAbsent(ch, child -> new TrieNode());
        }
        curr.isEnd = true;
    }
    private String dfs(String word, int i, TrieNode curr, StringBuilder sb){
        if(curr == null)
            return null;
        if(curr.isEnd)
            if(i == word.length())
                return sb.toString();
            else
                return null;
        if(i == word.length())
            return null;
        char curr_c = word.charAt(i);
        sb.append(curr_c);
        String res = dfs(word, i + 1, curr.children.get(curr_c), sb);
        if (res != null) return res;
        sb.deleteCharAt(sb.length() - 1);
        if(curr_c != 'P' && curr_c != 'L' && curr_c != 'M'){
            char neighbor = decipher.get(cipher.get(curr_c)+1);
            sb.append(neighbor);
            res = dfs(word, i + 1, curr.children.get(neighbor), sb);
            if (res != null) return res;
            sb.deleteCharAt(sb.length() - 1);
        }
        if(curr_c != 'Q' && curr_c != 'A' && curr_c != 'Z'){
            char neighbor = decipher.get(cipher.get(curr_c)-1);
            sb.append(neighbor);
            res = dfs(word, i + 1, curr.children.get(neighbor), sb);
            if (res != null) return res;
            sb.deleteCharAt(sb.length() - 1);
        }
        return null;
    }
    public String search(String word) {
        StringBuilder sb = new StringBuilder();
        String res = dfs(word, 0, root, sb);
        return res == null ? word : res;
    }
}

public class tinayi {

    public static void main(String[] args) throws IOException{
        
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(r.readLine());
        while(T-->0){
            StringTokenizer st = new StringTokenizer(r.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
            Trie trie = new Trie();
            String[] newroster = new String[M];
            st = new StringTokenizer(r.readLine());
            for(int i = 0; st.hasMoreTokens(); i++){
                trie.insert(st.nextToken());
            }
            st = new StringTokenizer(r.readLine());
            for(int i = 0; st.hasMoreTokens(); i++){
                newroster[i] = trie.search(st.nextToken());
            }
            Arrays.sort(newroster);
            for(int i = 0; i < M-1; i++)
                System.out.print(newroster[i] + " ");
            System.out.print(newroster[M-1] + "\n");
        }
    }
}
