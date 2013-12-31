/**
 * Point.java. An immutable data type for points in the plane.
 *
 * @author    Ian McPherson(irm0003@auburn.edu)
 * @version   2012-10-04
 *
 */

   import java.util.Comparator;
	
	
	
   public class Point implements Comparable<Point> {
   
    // compare points by slope
      public final Comparator<Point> SLOPE_ORDER = new slopeCompare();
   
      private final int x;    // x coordinate
      private final int y;    // y coordinate
   
    // create the point (x, y)
      public Point(int x, int y) {
        /* DO NOT MODIFY */
         this.x = x;
         this.y = y;
      }
   
    // plot this point to standard drawing
      public void draw() {
        /* DO NOT MODIFY */
         StdDraw.point(x, y);
      }
   
    // draw line between this point and that point to standard drawing
      public void drawTo(Point that) {
        /* DO NOT MODIFY */
         StdDraw.line(this.x, this.y, that.x, that.y);
      }
   
    // slope between this point and that point
      public double slopeTo(Point that) {
      	double slope = 1;
			if ((that.x == this.x) && (that.y == this.y))
			{
					return Double.NEGATIVE_INFINITY;
			}
			
			if (that.y == this.y)
			{
				return 0.0;
			}
			
			if (that.x == this.x)
			{
				return Double.POSITIVE_INFINITY;
			}
			
			return slope = (double)(that.y - this.y) / (that.x - this.x);
			
      }
   
    // is this point lexicographically smaller than that one?
    // comparing y-coordinates and breaking ties by x-coordinates
      public int compareTo(Point that) {
			
			int num = 2;
			
      	if (this.y < that.y)
				num = -1;
			
			if (this.y > that.y)
				num = 1;
				
			if (this.y == that.y && this.x < that.x)
				num = -1;
				
			if (this.y == that.y && this.x > that.x)
				num = 1;
				
			if (this.y == that.y && this.x == that.x)
				num = 0;
				
			return num;
			
      }
   
    // return string representation of this point
      public String toString() {
        /* DO NOT MODIFY */
         return "(" + x + ", " + y + ")";
      }
		
	public class slopeCompare implements Comparator<Point>
	{
		public int compare(Point p, Point q)
		{			
			double slopeOfP = slopeTo(p);
			double slopeOfQ = slopeTo(q);
			
			if (slopeOfP > slopeOfQ)
				return 1;
			
			if (slopeOfP == slopeOfQ)
				return 0;
					
			else
				return -1;
				
		}
	}
   
   }

	