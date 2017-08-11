#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


struct ring_buffer 
{
	u_char *buffer;
    int wr_pointer;
    int rd_pointer;
    int size;
};

typedef struct ring_buffer my_buffer;

int rb_free_size(my_buffer *rb);
int rb_data_size(my_buffer *rb);
u_char rb_peek(my_buffer* rb, int index);


void rb_init (my_buffer *ring, u_char* buff, int size) 
{
    memset (ring, 0, sizeof (struct ring_buffer));
    ring->rd_pointer = 0;
    ring->wr_pointer = 0;
    ring->buffer= buff;
    ring->size = size;
}

int rb_write (my_buffer *rb, u_char * buf, int len)
{
    int total;
    int i;

    /* total = len = min(space, len) */
    total = rb_free_size(rb);
    if(len > total)
        len = total;
    else
        total = len;

    i = rb->wr_pointer;
    if(i + len > rb->size)
    {
        memcpy(rb->buffer + i, buf, rb->size - i);
        buf += rb->size - i;
        len -= rb->size - i;
        i = 0;
    }
    memcpy(rb->buffer + i, buf, len);
    rb->wr_pointer = i + len;
    return total;
}

int rb_free_size (my_buffer *rb){
    return (rb->size - 1 - rb_data_size(rb));
}

int rb_read (my_buffer *rb, u_char * buf, int max) {
    int total;
    int i;
    /* total = len = min(used, len) */
    total = rb_data_size(rb);

    if(max > total)
        max = total;
    else
        total = max;

    i = rb->rd_pointer;
    if(i + max > rb->size)
    {
        memcpy(buf, rb->buffer + i, rb->size - i);
        buf += rb->size - i;
        max -= rb->size - i;
        i = 0;
    }
    memcpy(buf, rb->buffer + i, max);
    rb->rd_pointer = i + max;

    return total;
}

int rb_data_size (my_buffer *rb) {
    return ((rb->wr_pointer - rb->rd_pointer) % (rb->size-1));
}

void rb_clear (my_buffer *rb) {
    memset(rb->buffer,0,rb->size);
    rb->rd_pointer=0;
    rb->wr_pointer=0;
}

u_char rb_peek(my_buffer* rb, int index) 
{
	assert(index < rb_data_size(rb));

	return rb->buffer[((rb->rd_pointer + index) % rb->size)];
}

int main()
{
    my_buffer *ring=(my_buffer *)malloc(sizeof(my_buffer));
    u_char a[11]="abcdefgh2";
    u_char buff[12]={0};
    u_char mybuff[12]={0};
    
    rb_init (ring, buff, sizeof(buff));
    printf("%d\t\t",sizeof(buff));

    int w_res = rb_write (ring, a, 4);
    
  //  printf("%s\n",ring->buffer);
  //  printf("%d\n",ring->wr_pointer);    
  //  printf("%d\n",ring->rd_pointer);    
  //  printf("%d\n",rb_free_size(ring));
  //  printf("%d \t",rb_data_size(ring));
    
    int r_res = rb_read (ring, mybuff, 3);

    
    printf("%d \t %d\n",w_res,r_res);
    printf("%s\n",mybuff);
    
    return 0;

}
