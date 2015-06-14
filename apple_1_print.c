#include<stdio.h>
#include<stdint.h>
//#include<linux/spinlock.h>
//#include<linux/err.h>


/*
BYTE REPRESENTATION
_________________
|7|6|5|4|3|2|1|0|
__________________  
*/
#define BYTE(n)  			buf[n]
#define BIT(n) 				(1<<n)
#define BIT_MASK(len)	 		(BIT(len)-1)
#define GET_SET_BIT(n, start, len)      ((n >> start) & BIT_MASK(len))
#define MAX_MOUSE_RANGE 		( 512)
#define MIN_MOUSE_RANGE 		(-512)

struct mouse_struct {
	uint8_t  report_format;
	uint8_t  reserved;
	int16_t  x_pos;
	int16_t  y_pos;
	uint8_t  button_state;
	uint32_t timestamp;
};


struct mouse_struct mouse_packet;

static uint32_t get_timestamp(const uint8_t* buf)
{
	int ret  =(BYTE(6) << 10 | BYTE(5) << 2 | GET_SET_BIT(BYTE(4), 6, 2));
	printf("timestamp = %d\n", ret);
	return ret;
}

/* 
   ASSUMPTION: 10th bit of the delta receive if 1, then it
   is negative number and rest 9 bits represent its actual
   value. So max value of delta can be between -512 to 51
*/

static int16_t get_x_delta(const uint8_t* buf) {
	int16_t num = ((GET_SET_BIT(BYTE(4), 2, 2) << 8) | BYTE(2));
	
	/* check if it is negative number */
	if (num >> 9)
		num = (-1 * (num & BIT_MASK(10)));
	//else
	//	return num;
	printf("X delta: %d\n", num);
}

static int16_t get_y_delta(const uint8_t* buf) {
	int16_t num = ((GET_SET_BIT(BYTE(4), 4, 2) << 8) | BYTE(3));
	
	/* check if it is negative number */
	if (num >> 9)
		num = (-1 * (num & BIT_MASK(10)));
	//else
	//	return num;
	printf("y delta: %d\n", num);
}

static uint8_t get_button_state(const uint8_t* buf) {
	int ret  = GET_SET_BIT(BYTE(4), 0, 2);
	printf("button state: %d\n", ret);
return ret;
}

//static spinlock_t mouse_lock = SPIN_LOCK_UNLOCKED;


/* I am assuming that HandleReport function will be called from the
   interrupt context when device signal some event from mouse device
   and call corresponding interrupt handler.
   So i am holding spinlock while update data to protect these variable.
*/

/* considering length passed I this function is the length of the buffer */
static int HandleReport(uint8_t * buffer, uint16_t length)
{
	uint32_t timestamp   = get_timestamp(buffer);
	int16_t  x_delta     = get_x_delta(buffer);
	int16_t  y_delta     = get_y_delta(buffer);
	uint8_t button_state = get_button_state(buffer);

	/* length of buffer should not be less than 7 */
	if (length < 7)
		//return -EIO;
		return -5;
	
	/* take spin lock */
	//spin_lock(&mouse_lock);


	/* Update fields if detect any change in position or button state */
	if(x_delta || y_delta || (mouse_packet.button_state != button_state))
	{
		/* update x pos */
		mouse_packet.x_pos 	  += x_delta;

		/* Check for negative and positive boundaries */
		if (mouse_packet.x_pos > MAX_MOUSE_RANGE)
			 mouse_packet.x_pos = MAX_MOUSE_RANGE;
		else if (mouse_packet.x_pos < MIN_MOUSE_RANGE)	
			 mouse_packet.x_pos = MIN_MOUSE_RANGE;

		/* update Y pos */
		mouse_packet.y_pos 	  += y_delta;

		/* Check for negative and positive boundaries */
		if (mouse_packet.y_pos > MAX_MOUSE_RANGE)
			 mouse_packet.y_pos = MAX_MOUSE_RANGE;
		else if (mouse_packet.y_pos < MIN_MOUSE_RANGE)	
			 mouse_packet.y_pos = MIN_MOUSE_RANGE;

		mouse_packet.button_state  = button_state;
	}

	/* Update timestamp irrespective of any change in mouse data */
	if (mouse_packet.timestamp > timestamp)
		/* timestamp rollover, so handle and update it */
		mouse_packet.timestamp += timestamp;
	else
		mouse_packet.timestamp  = timestamp;
	
	//spin_unlock(&mouse_lock);
	return 0;
}

int main()
{
	uint8_t buffer[7] = {0, 0, 2, 2, 235, 255, 255};
	HandleReport(buffer, 7);	
	return 0;
}

