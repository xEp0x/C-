#include <iostream>
#include <sstream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ostringstream output;

  std::vector<bool> missing(26, true);

  std::string input;
  std::cin >> input;
  for (char ch : input) {
    missing[int(ch) - 97] = false;
  }

  for (int i = 0; i < 26; i++) {
    if (missing[i]) {
      output << char(i + 97);
    }
  }
  std::cout << output.str() << std::endl;

  return 0;
}
