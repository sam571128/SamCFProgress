import java.util.*
import kotlin.math.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of string
private fun readInts() = readStrings().map { it.toInt() } // list of int
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of double
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)
fun gcd(a: Long, b: Long) : Long = if (b == 0L) a else gcd(b,a%b)
val INF = 0x3f3f3f3f
val MOD = 1e9+7

fun main() {
    var t = readInt()
    while(t-- > 0){
        var n = readInt()
        var a = ArrayDeque<Int>()
        a.addAll(readInts())
        var ans1 = 0; var ans2 = 0
        var sum1 = 0; var sum2 = 0; var cnt = 0;
        while(a.size > 0){
            sum1 = 0
            while(sum1 <= sum2){
                if(a.size == 0) break
                sum1 += a.first()
                ans1 += a.first()
                a.removeFirst()
            }
            sum2 = 0
            cnt++
            if(a.size == 0) break
            while(sum2 <= sum1){
                if(a.size == 0) break
                sum2 += a.last()
                ans2 += a.last()
                a.removeLast()
            }
            cnt++
            if(a.size == 0) break
        }
        println("${cnt} ${ans1} ${ans2}")
    }
}