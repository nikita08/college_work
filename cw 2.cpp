
#include<cstdio>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct employee {
    int id;
    long int netsal;
};

void update_emp_database () {
    struct employee a[2];
    int rec_size = sizeof(struct employee);
    FILE *fp = fopen("empdbase","rb");
    FILE *flptr = fopen("temp","wb");
    if (fp == NULL) {
        cout << "Error opening file!";
        return;
    }
    if (flptr == NULL) {
        cout << "Error opening file!";
        return;
    }
    int i = 0;
    while (true) {
        i++;
        fread(&a,rec_size,2,fp);
        if(feof(fp))
            break;
        if (a[0].netsal > 30000) {
            a[0].netsal += 5000;
        }
        if (a[1].netsal <= 30000) {
            a[1].netsal += 3000;
        }
        if (i%2)
            fwrite(&a[++i % 2],rec_size,1,flptr);
    }
    fclose(fp);
    fclose(flptr);
    remove("empdbase");
    rename("temp","empdbase");
}

int main () {
    struct employee f[6] = {{1,38000},{2,45000},{3,30000},{4,35000},{5,32000},{6,12000}};
    struct employee c;
    int rsize = sizeof(struct employee);
    FILE *f_ptr;
    f_ptr = fopen("empdbase","wb");
    if (f_ptr == NULL) {
        cout << "Error in opening file!";
        return -1;
    }
    for (int i = 0; i < 6; i++) {
        fwrite(&f[i],rsize,1,f_ptr);
    }
    fclose(f_ptr);
    update_emp_database();
    f_ptr = fopen("empdbase","rb");
    if (f_ptr == NULL) {
        cout << "Error in opening file!";
        return -1;
    }
    long int s = 0;
    while(true) {
        fread(&c,rsize,1,f_ptr);
        if(feof(f_ptr))
            break;
        s = s + c.netsal;
    }
    fclose(f_ptr);
    cout << s;
    return 0;
}
