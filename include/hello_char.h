#define HELLO_DEBUG
#define DEVICE_NAME "hello_char"
#define MAJOR_NUM 240
#define IOCTL_SET_MSG _IOW(MAJOR_NUM, 0, int *)
#define IOCTL_GET_MSG _IOR(MAJOR_NUM, 1, int *)
#define IOCTL_DEBUG   _IOR(MAJOR_NUM, 2, char *)
