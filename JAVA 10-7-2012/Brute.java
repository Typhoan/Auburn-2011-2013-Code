   import java.util.Arrays;


 /**
 * Brute.java. Uses four for loops to check an array 
 * of Points for lines by comparing the slope of the Points.
 *
 * @author    Ian McPherson(irm0003@auburn.edu)
 * @version   2012-10-04
 *
 */
   public class Brute 
   {
      public static void main(String[] args)
      {
         Point[] points;
      
         points = setPoints(args[0]);
         Arrays.sort(points);
      
         for (int p = 0; p < points.length - 3; p++)
         {
            for (int q = p + 1; q < points.length - 2; q++)
            {
               for (int r = q + 1; r < points.length - 1; r++)
               {
                  for (int s = r + 1; s < points.length; s++)
                  {
                     if (points[p].slopeTo(points[q]) 
                     == (points[p].slopeTo(points[r])) 
                     && points[p].slopeTo(points[r]) 
                     == (points[p].slopeTo(points[s])))
                     {
                        System.out.println(points[p] + " -> " + points[q] + " -> " 
                        + points[r] + " -> " +  points[s]);
                        
                        if (args.length == 2)
                        {
                           StdDraw.setXscale(0, 32768);
                           StdDraw.setYscale(0, 32768);
                           points[p].draw();
                           points[q].draw();
                           points[r].draw();
                           points[s].draw();
                           points[p].drawTo(points[s]);
                        
                        }
                     }
                  }
               }
            }
         }
      
      
      }
   
   
      private static Point[] setPoints(String pathIn)
      {
         int[] num = In.readInts(pathIn);
         Point[] points = new Point[num[0]];
         int i = 0;
      
         for (int k = 1; k < num.length; k = k + 2)
         {
            Point g = new Point(num[k], num[k + 1]);
            points[i] = g;
            i++;
         }
      
         return points;
      }
   }