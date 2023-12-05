#include <stdio.h>
#include <time.h>

char* timestr(struct tm t, char* time) {
    sprintf(time, "%02d:%02d:%02d", t.tm_hour, t.tm_min, t.tm_sec);
    return time;
}

int main() {
    time_t now = time(NULL);
    struct tm t = *localtime(&now);
    char timestr_buffer[9];
    printf("Current time: %s\n", timestr(t, timestr_buffer));
    return 0;
}