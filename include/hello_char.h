#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/ioctl.h>

#define HELLO_DEBUG
#define DEVICE_NAME "chrdev"
#define MAJOR_NUM 240
#define IOCTL_SET_MSG _IOW(MAJOR_NUM, 0, int *)
#define IOCTL_GET_MSG _IOR(MAJOR_NUM, 1, int *)
#define IOCTL_DEBUG   _IOR(MAJOR_NUM, 2, char *)
