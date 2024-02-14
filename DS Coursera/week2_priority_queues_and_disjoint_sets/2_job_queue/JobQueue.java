import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class JobQueue {
    private int numWorkers;
    private int[] jobs;

    private int[] assignedWorker;
    private long[] startTime;

    private FastScanner in;
    private PrintWriter out;

    public static void main(String[] args) throws IOException {
        new JobQueue().solve();
    }

    private void readData() throws IOException {
        numWorkers = in.nextInt();
        int m = in.nextInt();
        jobs = new int[m];
        for (int i = 0; i < m; ++i) {
            jobs[i] = in.nextInt();
        }
    }

    private void writeResponse() {
        for (int i = 0; i < jobs.length; ++i) {
            out.println(assignedWorker[i] + " " + startTime[i]);
        }
    }

    class Worker {
        public Worker(int id, long nextFreeTime) {
            this.id = id;
            this.nextFreeTime = nextFreeTime;
        }

        public int id;
        public long nextFreeTime;
    }

    class WorkerComparator implements Comparator<Worker> {
        @Override
        public int compare(Worker o1, Worker o2) {
            if (o1.nextFreeTime > o2.nextFreeTime) {
                return 1;
            } else if (o1.nextFreeTime < o2.nextFreeTime) {
                return -1;
            } else {
                if (o1.id > o2.id) {
                    return 1;
                } else if (o1.id < o2.id) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }

    private void assignJobs() {
        // TODO: replace this code with a faster algorithm.
        assignedWorker = new int[jobs.length];
        startTime = new long[jobs.length];

        // a built-in priority queue implementation
        // with the comparator providing the min-heap functionality
        PriorityQueue<Worker> pq = new PriorityQueue<>(numWorkers, new WorkerComparator());

        // a current time counter to use when creating the new threads
        long currentTime = 0;

        // a best available thread
        Worker bestThread;

        for (int i = 0; i < jobs.length; i++) {
            int heapSize = pq.size();

            if (heapSize == numWorkers) {
                // new worker threads are not available; polling the queue
                bestThread = pq.poll();
            } else {
                // new worker threads are still available;
                // deciding whether to use one of them
                bestThread = pq.peek();

                if (bestThread == null) {
                    // creating a new worker thread because the queue is empty
                    bestThread = new Worker(heapSize, currentTime);
                } else if (bestThread.nextFreeTime > currentTime) {
                    // creating a new worker thread because the existing thread
                    // at the top of the queue is less optimal
                    bestThread = new Worker(heapSize, currentTime);
                } else {
                    // using an existing worker thread from the top of the queue
                    bestThread = pq.poll();
                }
            }

            // read the next free time of a best available thread
            long bestNextFreeTime = bestThread.nextFreeTime;

            // write down the output values
            assignedWorker[i] = bestThread.id;
            startTime[i] = bestNextFreeTime;

            // move the current time
            currentTime += bestNextFreeTime;

            // compute the next free time
            bestThread.nextFreeTime = bestNextFreeTime + jobs[i];

            // place the best available thread back into the queue
            pq.add(bestThread);
        }
    }

    // This is the best array-based implementation
    // of the min-heap queue I could come up with
    // in the time I had, and it still returns something like
    // "Failed case #9/28: time limit exceeded (Time used: 6.63/4.00".
    // Resorting to the built-in implementation of PriorityQueue<>.
    private void assignJobs_Array() {
        // TODO: replace this code with a faster algorithm.
        assignedWorker = new int[jobs.length];
        startTime = new long[jobs.length];

        if (numWorkers > jobs.length) {
            numWorkers = jobs.length;
        }

        // a min-heap of worker threads
        Worker[] workerHeap = new Worker[numWorkers];

        // a max index of a head element in a heap
        int maxHeapHead = numWorkers - 1;
        // an index of a head element in a heap
        int heapHead = maxHeapHead;

        // a current time counter to use when creating the new threads
        long currentTime = 0;

        // initialize the head of the heap
        workerHeap[heapHead] = new Worker(0, currentTime);

        // a best available thread
        Worker bestThread;

        for (int i = 0; i < jobs.length; i++) {
            if (heapHead == 0) {
                // new worker threads are not available;
                // using the thread at the top of the queue
                bestThread = workerHeap[0];
            } else {
                // new worker threads are still available;
                // deciding whether to use one of them

                if (workerHeap[heapHead].nextFreeTime > currentTime) {
                    // creating a new worker thread because the existing thread
                    // at the top of the queue is less optimal
                    heapHead--;
                    bestThread = new Worker(maxHeapHead - heapHead, currentTime);
                    workerHeap[heapHead] = bestThread;
                } else {
                    // using an existing worker thread from the top of the queue
                    bestThread = workerHeap[heapHead];
                }
            }

            // read the next free time of a best available thread
            long bestNextFreeTime = bestThread.nextFreeTime;

            // write down the output values
            assignedWorker[i] = bestThread.id;
            startTime[i] = bestNextFreeTime;

            // move the current time
            currentTime += bestNextFreeTime;

            // compute the next free time
            bestThread.nextFreeTime = bestNextFreeTime + jobs[i];

            // don't do SiftDown() if there is only one worker thread in the queue
            if (heapHead == maxHeapHead) {
                continue;
            }

            // rearrange the threads in the min-heap
            SiftDown(workerHeap, heapHead);
        }
    }

    private void SiftDown(Worker[] workerHeap, int heapHead) {
        int i = heapHead;

        while (true) {
            if (i == numWorkers - 1) {
                return;
            } else {
                // what follows is basically a code to compare two worker threads
                // interspersed with the code to swap two elements of the min-heap
                int i_id = workerHeap[i].id;
                long i_nextFreeTime = workerHeap[i].nextFreeTime;

                int i_next_id = workerHeap[i + 1].id;
                long i_next_nextFreeTime = workerHeap[i + 1].nextFreeTime;

                if (i_nextFreeTime > i_next_nextFreeTime) {
                    workerHeap[i].id = i_next_id;
                    workerHeap[i].nextFreeTime = i_next_nextFreeTime;

                    workerHeap[++i].id = i_id;
                    workerHeap[i].nextFreeTime = i_nextFreeTime;
                } else if (i_nextFreeTime < i_next_nextFreeTime) {
                    return;
                } else {
                    if (i_id > i_next_id) {
                        workerHeap[i].id = i_next_id;
                        workerHeap[i].nextFreeTime = i_next_nextFreeTime;

                        workerHeap[++i].id = i_id;
                        workerHeap[i].nextFreeTime = i_nextFreeTime;
                    } else {
                        return;
                    }
                }
            }
        }
    }

    public void solve() throws IOException {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        readData();
        assignJobs();
        writeResponse();
        out.close();
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