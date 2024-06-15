package mainPackage;
import geometry.circle;
import java.util.Scanner;

public class MainClass {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the radius of the circle: ");
        int x = scanner.nextInt();
        circle a = new circle(x);
        a.getRadius();
    }
}
