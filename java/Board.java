import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

class LinkedListNode {
    Node data;
    LinkedListNode next;

    LinkedListNode(Node data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    LinkedListNode head;

    public void add(Node data) {
        LinkedListNode newNode = new LinkedListNode(data);
        if (head == null) {
            head = newNode;
        } else {
            LinkedListNode current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public boolean contains(Node node) {
        LinkedListNode current = head;
        while (current != null) {
            if (current.data.equals(node)) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    public Node remove() {
        if (head == null) {
            return null;
        }
        LinkedListNode temp = head;
        head = head.next;
        return temp.data;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public ArrayList<String[]> getMatrixLines() {
        ArrayList<String[]> lines = new ArrayList<>();
        LinkedListNode current = head;
        while (current != null) {
            String[] line = new String[3];
            Node matrix = current.data;
            for (int i = 0; i < 3; i++) {
                line[i] = Arrays.toString(matrix.data[i]).replaceAll("[\\[\\],]", "");
            }
            lines.add(line);
            current = current.next;
        }
        return lines;
    }
}

class Node {
    int[][] data;
    Node parent;
    int g;
    double h;
    double f;

    public Node(int[][] data, Node parent) {
        this.data = data;
        this.parent = parent;
        this.g = (parent == null) ? 0 : parent.g + 1;
        this.h = calculateHeuristic();
        this.f = this.g + this.h;
    }

    public double calculateHeuristic() {
        // Euclidean Distance Heuristic
        int[][] goal = {
            {1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}
        };
        double distance = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int value = this.data[i][j];
                int goalRow = (value == 0) ? 1 : (value - 1) / 3;
                int goalCol = (value == 0) ? 1 : (value - 1) % 3;
                distance += Math.pow(i - goalRow, 2) + Math.pow(j - goalCol, 2);
            }
        }
        return Math.sqrt(distance);
    }

    public LinkedList generateChildren() {
        int[] blankPos = findBlank();
        int x = blankPos[0];
        int y = blankPos[1];

        int[][] moves = {{x, y - 1}, {x, y + 1}, {x - 1, y}, {x + 1, y}};
        LinkedList children = new LinkedList();

        for (int[] move : moves) {
            int newX = move[0];
            int newY = move[1];
            if (isValidMove(newX, newY)) {
                int[][] childData = copyAndSwap(x, y, newX, newY);
                children.add(new Node(childData, this));
            }
        }
        return children;
    }

    private boolean isValidMove(int x, int y) {
        return x >= 0 && x < 3 && y >= 0 && y < 3;
    }

    private int[][] copyAndSwap(int x1, int y1, int x2, int y2) {
        int[][] newData = new int[3][3];
        for (int i = 0; i < 3; i++) {
            newData[i] = Arrays.copyOf(this.data[i], 3);
        }
        int temp = newData[x1][y1];
        newData[x1][y1] = newData[x2][y2];
        newData[x2][y2] = temp;
        return newData;
    }

    private int[] findBlank() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (this.data[i][j] == 0) {
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Node other = (Node) obj;
        return Arrays.deepEquals(this.data, other.data);
    }

    @Override
    public int hashCode() {
        return Arrays.deepHashCode(data);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int[] row : data) {
            sb.append(Arrays.toString(row).replaceAll("[\\[\\],]", "")).append("\n");
        }
        return sb.toString();
    }
}

class Puzzle {
    LinkedList open;
    LinkedList closed;
    int[][] goal;

    public Puzzle() {
        open = new LinkedList();
        closed = new LinkedList();
        goal = new int[][]{
            {1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}
        };
    }

    public int[][] accept() {
        int[][] puz = new int[3][3];
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the start state matrix (space separated):");
        for (int i = 0; i < 3; i++) {
            String[] temp = scanner.nextLine().split(" ");
            for (int j = 0; j < 3; j++) {
                puz[i][j] = Integer.parseInt(temp[j]);
            }
        }
        return puz;
    }

    public void process() {
        int[][] start = accept();
        Node startNode = new Node(start, null);
        open.add(startNode);

        while (!open.isEmpty()) {
            // Print OPEN and CLOSED lists in a single row format
            System.out.println("\nOPEN and CLOSED:");
            printListsSideBySide(open, closed);

            Node current = open.remove();
            System.out.println("\nExpanding node with heuristic value: " + current.h);
            System.out.println(current);

            if (Arrays.deepEquals(current.data, goal)) {
                System.out.println("Goal reached!");
                printSolutionPath(current);
                return;
            }

            closed.add(current);

            LinkedList children = current.generateChildren();
            LinkedListNode childNode = children.head;

            while (childNode != null) {
                Node child = childNode.data;
                if (!closed.contains(child) && !open.contains(child)) {
                    open.add(child);
                }
                childNode = childNode.next;
            }
        }

        System.out.println("No solution found.");
    }

    private void printListsSideBySide(LinkedList openList, LinkedList closedList) {
        ArrayList<String[]> openLines = openList.getMatrixLines();
        ArrayList<String[]> closedLines = closedList.getMatrixLines();

        int maxSize = Math.max(openLines.size(), closedLines.size());
        for (int i = 0; i < maxSize; i++) {
            String[] openLine = (i < openLines.size()) ? openLines.get(i) : new String[]{"", "", ""};
            String[] closedLine = (i < closedLines.size()) ? closedLines.get(i) : new String[]{"", "", ""};

            for (int j = 0; j < 3; j++) {
                System.out.printf("%-20s | %-20s%n", openLine[j], closedLine[j]);
            }
            System.out.println();
        }
    }

    private void printSolutionPath(Node node) {
        if (node == null) return;
        printSolutionPath(node.parent);
        System.out.println("Node in path:");
        System.out.println(node);
    }

    public static void main(String[] args) {
        Puzzle puz = new Puzzle();
        puz.process();
    }
}
