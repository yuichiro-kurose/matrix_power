#include <iostream>

const int MOD = 1000000007;

int main() {
  long long n;
  std::cin >> n;
  long long dpD0 = 1;
  long long dpABC0 = 0;
  for (long long i = 0; i < n; i++) {
    long long dpD1 = dpABC0 * 3 % MOD;
    long long dpABC1 = (dpABC0 * 2 + dpD0) % MOD;
    dpD0 = dpD1;
    dpABC0 = dpABC1;
  }
  std::cout << dpD0 << std::endl;
  return 0;
}
