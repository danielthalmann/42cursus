
### void *memset(void *s, int c, size_t n);

memset - fill memory with a constant byte

### int printf(const char *format, ...);

write format string to stdout

### void *malloc(size_t size);

allocates size bytes and returns a pointer to the allocated memory

### void free(void *ptr); 

frees the memory space pointed to by ptr

### ssize_t write(int fd, const void *buf, size_t count);

writes up to count bytes from the buffer starting at buf to the file referred to
by the file descriptor fd.

### int usleep(useconds_t usec);

suspends execution of the calling thread for (at least) usec microseconds

### int gettimeofday(struct timeval *tv, struct timezone *tz);

gets the system’s clock time. The current time is expressed in elapsed seconds
and microseconds since 00:00:00, January 1, 1970 (Unix Epoch).

### int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

function starts a new thread in the calling process

### int pthread_detach(pthread_t thread);

marks the thread identified by thread as detached. When a detached thread 
terminates, its resources are automatically released back to the system without
the need for another thread to join with the terminated thread.

### int pthread_join(pthread_t thread, void **retval);

waits for the thread specified by thread to terminate.  If that thread has
already terminated, then pthread_join() returns immediately.

### int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

initialises the mutex referenced by mutex with attributes specified by attr. 
If attr is NULL, the default mutex attributes are used.

### int pthread_mutex_destroy(pthread_mutex_t *mutex);

destroys the mutex object referenced by mutex;

### int pthread_mutex_lock(pthread_mutex_t *mutex);

The mutex object referenced by mutex is locked by calling pthread_mutex_lock().
If the mutex is already locked, the calling thread blocks until the mutex 
becomes available.
The function pthread_mutex_trylock() is identical to pthread_mutex_lock() except
that if the mutex object referenced by mutex is currently locked (by any thread,
including the current thread), the call returns immediately. 

### int pthread_mutex_unlock(pthread_mutex_t *mutex);

The pthread_mutex_unlock() function releases the mutex object referenced by 
mutex. The manner in which a mutex is released is dependent upon the mutex's
type attribute.

https://franckh.developpez.com/tutoriels/posix/pthreads/