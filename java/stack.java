public class Stack<T> {
    private int maxSize;
    private int top;
    private Object[] stackArray;

    public Stack(int size) {
        this.maxSize = size;
        this.stackArray = new Object[maxSize];
        this.top = -1;
    }

    public void push(T value) {
        if (isFull()) {
            System.out.println("Stack is full, cannot push " + value);
            return;
        }
        stackArray[++top] = value;
    }

    public T pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty, cannot pop");
            return null;
        }
        return (T) stackArray[top--];
    }

    @SuppressWarnings("unchecked")
    public T peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty, cannot peek");
            return null;
        }
        return (T) stackArray[top];
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    // Check if the stack is full
    public boolean isFull() {
        return (top == maxSize - 1);
    }

    public int size() {
        return top + 1;
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        
        System.out.println("Top element: " + stack.peek());
        System.out.println("Popped element: " + stack.pop());
        System.out.println("Stack size: " + stack.size());
    }
}
