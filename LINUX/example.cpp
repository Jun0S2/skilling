#include <iostream>
#include <fstream>
#include <cstring>
#include <json/json.h>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <limits.h>

#define MAX_EVENTS 10

int main() {
    // path
    const char* monitor_path = "/sys/kernel/example"; // mechanism to monitor the specified path for new files

    // NONBLOCK -> EDGE EVENT
    int inotify_fd = inotify_init1(IN_NONBLOCK);
    if (inotify_fd == -1) {
        std::cerr << "Failed to initialize inotify." << std::endl;
        return 1;
    }

    int wd = inotify_add_watch(inotify_fd, monitor_path, IN_CREATE);
    if (wd == -1) {
        std::cerr << "Failed to add watch." << std::endl;
        close(inotify_fd);
        return 1;
    }

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        std::cerr << "Failed to create epoll instance." << std::endl;
        close(inotify_fd);
        return 1;
    }

    epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = inotify_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, inotify_fd, &event) == -1) {
        std::cerr << "Failed to add inotify file descriptor to epoll." << std::endl;
        close(inotify_fd);
        close(epoll_fd);
        return 1;
    }

    epoll_event events[MAX_EVENTS];

    while (true) {
        int num_ready = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_ready == -1) {
            std::cerr << "epoll_wait failed." << std::endl;
            break;
        }

        for (int i = 0; i < num_ready; ++i) {
            if (events[i].data.fd == inotify_fd) {
                char buffer[sizeof(inotify_event) + NAME_MAX + 1] = {};
                ssize_t len = read(inotify_fd, buffer, sizeof(buffer));
                if (len == -1) {
                    std::cerr << "Error reading inotify event." << std::endl;
                    break;
                }

                inotify_event* event = reinterpret_cast<inotify_event*>(buffer);
                if (event->mask & IN_CREATE) {
                    std::string filename = event->name;
                    std::string filepath = std::string(monitor_path) + "/" + filename;

                    // Read the file
                    std::ifstream file(filepath);
                    if (!file.is_open()) {
                        std::cerr << "Failed to open file: " << filepath << std::endl;
                        continue;
                    }

                    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    file.close();
                  
                    // print the file content before parsing
                    std::cout << "File Content:\n" << content << std::endl;

                    // Remove the file
                    if (remove(filepath.c_str()) != 0) {
                        std::cerr << "Failed to remove file: " << filepath << std::endl;
                    } else {
                        std::cout << "File processed and removed: " << filepath << std::endl;
                    }

            
                }
            }
        }
    }

    // Cleanup
    close(inotify_fd);
    close(epoll_fd);
    return 0;
}
