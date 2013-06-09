import java.io._
import scala.math._

object F {
  if (util.Properties.userName != "watashi") {
    scala.Console.setIn(
      new BufferedInputStream(new FileInputStream("positive.in")))
    scala.Console.setOut(
      new PrintStream(new FileOutputStream("positive.out")))
  }

  def main(args: Array[String]) {
    val n = readLine().toInt
    val a = readLine().split(" ").map(_.toInt)
    println(max(0, a.sum))
  }
}

