#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string res;
  char s[100];

  while (scanf(" %[^\n]", s) != EOF) {
    res += s;
  }
  std::cout << "Thank you, " << res << ", and farewell!";

  return 0;
}
