# Socket programming in C

## Including header files

```c
<sys/socket.h>
<netinet/in.h>
```

- `man netinet_in.h` and `man sys_socket.h`.
- First of all we need to include following header files.
- `<sys/socket.h>` is used for defining __Internet Protocol Family__ related functions, structures and data types.
- One of those structures which will be used is `sockaddr` structure.
- `<netinet/in.h>` is used for defining __Internet Address family__ related structures and data types.
- One of those structures is `sockaddr_in` which we will be using in our program.

## Using syscalls and functions

### socket()

- `man 2 socket`
- `socket` syscall creates an endpoint of communication and returns a file descriptor that refers to this endpoint.
- On successful try, `socket` returns small unsigned integer, on failure it returns -1 and sets `errno` to indicate error.
- Definition for `socket` syscall is the following:

```c
int socket(int domain, int type, int protocol);
```

- `domain` specifies the domain of communication for the socket.
- These domain families are defined in `<sys/socket.h>` and `AF_INET` is for IPv4 family.
- `type` specifies the type of socket that will be used.
- For TCP socket we are going to use `SOCK_STREAM` (for UDP it's `SOCK_DGRAM`).
- `protocol` is the protocol that is going to be used with the socket.
    - Normally this is set to 0, because `type` of the socket already specified the protocol.

### bind()

- `man 2 bind`
- Function definitions goes like this:

```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

- `bind` syscall assigns a name to a socket.
- In other words it binds an address `addr` to a socket (`sockfd`) created using `socket` syscall.
- `addrlen` is number of bytes of a structure pointed to by `addr`.
- On success it returns 0, on failure it returns -1 and sets `errno` to indicate error.
- Our structure will be a `sockaddr_in` struct type, as shown below:

```c
struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    sturct in_addr sin_addr;
    char sin_zero[8];
} server_addr;
```

- `sin_family` member (accessed with `server_addr.sin_family`) will be set to `AF_INET`.
- `sin_port` will be our port number to listen on and it will be set like:

`server_addr.sin_port = htons(1337);`

- `htons` will convert our port number to network byte order which is necessary.
- `sin_addr` member is actually another struct with type `struct in_addr`, which contains only one member.

```c
struct in_addr {
    unsigned long s_addr;
};
```

- This member will be set to: `server_addr.sin_addr.in_addr = INADDR_ANY;`
- This means that our socket will be bound to any local interfaces.
- After setting up our structures and its members, you need to pass a pointer to this structure as:
`(struct sockaddr *) &server_addr` which will be our second argument to `bind`.
- Third and final argument to `bind` syscall is size of the structure `addr`.
- This is to be done with: `sizeof(server_addr)`


### listen()

- `man listen`
- Function definition:

```c
int listen(int socket, int backlog);
```

- `listen` function shall mark the socket for accepting incoming connections.
- First argument `socket` is the socket file descriptor.
- Second argument is number of connections that can wait in socket's listening queue.
    - It is usually set to 0.
- On success `listen` returns 0, on failure it returns -1 and sets `errno`.

### accept()

- Function definition:

```c
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

- `accept` function will extract the first connection and create a new identical socket (as one created with `socket` function).
- First argument `sockfd` is socket file descriptor created with `socket` syscall.
- Second argument is pointer to `sockaddr` structure where connecting socket shall be returned.
    - Most of the time this argument is set to `NULL` or 0.
- Third argument is a length of `sockaddr` structure.
    - When second argument is set to 0, this argument must be set to 0 also!
- On success this function returns new socket file descriptor which is unsigned integer.
- On failure it returns -1, and sets `errno` accordingly to error message.

### dup2()

- Function definition:

```c
int dup2(int oldfd, int newfd);
```

- This function duplicates old file descriptor to new file descriptor.
- Use of this function in our program will be to duplicate socket file descriptor (returned by `accept`) into `stdin`, `stdout` and `stderr`.


---

#### Resources

1. https://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html
2. https://github.com/h0mbre/Learning-C/tree/master/Assignment-26
