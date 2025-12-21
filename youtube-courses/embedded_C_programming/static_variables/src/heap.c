#include <stddef.h>
#include <stdint.h>

/* Linker symbols */
extern uint8_t __heap_start__;
extern uint8_t __heap_end__;

static uint8_t *heap_cur;

static inline uintptr_t align8(uintptr_t p)
{
    return (p + 7u) & ~7u;
}

void *_sbrk(ptrdiff_t incr)
{
    if (heap_cur == NULL)
        heap_cur = &__heap_start__;

    uint8_t *prev = heap_cur;
    uint8_t *next = (uint8_t *)align8((uintptr_t)(heap_cur + incr));

    if (next > &__heap_end__) {
        return (void *)-1;
    }

    heap_cur = next;
    return prev;
}

void *malloc(size_t size)
{
    if (size == 0)
        return NULL;

    size = align8(size);

    void *p = _sbrk((ptrdiff_t)size);
    if (p == (void *)-1)
        return NULL;

    return p;
}

void free(void *ptr)
{
    (void)ptr;
}
