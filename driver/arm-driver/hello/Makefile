.PHONY:all clean
ifneq ($(KERNELRELEASE),)

#no using here 
#obj-m := hello.o  #rename

else
		
EXTRA_CFLAGS += -DDEBUG 
#KDIR := /home/linux-4.4.76
KDIR := /home/linux
all:help
		make  CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm -C $(KDIR) M=$(PWD) modules
clean:
		rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .*.ko .tmp_versions

endif


help:
	@echo =======help begin ===========
	@echo obj-m is $(obj-m)
	@echo KDIR is $(KDIR)
	@echo KERNELRELEASE is $(KERNELRELEASE)
	@echo =======help end ===========

