#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool valid(char f[]) {
    for (int i = 0; i < 8; i++)
          if (f[i] != '0' && f[i] != '1') return false;
    return true;
}

void receiveFrames(int count, bool handleError, bool ackLost, bool frameLost) {
    int received = 0;
    for (int i = 1; i <= count; i++) {
        char f[9]; // Increase size to prevent buffer issues
        while (1) {
            printf("Enter the value of frame %d:", i);
            scanf("%s", f);
            
            if (frameLost && strlen(f) <= 1) {
                printf("Frame %d is missing\nRe-Enter the Frame\n", i);
                continue;
            }
            if (!valid(f)) {
                printf("Nack%d-frame %d is in error\n", i, i);
                printf("Re-enter the value of frame %d\n", i);
                continue;
            }
            if (ackLost && i == count) {
                printf("Ack lost...\nRe-enter the frame %d:", i);
                scanf("%s", f);
            }
            printf("ack%d, frame %d is received\n", i, i);
            received++;
            break;
        }
    }
    if (received == count) printf("\nAll frames received successfully\n");
} 

int main() {
    int choice;
    printf("1:ERROR FREE CHANNEL\n2:FRAME WITH ERROR\n3:ACK IS LOST\n4:FRAME IS LOST\n");
    printf("Enter the choice:");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: receiveFrames(4, false, false, false); break;
        case 2: receiveFrames(4, true, false, false); break;
        case 3: receiveFrames(4, false, true, false); break;
        case 4: receiveFrames(4, false, false, true); break;
        default: printf("Invalid Choice\n");
    }
    return 0;
}
