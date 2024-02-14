import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class MergingTables {
    private final InputReader reader;
    private final OutputWriter writer;

    public MergingTables(InputReader reader, OutputWriter writer) {
        this.reader = reader;
        this.writer = writer;
    }

    public static void main(String[] args) {
        InputReader reader = new InputReader(System.in);
        OutputWriter writer = new OutputWriter(System.out);
        new MergingTables(reader, writer).run();
        writer.writer.flush();
    }

    class Table {
        Table parent;
        Table mergedTo;
        int id;
        int rank;
        long numberOfRows;

        Table(long numberOfRows) {
            this.numberOfRows = numberOfRows;
            rank = 0;
            parent = this;
            mergedTo = null;
        }
        Table getParent() {
            // find super parent and compress path
            Table p = this.parent;
            while (p != p.parent) {
                p = p.parent;
            }
            return p.parent;
        }

        @Override
        public String toString() {
            return Integer.toString(id);
        }
    }

    long maximumNumberOfRows = -1;

    void merge(Table destination, Table source) {
        Table realDestination = destination.getParent();
        Table realSource = source.getParent();
        if (realDestination == realSource) {
            return;
        }
//        // merge two components here
        long totalMergedRows;

        // use rank heuristic
        if (realDestination.rank > realSource.rank) {
            realSource.parent = realDestination;

            realDestination.numberOfRows += realSource.numberOfRows;
            realDestination.mergedTo = destination;
            realSource.mergedTo = null;

            totalMergedRows = realDestination.numberOfRows;
        } else {
            realDestination.parent = realSource;

            realSource.numberOfRows += realDestination.numberOfRows;
            realSource.mergedTo = destination;
            realDestination.mergedTo = null;

            totalMergedRows = realSource.numberOfRows;

            if (realDestination.rank == realSource.rank) {
                realSource.rank = realDestination.rank + 1;
            }
        }

        // update maximumNumberOfRows
        maximumNumberOfRows = Math.max(maximumNumberOfRows, totalMergedRows);
    }

    public void run() {
        int n = reader.nextInt();
        int m = reader.nextInt();
        Table[] tables = new Table[n];
        for (int i = 0; i < n; i++) {
            int numberOfRows = reader.nextInt();
            tables[i] = new Table(numberOfRows);
            tables[i].id = i + 1;
            maximumNumberOfRows = Math.max(maximumNumberOfRows, numberOfRows);
        }
        for (int i = 0; i < m; i++) {
            int destination = reader.nextInt() - 1;
            int source = reader.nextInt() - 1;
            merge(tables[destination], tables[source]);
            writer.printf("%d\n", maximumNumberOfRows);
        }
    }


    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    static class OutputWriter {
        public PrintWriter writer;

        OutputWriter(OutputStream stream) {
            writer = new PrintWriter(stream);
        }

        public void printf(String format, Object... args) {
            writer.print(String.format(Locale.ENGLISH, format, args));
        }
    }
}