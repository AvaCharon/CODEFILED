import java.net.*;
import java.io.*;
import java.util.*;

public class WordsOfSameChar {
    public static void main(String[] args) throws IOException {
        URL url = new URL("http://www.puzzlers.org/pub/wordlists/unixdict.txt");
        InputStreamReader isr = new InputStreamReader(url.openStream());
        BufferedReader reader = new BufferedReader(isr);

        Map<String, Collection<String>> anagrams = new HashMap<String, Collection<String>>();
        String words;
        int count = 0;
        while ((words = reader.readLine()) != null) {
            char[] ch = words.toCharArray();
            Arrays.sort(ch);
            String key = new String(ch);
            if (!anagrams.containsKey(key))
                anagrams.put(key, new ArrayList<String>());
            anagrams.get(key).add(words);
            count = Math.max(count, anagrams.get(key).size());
        }
        reader.close();
        for (Collection<String> ans : anagrams.values()) {
            if (count == ans.size())
                System.out.println(ans);
        }
    }
}
