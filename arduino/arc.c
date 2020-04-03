// LCD TFT display with standard library for displaying graphics
//

int value = 50;     // 0..100
int color = 0xFA04;
fillArc(80, 60, 210, value, 50, 50, 10, color);

/**
 * fillArc - Draw a circular or elliptical arc with a defined thickness
 * 
 * fillArc(80, 60, 210, 100, 50, 50, 10, 25);
 * 
 * x -  X Coord of centre of arc
 * y - Y Coord of centre of arc
 * start_angle - Start Angle [0-359]
 * seg_count - Number of 3 degree segments to draw [120 => 360 degree arc]
 * rx - X axis radius
 * ry - Y axis radius
 * w - Width (thickness) of arc in pixels
 * color 16 bit color value
 */
int fillArc(int x, int y, int start_angle, int seg_count, int rx, int ry, int w, unsigned int color) {
    byte seg = 3; // Segments are 3 degrees wide = 120 segments for 360 degrees
    byte inc = 3; // Draw segments every 3 degrees, increase to 6 for segmented ring
    // Calculate first pair of coordinates for segment start
    float sx = cos((start_angle - 90) * DEG2RAD);
    float sy = sin((start_angle - 90) * DEG2RAD);
    uint16_t x0 = sx * (rx - w) + x;
    uint16_t y0 = sy * (ry - w) + y;
    uint16_t x1 = sx * rx + x;
    uint16_t y1 = sy * ry + y;
    // Draw color blocks every inc degrees
    for (int i = start_angle; i < start_angle + seg * seg_count; i += inc) {
        // Calculate pair of coordinates for segment end
        float sx2 = cos((i + seg - 90) * DEG2RAD);
        float sy2 = sin((i + seg - 90) * DEG2RAD);
        int x2 = sx2 * (rx - w) + x;
        int y2 = sy2 * (ry - w) + y;
        int x3 = sx2 * rx + x;
        int y3 = sy2 * ry + y;
        display.fillTriangle(x0, y0, x1, y1, x2, y2, color);
        display.fillTriangle(x1, y1, x2, y2, x3, y3, color);
        // Copy segment end to sgement start for next segment
        x0 = x2;
        y0 = y2;
        x1 = x3;
        y1 = y3;
    }
} /**/
