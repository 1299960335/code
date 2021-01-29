#include"proh.h"
void proh()
{
  char arr[size];
  memset(arr,'\0',sizeof(arr));
  int i=0;
  while(i<100)
  {
    arr[i++]='#';
    sleep(1);
    fflush(stdout);
   printf("[%-100s][%3d%%]\r",arr,i);
  }
  printf("\n");
}
