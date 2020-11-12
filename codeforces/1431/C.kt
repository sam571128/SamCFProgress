import java.util.*
import kotlin.collections.ArrayDeque

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

fun main(args: Array<String>){
    var t = readInt();
    while(t-- > 0){
        var (n,k) = readInts(2);
        var arr = readInts(n);
        var v = ArrayDeque<Int>(); var sum = 0; var ans = 0;
        for(i in n-1 downTo 0){
            sum += arr[i];
            v.addLast(arr[i]);
            while(v.size > (n-i)/k){
                sum -= v[0];
                v.removeFirst();
            }
            ans = maxOf(ans,sum);
        }
        println(ans);
    }
}