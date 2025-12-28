#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Diski %c cubugundan %c cubuguna tasi\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, yardimci, hedef);
    printf("Diski %c cubugundan %c cubuguna tasi\n", kaynak, hedef);
    hanoi(n - 1, yardimci, hedef, kaynak);
}
int main() {
    int diskSayisi = 3;
    printf("%d disk icin adimlar:\n", diskSayisi);
    hanoi(diskSayisi, 'A', 'C', 'B');
    return 0;
}
