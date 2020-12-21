#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
 
template <uint32_t Modulus>
struct modular {
  static_assert(int(Modulus) > 0, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static modular raw(uint32_t _v) {
    modular res;
    res.v = _v;
    return res;
  }
 
  modular() : v(0) {}
  modular(int64_t x) : v(x % Modulus) {
    if (int(v) < 0) v += Modulus;
  }
 
  template <class T>
  explicit operator T() const {
    return v;
  }
  modular& operator++() {
    ++v;
    if (v == Modulus) v = 0;
    return *this;
  }
  modular& operator--() {
    if (v == 0) v = Modulus;
    --v;
    return *this;
  }
  modular operator+() const { return *this; }
  modular operator-() const {
    modular res;
    res.v = v ? Modulus - v : 0;
    return res;
  }
  modular& operator*=(modular b) {
    v = uint64_t(v) * b.v % Modulus;
    return *this;
  }
  modular& operator/=(modular b) {
    auto [x, gcd] = extgcd(b.v, Modulus);
    assert(gcd == 1);
    return *this *= x;
  }
  modular& operator+=(modular b) {
    v += b.v - Modulus;
    if (int(v) < 0) v += Modulus;
    return *this;
  }
  modular& operator-=(modular b) {
    v -= b.v;
    if (int(v) < 0) v += Modulus;
    return *this;
  }
 
  friend modular operator++(modular& a, int) {
    return std::exchange(a, ++modular(a));
  }
  friend modular operator--(modular& a, int) {
    return std::exchange(a, --modular(a));
  }
  friend modular operator*(modular a, modular b) { return a *= b; }
  friend modular operator/(modular a, modular b) { return a /= b; }
  friend modular operator+(modular a, modular b) { return a += b; }
  friend modular operator-(modular a, modular b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, modular& b) {
    int64_t x;
    return is >> x, b = x, is;
  }
  friend std::ostream& operator<<(std::ostream& os, modular b) {
    return os << b.v;
  }
  friend bool operator==(modular a, modular b) { return a.v == b.v; }
  friend bool operator!=(modular a, modular b) { return a.v != b.v; }
 
 private:
  static std::pair<int, int> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }
 
  uint32_t v;
};

template <typename num>
std::vector<num> BerlekampMassey(const std::vector<num>& s) {
  int n = int(s.size()), L = 0, m = 0;
  std::vector<num> C(n), B(n), T;
  C[0] = B[0] = 1;

  num b = 1;
  for(int i = 0; i < n; i++) { ++m;
    num d = s[i];
    for (int j = 1; j <= L; j++) d += C[j] * s[i - j];
    if (d == 0) continue;
    T = C; num coef = d / b;
    for (int j = m; j < n; j++) C[j] -= coef * B[j - m];
    if (2 * L > i) continue;
    L = i + 1 - L; B = T; b = d; m = 0;
  }

  C.resize(L + 1); C.erase(C.begin());
  for (auto& x : C) {
    x = -x;
  }
  return C;
}

template <typename num>
num linearRec(const std::vector<num>& S, const std::vector<num>& tr, long long k) {
  int n = int(tr.size());
  assert(S.size() >= tr.size());

  auto combine = [&](std::vector<num> a, std::vector<num> b) {
    std::vector<num> res(n * 2 + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) res[i + j] += a[i] * b[j];
    for (int i = 2 * n; i > n; --i) for (int j = 0; j < n; j++)
      res[i - 1 - j] += res[i] * tr[j];
    res.resize(n + 1);
    return res;
  };

  std::vector<num> pol(n + 1), e(pol);
  pol[0] = e[1] = 1;

  for (++k; k; k /= 2) {
    if (k % 2) pol = combine(pol, e);
    e = combine(e, e);
  }

  num res = 0;
  for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
  return res;
}

const int MOD = 1e9+7;
signed main(){
  fastio
  using mint = modular<MOD>;
  ll n,m;
  cin >> n >> m;
  vector<mint> dp(m,1);
  for(int i = m;i <= 2*m;i++){
    dp.push_back(dp[i-1] + dp[i-m]);
  }
  cout << linearRec(dp,BerlekampMassey(dp),n) << "\n";
}