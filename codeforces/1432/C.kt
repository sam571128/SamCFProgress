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
    var t = readInt();
    while(t-- > 0){
        var n = readInt();
        var arr = readInts();
        var sum = 0;
        for(i in arr) sum += i;
        if(sum%arr.size>0){
            println(sum/arr.size+1);
        }else{
            println(sum/arr.size);
        }
    }
}