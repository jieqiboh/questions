#include "string"
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string s;
  char c;
  while (scanf("%c", &c) != EOF) {
    s = c + s;
  }

  std::cout << s;

  return 0;
}
