#include<stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec){
total_sec = total_sec % (60 * 60);
*hr = (int)(total_sec / (60 * 60));
*min = (int)(total_sec / 60);
*sec = (total_sec % 60);
}

int main(){
int n, hr, min, sec;
printf("Enter seconds: ");
scanf("%d", &n);
split_time(n, &hr, &min, &sec);
printf("Converted format: %d hour %d mins %d secs \n", hr, min, sec);
return 0;
}
