package geometry;

public class circle {
    int radius;

    public circle(int radius){
        this.radius = radius;
    }

    public int getRadius(){
        return radius;
    }


    public circle(circle c){
        this.radius = c.getRadius();
    }

    public static void enlarge(circle c, double dr){
        c.radius += dr;
    }

    
}
