#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
using namespace std;

int main(){
int shmid;
int *array;
int count = 5;
int i = 0;
key_t key = 6166529;

shmid = shmget(key, count*sizeof(int), IPC_EXCL);

array = (int*)shmat(shmid, 0, SHM_RDONLY);

for(i=0; i<5; i++)
    {
        printf("\n%d---\n", array[i] );
    }

    printf("\nRead to memory succesful--\n");

    shmdt((void *) array);
    

    return 0;
}
