#include <iostream>
#include <array>

using mat = std::array<std::array<long long, 2>, 2>;
const int MOD = 1000000007;

mat mul(mat A, mat B) {
  mat C{};
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < 2; j++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
      }
    }
  }
  return C;
}

mat pow(mat A, long long n) {
  mat B{{{1, 0}, {0, 1}}};
  while (n > 0) {
    if (n & 1) {
      B = mul(B, A);
    }
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int main() {
  long long n;
  std::cin >> n;
  mat A{{{0, 3}, {1, 2}}};
  A = pow(A, n);
  std::cout << A[0][0] << std::endl;
  return 0;
}
