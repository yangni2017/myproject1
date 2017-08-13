obj-m := led.o  
KERNEL_DIR := /home/yangni/fl2440/kernel/linux-3.0.54  
PWD := $(shell pwd)  
all:  
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules  
clean:  
	rm *.o *.ko *.mod.c  
  
.PHONY:clean  
