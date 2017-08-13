obj-m := plat_button.o  
CROSS_COMPILE ?= /opt/buildroot-2012.08/arm920t/usr/bin/arm-linux-
ARCH=arm

KERNEL_DIR := /home/yangni/fl2440/kernel/linux-3.0.54  
PWD := $(shell pwd)  
all:  
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules  
clean:  
	rm *.o *.mod.c *.symvers *.order
  
.PHONY:clean  
