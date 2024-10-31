/* Roll#24k-0001 Name:Masoom Khan Assignment:2 Q10
 * This program generates a star pattern based on a user-specified odd value N.
 * The star is composed of lines connecting points arranged in a pentagonal shape.
 * The length of each side and the position of the center adapt based on N.
 *
 * For a chosen size N:
 *   - The top vertex of the star is positioned at (width/2, 0).
 *   - The center of the pattern is approximately at (width/2, height/2).
 *   - Width and height scale according to N for an aspect ratio of 5:2.
 */
#include <stdio.h>
int main() {
    int size, asx = 5, asy = 2;
    
    // Prompt user to enter an odd value for N
    printf("Enter an odd value for N: ");
    scanf("%d", &size);

    // Ensure N is odd and handle invalid input
    if (size % 2 == 0) {
        printf("Please enter an odd number for N.\n");
        return 1;
    }

    // Calculate width and height based on aspect ratio and size
    int width = size * asx / asy - 1;
    int height = size;

    // Define vertices of the star
    int verts[5][2] = {
        { width / 2, 0 },                  // Top
        { width / 8, height - 1 },         // Bottom-left
        { width - 1, height * 3 / 8 },     // Right
        { 0, height * 3 / 8 },             // Left
        { width - 1 - width / 8, height - 1 } // Bottom-right
    };

    // Generate the star pattern row by row
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int left_count = 0;
            
            // Check if (x, y) is inside the star
            for (int v = 0; v < 5; v++) {
                int vx = verts[(v + 1) % 5][0] - verts[v][0];
                int vy = verts[(v + 1) % 5][1] - verts[v][1];
                int dx = x - verts[v][0];
                int dy = y - verts[v][1];
                int cross = vx * dy - vy * dx;
                if (cross <= 0) left_count++;
            }
            
            // Print '*' if the point is inside the star; otherwise, print a space
            putchar(left_count >= 4 ? '*' : ' ');
        }
        putchar('\n'); // Move to the next line after each row
    }

    return 0;
}
