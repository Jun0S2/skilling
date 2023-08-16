# EPOLL

## Intro.
While there's a fatal error occurs on the hardware side, it is hard to recognize what happened and when it actually happened. Thus, we are trying to send all the fatal failures to server and gather them up. 
How can we implement this ? - These error records will be stored in by BSP side, however, BSP cannot actually send these to server. Indeed, framework will get this information from kernel and send it via using other app's api.

## How to monitor calls ?
* select
* poll
* epoll
  - epoll is specific to Linux.
  - `#include <sys/epoll.h>`
  - faster!!!
 
## EPOLL
anymeow, so what i'm trying to acheive is
1. Access certain directory
2. Monitor if there's any changes
3. If there is any changes - sends callback to app side

### Edge Triggered vs. Level Trigger
- Edge Trigger : Triggered only when modifications are made
- Level Trigger : Keep monitoring

### APIs
1. epoll_create
  ```c++
  #include <sys/epoll.h>
  int32_t epoll_create1(int flag);
  ```
2. epoll_ctl
   ```c++
   int32_t epoll_ctl(int epollfd, int option, int fd, struct epoll_event *event);
   ```
3. epoll_wait
   ```c++
   int epoll_wait(int epollfd, struct epoll_event *event, int maxevents, int timeout);
   ```
