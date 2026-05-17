#include <stdio.h>

// Function to check if a page exists in frames
int is_exist(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page)
            return i; // Return position if page found
    }
    return -1; // Page not found
}

int main() {
    int n, frame, pagefault = 0;
    int pointer = 0;

    printf("Enter the total number of pages: ");
    scanf("%d", &n);

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    int page[n], frames[frame], reference[frame];

    printf("Enter the page numbers (separated by space): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    // Initialize all frames and reference bits
    for (int i = 0; i < frame; i++) {
        frames[i] = -1;
        reference[i] = 0;
    }

    printf("\nSecond Chance Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        int pos = is_exist(frames, frame, page[i]);

        if (pos != -1) {
            // Page hit: give second chance
            reference[pos] = 1;
        } else {
            // Page fault: find a frame with reference bit 0
            while (reference[pointer] == 1) {
                reference[pointer] = 0;
                pointer = (pointer + 1) % frame;
            }
            // Replace the page
            frames[pointer] = page[i];
            reference[pointer] = 0;
            pointer = (pointer + 1) % frame;
            pagefault++;
        }

        // Display frames
        printf("After inserting page %d: ", page[i]);
        for (int j = 0; j < frame; j++) {
            if (frames[j] == -1)
                printf("[ ] ");
            else
                printf("[%d] ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pagefault);

    return 0;
}
