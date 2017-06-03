#ifdef __cplusplus
extern "C"
{
#endif
/* ioctl magic numbers */
#define GPIO_IOCTL_BASE		'G'

/* inputs */
#define GPIO_CONFIG_AS_INP	_IO  (GPIO_IOCTL_BASE, 0)	/* config this pin as input */
#define GPIO_READ_PIN_VAL	_IOR (GPIO_IOCTL_BASE, 1, int)	/* read pin value */

/* outputs */
#define GPIO_CONFIG_AS_OUT	_IO  (GPIO_IOCTL_BASE, 2)	/* config this pin as output */
#define GPIO_WRITE_PIN_VAL	_IOW (GPIO_IOCTL_BASE, 3, int)	/* sets the pin value */

#define GPIO_IOCTL_MAXNR	3

int key_Available();
int key_Get();
void *keypad_Thread();
#ifdef __cplusplus
}


#endif /* __DIGI_GPIO_H_ */
