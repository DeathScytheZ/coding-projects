import geometry.circle;

public class Tp2 {
    public static void main(String[] args){
        circle c = new circle(4);
        circle f = new circle(c);
        System.out.println("c = " + c.getRadius());
        System.out.println("f = " + f.getRadius());
        circle.enlarge(c, 4);
        circle.enlarge(f,1);
        System.out.println("c = " + c.getRadius());
        System.out.println("f = " + f.getRadius());
    }

}