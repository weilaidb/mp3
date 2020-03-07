#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


/*
 *argc:应用程序参数个数
 *argv[]:具体的参数内容，字符串形式 
 *./chrdevbaseAPP  <filename>  <1:2> 1表示读，2表示写
 * ./chrdevbaseAPP /dev/chrdevbase 1    表示从驱动里面读数据
 * ./chrdevbaseAPP /dev/chrdevbase 2    表示向驱动里面写数据
 * */
int main(int argc, char *argv[])
{
    int ret = 0;
    int fd = 0;
    char *filename;
    char readbuf[100], writebuf[100];
    static char usrdata[] = {"usr data!"};

    if(argc < 3) {
        printf("Error usage!./chrdevbaseAPP  <filename>  <1> 1表示读\r\n");
        printf("            ./chrdevbaseAPP  <filename>  <2> <write data>2表示写\r\n");
        return -1;
    }

    filename = argv[1];

    fd = open(filename, O_RDWR);
    if(fd < 0 ) {
        printf("Can't open file %s\r\n", filename);
        return -1;
    }

    if(atoi(argv[2]) == 1){ /*  读 */
        /* read */
        ret = read(fd, readbuf, 50);
        if (ret < 0) {
            printf("read file %s failed!\r\n", filename);
        }
        else {
            printf("APP read data:%s\r\n", readbuf);
        }
    }

    /* write */
    if(atoi(argv[2]) == 2) { /* 写 */ 
        char *pwdata = argv[3];
        if(pwdata == NULL)
        {
            perror("null write data error");
            return -1;
        }
        int len = strlen(argv[3]);
        int maxlen = sizeof(writebuf);
        len = len > maxlen ? maxlen :len;
        memcpy(writebuf, argv[3],(len));
        ret = write(fd, writebuf, len);
        if (ret < 0) {
            printf("write file %s failed!\r\n", filename);
        }
        else {
        //    printf("write date ok, len:%u, actulen:%u\n", len, ret);
        }
    }

    /* close */
    ret = close(fd);
    if(ret < 0) {
        printf("close file %s falied!\r\n", filename);
    }

    return 0 ;

}
