import java.util._
import scala.math._

object Main {
    val in = new Scanner(System.in)

    def main(args: Array[String]) {
        val a = in.nextInt()
        val n = in.nextInt()
        val b = a + n
        val x = Array.fill[Long](b)(1)
        for (i <- 1 to sqrt(b).toInt) {
            val ii = i * i
            for (j <- 0 until b by ii) {
                x(j) = ii
            }
        }
        println(x.zipWithIndex.drop(a).map{ case (x, y) => y / x }.sum)
    }
}

// vim: set ts=4 sw=4 et:
