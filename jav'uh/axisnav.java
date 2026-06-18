import java.io.*;
import java.math.BigDecimal;
import java.util.*;
import java.util.function.*;

public class axisnav {
    public static void main(String[] args) throws FileNotFoundException {
   
        Scanner sc = new Scanner(System.in);
        Scanner sc2 = new Scanner(sc.nextLine());
        for(int i = 0; i < 6; i++) sc2.next();
        Coords here = new Coords(sc2.nextDouble(), sc2.nextDouble(), sc2.nextDouble(), sc2.nextDouble());
       

        sc2 = new Scanner(sc.nextLine());
        for(int i = 0; i < 6; i++) sc2.next();
        Coords there = new Coords(sc2.nextDouble(), sc2.nextDouble(), sc2.nextDouble(), sc2.nextDouble());
        System.out.println(here.toString() + " " + there.toString());
        //we also could just use slopes.
        //apparently tangent is slope and i never realized this.
        //take the tangent of both angles
        //let our coords be (x = a, y = b, angle = c) and (x = d, y = e, angle = f)
        //so for some x, tan(c) * (x - a) + b = tan(f) * (x - d) + e
        //tan(c) * x - tan(f) * x = tan(f) * (-d) + tan(c) * a - b + e
        //x = (tan(f) * (-d) + tan(c) * a - b + e) / (tan(c) - tan(f))

       
        double z = (Math.tan(there.d * Math.PI / 180) * (there.z) + Math.tan(here.d * Math.PI / 180) * -here.z - here.x + there.x)
        / (Math.tan(here.d * Math.PI / 180) - Math.tan(there.d * Math.PI / 180));
        double x = Math.tan(here.d * Math.PI / 180) * (z + here.z) + here.x;


        double dist = Math.hypot(here.x - x, here.z + z); //in general, here is closer to the nether portal.
        System.out.printf("dist: %.2f blocks\n", dist);
       
        System.out.printf("Nether blind at %d %d - %d %d", (int) (x / 8), (int) (-z / 8), (int) x, (int) -z);
    }
    record Coords (double x, double y, double z, double d) {
        Coords {
            d = ((d % 360) + 360) % 360;
        }
    }
}

/*

/execute in minecraft:overworld run tp @s 156.28 73.00 454.95 -2918.97 -32.27
/execute in minecraft:overworld run tp @s 130.67 66.00 475.72 -2920.30 -32.53

 */
