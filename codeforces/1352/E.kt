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
        var arr = readInts()
        var cnt = IntArray(n+1)
        for(i in arr){
            cnt[i]++;
        }
        var ans = 0;
        for(i in 0 until n){
            var sum = arr[i];
            for(j in i+1 until n){
                sum += arr[j];
                if(sum <= n) {
                    ans += cnt[sum]
                    cnt[sum] = 0;
                }
            }
        }
        println(ans);
    }
}