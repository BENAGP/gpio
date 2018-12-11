#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/ioctl.h>
#include "../include/hello_char.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

char *string;
char sbuf[80];

char *msg1="This is an kernel module example string1!";
char *msg2="This is an kernel module example string2!";
char *msg3="This is an kernel module example string3!";

int hello_open(struct inode *node, struct file *filp)
{
		printk("Device is open\n");
			return 0;
}

int hello_close(struct inode *node, struct file *filp)
{
		printk("Device is closed\n");
			return 0;
}

ssize_t hello_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
		int len;
			len=MIN(strlen(string),length);
				if(*offset>=len) return 0; /* Important! */
						printk("Read data from kernelspace to userspace\n");
							copy_to_user(buffer, string, len);
								*offset+=len;
									return len;
}

ssize_t hello_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
		int len;
			string=sbuf;
				len=MIN(80,length);
					printk("Write data from userspace to kernelspace,%d\n",len);
						copy_from_user(string, buffer, len);
							printk("sbuf:%s\n",sbuf);
								*offset+=len;
									return len;
}

long hello_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
/*int hello_ioctl(struct inode *node, struct file *filp, unsigned int cmd, unsigned long arg)*/
{
		switch(cmd)
				{
							case IOCTL_SET_MSG:
										if (arg==1) string=msg1;
													if (arg==2) string=msg2;
																if (arg==3) string=msg3;
																			break;
																					case IOCTL_GET_MSG:
																								if (string==msg1) *(long *)arg=1;
																											if (string==msg2) *(long *)arg=2;
																														if (string==msg3) *(long *)arg=3;
																																default:
																																			break;
																																				}
																																					return 0;
}

int major;

struct file_operations fops={
	       open : hello_open,
		          release : hello_close,
				         read : hello_read,
						        write: hello_write,
								       unlocked_ioctl: hello_ioctl
									          /*ioctl: hello_ioctl*/
};


int init_module()
{
		string=msg1;
			major=register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
				if ( major>0 ) printk("\n\nMajor=%d\n", major);
					else if ( major < 0) {
								printk ("Can't register this module\n");
										unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
												return 1;
													}

														return 0;
}

void cleanup_module()
{
		string=msg1;
			unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Stanley Peng");
