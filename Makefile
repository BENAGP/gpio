KSRC = /home/student/linux-4.9
PWD  = $(shell pwd)

obj-m = hello_char.o

default:
		$(MAKE) -C $(KSRC) SUBDIRS=$(PWD) modules
clean:
		$(MAKE) -C $(KSRC) SUBDIRS=$(PWD) clean
