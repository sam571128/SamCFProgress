import java.lang.Math.pow
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
        var cnt = 1
        var a = ArrayList<Int>()
        while(n > 0){
            if(n%10!=0) a.add(n%10*cnt)
            n/=10
            cnt*=10
        }
        println(a.size)
        for(i in a) print("${i} ")
        println()
    }
}