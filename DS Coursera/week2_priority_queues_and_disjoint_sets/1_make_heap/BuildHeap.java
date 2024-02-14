import java.io.*;
import java.util.*;

public class BuildHeap {
    private int[] data;
    private List<Swap> swaps;

    private FastScanner in;
    private PrintWriter out;

    public static void main(String[] args) throws IOException {
        new BuildHeap().solve();
    }

    private void readData() throws IOException {
        int n = in.nextInt();
        data = new int[n];
        for (int i = 0; i < n; ++i) {
            data[i] = in.nextInt();
        }
    }

    private void writeResponse() {
        out.println(swaps.size());
        for (Swap swap : swaps) {
            out.println(swap.index1 + " " + swap.index2);
        }
    }

    private void generateSwaps() {
        swaps = new ArrayList<Swap>();

        // this is the maximal index in data[]
        int max_index = data.length - 1;

        // this is the 0-based index of the first element with at least one child
        int n = data.length / 2 - 1;

        // this iterates backwards through all the parent nodes in data[]
        for (int i = n; i >= 0; i--) {

//            // print the index and the value of the parent node data[i]
//            out.println(i + ": " + data[i]);

            // left child node index and value
            int l_child_index = 2 * i + 1;
            int l_child = Integer.MAX_VALUE;
            if (l_child_index <= max_index) {
                l_child = data[l_child_index];
            }

            // right child node index and value
            int r_child_index = l_child_index + 1; //2 * i + 2;
            int r_child = Integer.MAX_VALUE;
            if (r_child_index <= max_index) {
                r_child = data[r_child_index];
            }

//            // print the index and the value of the left child of data[i]
//            if (l_child != Integer.MAX_VALUE) {
//                out.println("l_child " + l_child_index + ": " + l_child);
//            }
//
//            // print the index and the value of the right child of data[i]
//            if (r_child != Integer.MAX_VALUE) {
//                out.println("r_child " + r_child_index + ": " + r_child);
//            }

            // minimal child value
            int min_child = Math.min(l_child, r_child);

            // if there were children (there always are, but let's check just in case)
            // and the minimal child value is less than the value of the parent node
            // then sift the parent node down
            if (min_child != Integer.MAX_VALUE && min_child < data[i]) {
                SiftDown(i);
            }
        }
    }

    private void SiftDown(int i) {
//        // print the index of the maximal node
//        out.println("SiftDown(" + i + ")");

        // this is the index of the current maximal node in need to be sifted down
        int max_index = i;
        // this is the size of data[]
        int size = data.length - 1;

        // right child node index (first check the greater of two indexes)
        int r_child_index = 2 * i + 2;
        if (r_child_index <= size && data[r_child_index] < data[max_index]) {
            max_index = r_child_index;
        }

        // left child node index (then check the lesser of two indexes)
        int l_child_index = r_child_index - 1; //2 * i + 1;
        if (l_child_index <= size && data[l_child_index] < data[max_index]) {
            max_index = l_child_index;
        }

        if (i != max_index) {
            // swap the nodes
            swaps.add(new Swap(i, max_index));
            int temp = data[i];
            data[i] = data[max_index];
            data[max_index] = temp;

            // check if the newly sifted down node needs to be further sifted down
            SiftDown(max_index);
        }
    }

    public void solve() throws IOException {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        readData();
        generateSwaps();
        writeResponse();
        out.close();
    }

    static class Swap {
        int index1;
        int index2;

        public Swap(int index1, int index2) {
            this.index1 = index1;
            this.index2 = index2;
        }
    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}
