#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/hello_char.h"

int main()
{
		int fd, n;
			char str[100];
				unsigned long ptr;

					fd=open("./ach", O_RDWR);
						if(fd<0) {
									printf("Error open file\n");
											return(1);
												}
													ioctl(fd, IOCTL_GET_MSG, &ptr);

														n=read(fd, str, 80);
															str[n]='\0';
																printf("Message %d reads: %s\n", ptr, str);

																	ptr++;
																		if (ptr>3) ptr=1;
																			ioctl(fd, IOCTL_SET_MSG, ptr);
																				close(fd);
																					return 0;
}
