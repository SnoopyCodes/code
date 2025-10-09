import java.io.*;
import java.util.*;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isEnd = false;
}

class Trie{
    char[] kb = "QWERTYUIOP[ASDFGHJKL[ZXCVBNM".toCharArray();
    TrieNode root;
    int[] enc = new int[65 + 28]; //given a char, find its index in kb
    public Trie(){
        root = new TrieNode();
        for (int i = 0; i < 28; i++) {
            enc[kb[i]] = i;
        }
    }
    void insert(String word){
        TrieNode curr = root;
        for(char ch: word.toCharArray()){
            if (curr.children[ch - 65] == null) { curr.children[ch - 65] = new TrieNode(); }
            curr = curr.children[ch - 65];
        }
        curr.isEnd = true;
    }
    
    String dfs(String word, int i, TrieNode curr, StringBuilder sb){
        if(curr == null) { return null; }
        if(curr.isEnd) { return i == word.length() ? sb.toString() : null; }
        if(i == word.length()) { return null; }
        char curr_c = word.charAt(i);
        for (int d : new int[]{ 0, 1, -1 }) {
            int ind = enc[curr_c] + d;
            if (ind < 0 || ind == 28 || kb[ind] == '[') { continue; }
            sb.append(kb[ind]);
            String res = dfs(word, i + 1, curr.children[kb[ind] - 65], sb);
            if (res != null) { return res; }
            sb.deleteCharAt(sb.length() - 1);
        }
        return null;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException{
        var now = System.currentTimeMillis();
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(r.readLine());
        while(T-->0){
            StringTokenizer st = new StringTokenizer(r.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
            Trie trie = new Trie();
            String[] newroster = new String[M];
            st = new StringTokenizer(r.readLine());
            while (st.hasMoreTokens()) {
                trie.insert(st.nextToken());
            }
            st = new StringTokenizer(r.readLine());
            for(int i = 0; st.hasMoreTokens(); i++){
                String w = st.nextToken();
                String res = trie.dfs(w, 0, trie.root, new StringBuilder());
                newroster[i] = res == null ? w : res;
            }
            Arrays.sort(newroster);
            for(int i = 0; i < M-1; i++)
                System.out.print(newroster[i] + " ");
            System.out.print(newroster[M-1] + "\n");
            // System.out.println(System.currentTimeMillis() - now);
        }
    }
}
