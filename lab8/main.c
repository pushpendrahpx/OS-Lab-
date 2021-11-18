/*

Wait(S)
{
    while (i <= 0) 
    --S;
}
  
  
Signal(S)
{
    S++;
}

Process P             Process Q
Semaphore S           Semaphore T
1                     1

while(1){             while(1){}
  
P(s) // Wait(S)       P(T) // Wait of T
print("00");          print("11");
V(T) // Signal(T)       V(S) // Signal (S)
s

}                     }

Before critical section, there should be wait 



And After Critical Section there should be signal
*/


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int times = 6;
int S = 1; int T = 0;


void Wait(int *i){
  while((*i) <= 0);
  (*i)--;
}
void Signal(int *i){
  (*i) = (*i) + 1;
}



void *thread1function(void *vargp){

  while(times > 0){

    // P(S)
    times--;


    
    Wait(&S);

    printf("00");
    Signal(&T);


  }

}


void *thread2function(void *vargp){

  while(times > 0){


    times--;

    Wait(&T);
    printf("11");
    Signal(&S);



  }

}





int main(){

  pthread_t thread1,thread2;
  pthread_create(&thread1, NULL, thread1function, (void *)&thread1);

  pthread_create(&thread2, NULL, thread2function, (void *)&thread2);

  
  pthread_exit(NULL);
  return 0;
}