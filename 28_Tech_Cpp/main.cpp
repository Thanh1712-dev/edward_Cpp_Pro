#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int a) {
    if (a <= 1) return false; // Các số <= 1 không phải là số nguyên tố
    if (a == 2) return true;  // 2 là số nguyên tố duy nhất chẵn
    if (a % 2 == 0) return false; // Các số chẵn khác 2 không phải là số nguyên tố
    int sqrt_a = static_cast<int>(sqrt(a)); // Tính căn bậc hai của a
    for (int i = 3; i <= sqrt_a; i += 2) { // Duyệt từ 3 đến căn bậc hai của a, chỉ kiểm tra số lẻ
        if (a % i == 0) {
            return false; // Nếu a chia hết cho i thì không phải là số nguyên tố
        }
    }
    return true; // Nếu không tìm thấy ước số nào, a là số nguyên tố
}

int main() {
  int N;
  cin >> N;
  int arr[N];
  for (int z = 0; z < N; ++z) {
    cin >> arr[z];
  }
  for (int i = 0; i < N; ++i) {
    int sum1 = 0;
    int sum2 = 0;
    for (int j = 0; j < i; ++j) {
      sum1 += arr[j];
    }
    for (int j = N - 1; j > i; --j) {
      sum2 += arr[j];
    }
    if (isPrime(sum1) && isPrime(sum2)) {
      cout << i << ' ';
    }
    sum1 = 0;
    sum2 = 0;
  }
  return 0;
}