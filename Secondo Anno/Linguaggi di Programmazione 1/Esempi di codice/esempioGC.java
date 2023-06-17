public class Employee {
    private String name;
    private Employee boss;
    
    // ...

    public static void main(...) {
        Employee a = new Employee("Pippo", null);
        f();
        // Caso 2: GC qui
        System.out.println(a);
    }

    public static void f() {
        Employee a = new Employee("Elon", null),
            b = new Employee("Mike", a),
            c = new Employee("Jennifer", a);
        ArrayList<Employee> l = new ArrayList<>();
        l.add(a);
        l.add(b);
        l.add(c);
        a = null;
        b = null;
        // Caso 1: Supponiamo che avvenga GC qui
    }
}
