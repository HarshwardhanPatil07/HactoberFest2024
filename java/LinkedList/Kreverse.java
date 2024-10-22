
// GitHub: https://github.com/harshu84190
// Aim: Implement k-reverse in a LinkedList
// Date: October 21, 2024

public class Kreverse {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static class LinkList {
        Node head, tail;

        public void addLast(int data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        public void display() {
            Node tmp = head;
            while (tmp != null) {
                System.out.print(tmp.data + " ");
                tmp = tmp.next;
            }
            System.out.println();
        }

        public int size() {
            Node tmp = head;
            int size = 0;
            while (tmp != null) {
                size++;
                tmp = tmp.next;
            }
            return size;
        }

        public void kReverse(int k) {
            int size = size();
            if (size < k || k < 2) {
                return;
            }
            Node tmp = head;
            Node curr = null, tailcurr = null;
            Node ans = null, tailAns = null;
        
            while (tmp != null && size >= k) {
                curr = null;
                tailcurr = null;
                int idx = 0;
                while (tmp != null && idx < k) {
                    Node next = tmp.next;
                    if (curr == null) {
                        curr = tailcurr = tmp;
                        tailcurr.next = null;
                    } else {
                        tmp.next = curr;
                        curr = tmp;
                    }
                    tmp = next;
                    idx++;
                }
                size -= k;
                if (ans == null) {
                    ans = curr;
                    tailAns = tailcurr;
                } else {
                    tailAns.next = curr;
                    tailAns = tailcurr;
                }
            }
            tailAns.next = tmp;
            head = ans;
        }
        
    }

    public static void main(String[] args) {
        LinkList ll = new LinkList();
        ll.addLast(1);
        ll.addLast(10);
        ll.addLast(2);
        ll.addLast(3);
        ll.addLast(30);
        ll.addLast(41);
        ll.addLast(20);
        ll.addLast(32);

        System.out.println("Original List:");
        ll.display();

        ll.kReverse(3);
        ll.display();
    }
}

/*
Overview:
The k-reverse problem involves reversing the linked list in groups of 'k' nodes at a time. 
If the number of remaining nodes is less than 'k', they are left as is.

Input:
Original List: 1 10 2 3 30 41 20 32

Output:
After k = 3 Reverse: 2 10 1 41 30 3 20 32

Explanation:
The linked list is reversed in groups of 3. The first group {1, 10, 2} becomes {2, 10, 1}, 
the second group {3, 30, 41} becomes {41, 30, 3}, and the remaining two nodes {20, 32} stay the same.
*/
