#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

#define BYTE 4096 
#define LEN 100

int func(const void *p, const void *q){
	return (*(long int*)p - *(long int*)q);
}

float print(long int arr[], int n)
{
    float med = 0;
    if(n%2 == 0){
    med = (arr[(n-1)/2] + arr[n/2])/2;
    }
    else{
    med = arr[n/2];
    }
    
    return med; 
}

int main(int argc, char *argv[]) {
    int K = atoi(argv[1]);
    //char file_name = (char *) malloc(LEN);
    if(K == 1) { // file creation mode 
        char* file_name = argv[2];
        printf("file name: %s\n", file_name);
        size_t file_size = atoi(argv[3]) * BYTE;
        printf("file size: %ld\n", file_size);
        //int creat(&file_name, mode_t mode);
        int file_des = open(file_name, O_CREAT | O_RDWR | O_TRUNC, S_IRWXG | S_IRWXU | S_IROTH);//O_CREAT = make new file if there isn't one, O_RDWR = read and write, O_TRUNC = truncate to 0 and set length to 0 if the file already exists, S_... are all permissions.
        
        char buff [file_size]; // sets buffer the size of the file
        memset(buff, 0, file_size); //fills buffer with 0s
        printf("buff 1 & 2: %d %d\n", buff[0], buff[1]);
        ssize_t f_write = write(file_des,buff, file_size);//writes buffer to file
        if(file_des == -1){
    	printf("file_des Error #: %d\n", file_des);
    	
    	}
    	if(f_write == -1){
    	printf("f_write Error #: %ld\n", f_write);
    	
    	}
    	int f = fsync(file_des);
    	if(f == -1){
    	printf("fsync Error #: %d\n", errno);
    	
    	}
    }
    
    if(K == 2){
    	struct timespec time; 
    	struct stat buf;

    	
        char* file_name = argv[2];
        size_t IO_size = atoi(argv[3]);
        int samples = atoi(argv[4]);
     	long int tim[samples];
     	      
        
        int file_des = open(file_name, O_RDWR);
        stat(file_name, &buf);
        int num = buf.st_size/BYTE;        
        
	int i = 0;
        while(i != samples){
        int rand = random() % num;
        off_t off = rand * BYTE;
       
        while(off + IO_size  > buf.st_size){
        	off -= 4096;
        }
        
        clock_gettime(CLOCK_MONOTONIC, &time);
        time_t curtime = time.tv_nsec * 1000; //microseconds
        
        int pos = lseek(file_des, off, SEEK_SET);
        char* buffer [IO_size];
        read(file_des, buffer, IO_size);
        
        
    
    	clock_gettime(CLOCK_MONOTONIC, &time);
        time_t endtime = time.tv_nsec * 1000; //microseconds
    	time_t total_time = endtime - curtime;
    	tim[i] = total_time;
    	i++;
    	}
    	
    	qsort(tim, samples, sizeof(long int), func);
    	float med = print(tim, samples);
    	printf("IO Latency Median: %0.2f\n", med);
    	
    }
    return 0;   
}
