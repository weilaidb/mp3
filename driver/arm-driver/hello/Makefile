.PHONY:all clean
ifneq ($(KERNELRELEASE),)

obj-m := hello.o  #rename

else
		
EXTRA_CFLAGS += -DDEBUG 
#KDIR := /home/linux-4.4.76
KDIR := /home/linux
all:
		make  CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm -C $(KDIR) M=$(PWD) modules
clean:
		rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .*.ko .tmp_versions

endif
