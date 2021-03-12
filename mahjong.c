#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void getHand(char* hand);
bool isChow(const char* hand);
bool isPung(const char* hand);
bool isKong(const char* hand);

int main() {
  char hand[20];

  getHand(hand);

  bool hasCombination = false;

  if (isChow(hand)) {
    printf("Chow!\n");
    hasCombination = true;
  }
  if (isPung(hand)) {
    printf("Pung!\n");
    hasCombination = true;
  }
  if (isKong(hand)) {
    printf("Kong!\n");
    hasCombination = true;
  }
  if (!hasCombination) {
    printf("No combination!\n");
  }
  return 0;
}

void getHand(char* hand) {
  printf("Enter a hand: ");

  scanf("%s", hand);
}

bool isPung(const char* hand) {
  for (int i = 1; i < strlen(hand) - 1; i++) {
    if (hand[i] == hand[i - 1] && hand[i] == hand[i + 1]) {
      return true;
    }
  }
  return false;
}

bool isKong(const char* hand) {
  for (int i = 1; i < strlen(hand) - 2; i++) {
    if (hand[i] == hand[i - 1] && hand[i] == hand[i + 1] &&
        hand[i] == hand[i + 2]) {
      return true;
    }
  }
  return false;
}

bool isChow(const char* hand) {
  for (int i = 0; i < strlen(hand) - 2; i++) {
    int n = 1;
    for (int j = i + 1; j < strlen(hand); j++) {
      if (hand[i] + n == hand[j]) {
        n++;
      }
      if (n == 3) {
        return true;
      }
    }
  }
  return false;
}
// 1271323