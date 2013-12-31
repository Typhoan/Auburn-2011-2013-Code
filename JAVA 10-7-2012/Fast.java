   import java.util.Arrays;

   
 /**
 * Fast.java. Uses a Sort method to find and draw lines if 
 * the slope of the points are equal and there are four or
 * more points.
 *
 * @author    Ian McPherson(irm0003@auburn.edu)
 * @version   2012-10-04
 *
 */
   public class Fast 
   {
      public static void main(String[] args)
      {
         Point[] slopes; // Array of Points ordered by slope
         Point[] points; // Array of Points ordered by natural order
      
         points = setPoints(args[0]);
         Arrays.sort(points);
      
         for (int a = 0; a < points.length; a++)
         {
            slopes = points.clone();
            Point p = slopes[a];
            Arrays.sort(slopes, p.SLOPE_ORDER);
            int i = 0;
            while (i < slopes.length - 1)
            {
               if (p.slopeTo(slopes[i]) == p.slopeTo(slopes[i + 1]))
               {
                  int j = i + 1;
                  int numOfP = 3; // number of points found with same slope
                  while (j < slopes.length - 1)
                  {
                     if (p.slopeTo(slopes[i]) == p.slopeTo(slopes[j + 1]))
                     {
                        j++;
                        numOfP++;
                     }
                     else
                     {
                        if (numOfP > 3)
                        {
                           Point[] line = new Point[numOfP];
                           line[0] = p;
                           for (int k = 1; k < line.length; k++)
                           {
                              line[k] = slopes[i];
                              i++;
                           }
                           // Boolean variable to see if this line as been found
                           boolean isLine = true; 
                           int l = 0;
                           while (l < line.length - 1 && isLine)
                           {
                              if (line[l].compareTo(line[l + 1]) == 1)
                                 isLine = false;
                                 
                              l++;
                           }
                        
                           if (isLine) // If line is first time found then output
                           {
                              for (int k = 0; k < line.length - 1; k++)
                              {
                                 System.out.print(line[k] + " -> ");
                              }
                              System.out.println(line[line.length - 1]);
                           }
                           // draws plot if there is -v
                           if (isLine && args.length == 2) 
                           {
                              StdDraw.setXscale(0, 32768);
                              StdDraw.setYscale(0, 32768);
                              for (int k = 0; k < line.length; k++)
                              {
                                 line[k].draw();
                              }
                              line[0].drawTo(line[line.length - 1]);
                           }
                           
                           else
                              i = j;
                        }
                        j = slopes.length;
                     }
                  }
               }
               i++;
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