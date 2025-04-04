#include <stdio.h>
#include <string.h>

void enterFrames(int start, int end, char frame[][10]) {
    for (int i = start; i <= end; i++) {
        printf("enter the value of frame %d:", i);
        scanf("%s", frame[i]);
    }
}

void discardFrames(int start, int end) {
    for (int i = start; i <= end; i++)
        printf("frame %d is discarded by the reciever node\n", i);
}

void reEnterFrames(int start, int end, char frame[][10]) {
    for (int i = start; i <= end; i++) {
        printf("re-enter the value of frame %d:", i);
        scanf("%s", frame[i]);
    }
}

int main() {
    char frame[10][10];
    int ch;

    printf("1:damaged frame\n2:lost frame\n3:lost acknowledgment\nenter your choice:");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            enterFrames(0, 2, frame);
            printf("ACK3:frame 0, frame 1, frame 2\trecieved sucessfully\n");

            enterFrames(3, 3, frame);
            for (int j = 0; j < 8; j++) {
                if (frame[3][j] != '0' && frame[3][j] != '1') {
                    printf("NAK 3: error in frame 3\n");
                    break;
                }
            }

            enterFrames(4, 5, frame);
            discardFrames(4, 5);
            reEnterFrames(3, 5, frame);
            printf("frame0 ,frame1 ,frame2 ,frame3, frame4 ,frame 5 revieved sucessfully by reciever node\n");
            break;

        case 2:
            enterFrames(0, 3, frame);
            printf("frame 3 is discarded by the reciever node\n");
            printf("NAK 2:frame 2 not recieved properly\n");

            enterFrames(4, 4, frame);
            discardFrames(4, 4);
            reEnterFrames(2, 4, frame);
            printf("frame0 ,frame1 ,frame2 ,frame3, frame4 revieved sucessfully by reciever node\n");
            break;

        case 3:
            enterFrames(0, 2, frame);
            printf("ACK3: genetated after recieving 3 frame is lost\n");
            printf("sender node waiting time is expired(time out) .... \n");

            reEnterFrames(0, 3, frame);
            printf("frame0 ,frame1 ,frame2 ,frame3 revieved sucessfully by reciever node\n");
            break;
    }
    return 0;
}
