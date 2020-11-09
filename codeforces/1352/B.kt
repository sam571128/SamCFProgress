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
        var (a,b) = readInts()
        if(a < b){
            println("NO")
            continue
        }
        if(a%2==b%2){
            println("YES")
            for(i in b-1 downTo 1){
                print("${1} ")
            }
            print("${a-b+1} ")
        }else{
            if(a%2==1){
                println("NO")
                continue
            }
            if(a >= b*2){
                println("YES")
                for(i in b-1 downTo 1){
                    print("${2} ")
                }
                print("${a-2*(b-1)} ")
            }else{
                print("NO")
            }
        }
        println()
    }
}