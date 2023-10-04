package DSA_JAVA;

public class ArrayStack {

    Object[] a;
    int size;

    public ArrayStack(int length) {
        a = new Object[length];
    }

    public void push(Object object) {
        if (size == a.length) {
            // Resize method here!
            Object[] arr = new Object[a.length * 2];
            for (int i = 0; i < a.length; i++) {
                arr[i] = a[i];
            }
            a = arr;
        }
        a[size++] = object;
    }

    public Object pop() {
        if (size == 0) throw new IllegalStateException("Stack is Empty");
        
        return a[--size];
    }

    public Object peek() {
        if (size == 0) throw new IllegalStateException("Stack is Empty");
        return a[size - 1];
    }
    
    public boolean deleteSpecific(Object object){
        for(int i = 0; i < size; i++){
            if(a[i].equals(object)){
                if(i == size-1){
                    a[--size] = null;
                    return true;
                } else{
                    Object temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
        }
        return false;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return (size == 0);
    }
    
    public boolean contains(Object object){
        if(a[0].equals(object)) return true;
        for(int i =0; i < size; i++)
            if(a[i].equals(object))
                return true;
        return false;
    }
    
    //Reverses the stack on which method is executed.
    public void reverse(){
        int breakOut = 0;
        for (int i = 0; i < size; i++) {
            if(breakOut == size/2) break;
            int y = i+1;
            Object temp = a[i];
            a[i] = a[size-y];
            a[size-y] = temp;
            breakOut++;
        }
    }
    
    public void printOnly(){
        int loopingNumber = size-1;
        for (int i = loopingNumber; i >= 0; i--) {
            System.out.print(a[i] + " ");
        }
    }
    
    public String[] toArray(){
        String[] arr = new String[size];
        int index = 0;
        for(int i = size-1; i >= 0; i--){
            arr[index++] = a[i].toString();
        }
        return arr;
    }
    
    public void bottomElement(Object object){
        for (int i = size; i >= 0; i--) {
            if(i==0){ a[i] = object; break;}
            a[i] = a[i-1];
        }
        size++;
    }
    
    public boolean isEqual(ArrayStack stack){
        if(size != stack.size()) return false;
        for(int i = size-1; i >= 0; i--){
            if(a[i] != stack.a[i])
                return false;
        }
        return true;
    }
    @Override
    public String toString(){
        if(isEmpty()) return "[]";
        StringBuffer buff = new StringBuffer("[" + a[0]);
        for (int i = 1; i < size; i++) {
            buff.append(", ").append(a[i]);
        }
        return (buff + "]");
    }
    
    public LinkedList toLinkedList(){
        LinkedList list = new LinkedList();
        int z = size;
        int d = z;
        for (int i = 0; i < z; i++) {
            list.insert(a[--d]);
        }
        return list;
    }
    
    public static void main(String[] args) {
        ArrayStack stack = new ArrayStack(10);
        stack.push(1);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push("Zohaib");
        System.out.println("Deleted: " + stack.deleteSpecific(4));
        
        stack.bottomElement(7);
        
        //Checking for Equality
//        ArrayStack stack2 = new ArrayStack(5);
//        stack2.push(1);
//        stack2.push(3);
//        stack2.push(4);
//        stack2.push(5);
//        stack2.push("Zohaib");
//        System.out.println(stack.isEqual(stack2));

        System.out.println("Contains: " + stack.contains(1));
        System.out.println("to String: " + stack.toString());
        
        //Stack to Array
//        String[] arr = stack.toArray();
//        for (int i = 0; i < arr.length; i++) {
//            System.out.println(arr[i]);
//        }

        //To linkedList
//        LinkedList list = stack.toLinkedList();
//        Node p = list.start;
//        for (int i = 0; i < list.size(); i++) {
//            System.out.println(p.data);
//            p = p.next;
//        }
        
        stack.printOnly();
//        while(!stack.isEmpty())
//            System.out.println(stack.pop());
    }
}
