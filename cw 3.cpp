#include <iostream>
#include <cstring>
using namespace std;

void removeDupe (char fox[]) {
    int p = strlen(fox);
    /* The built-in function strlen(fox) gives the length of string 'fox'. */
    for (int sigma = 0; sigma < p-1; sigma++) {
        int eta = sigma + 1;
        while(eta < p) {
            int temp = 0;
            if (fox[sigma] == fox[eta]) {
                temp++;
                int phi = eta + 1;
                while (fox[phi] == fox[eta] && fox[phi]!='\0') {
                    temp++;
                    phi++;
                }
            }
            if (temp!=0) {
                for (int phi = eta; phi < p - temp; phi++)
                    fox[phi] = fox[phi + temp];
            }

            //fox[p = p - 1 - temp] = '\0';
            fox[p = p - temp] = '\0';
            //fox[p = p + 1 - temp] = '\0';

            eta++;
        }
    }
}

int main () {
    char D[] = "hello and welcome back"; /* Note: There is exactly one space between each word */
    removeDupe(D);
    cout << D;
    return 0;
}
