/*
 * RGBConverter.h - Arduino library for converting between RGB, HSV and HSL
 * 
 * Ported from the Javascript at http://mjijackson.com/2008/02/rgb-to-hsl-and-rgb-to-hsv-color-model-conversion-algorithms-in-javascript
 * The hard work was Michael's, all the bugs are mine.
 *
 * Robert Atkins, December 2010 (ratkins_at_fastmail_dot_fm).
 *
 * https://github.com/ratkins/RGBConverter
 *
 */  
#ifndef RGBConverter_h
#define RGBConverter_h

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <Arduino.h>
#endif

class RGBConverter {

public:
    /**
     * Converts an RGB color value to HSL. Conversion formula
     * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
     * Assumes r, g, and b are contained in the set [0, 255] and
     * returns h, s, and l in the set [0, 1].
     *
     * @param   byte    r       The red color value
     * @param   byte    g       The green color value
     * @param   byte    b       The blue color value
     * @param   double  hsl[]   The HSL representation
     */
    void rgbToHsl(byte r, byte g, byte b, double hsl[]);
    
    /**
     * Converts an HSL color value to RGB. Conversion formula
     * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
     * Assumes h, s, and l are contained in the set [0, 1] and
     * returns r, g, and b in the set [0, 255].
     *
     * @param   double  h       The hue
     * @param   double  s       The saturation
     * @param   double  l       The lightness
     * @return  byte    rgb[]   The RGB representation
     */
    void hslToRgb(double h, double s, double l, byte rgb[]);

    /**
     * Converts an RGB color value to HSV. Conversion formula
     * adapted from http://en.wikipedia.org/wiki/HSV_color_space.
     * Assumes r, g, and b are contained in the set [0, 255] and
     * returns h, s, and v in the set [0, 1].
     *
     * @param   byte  r       The red color value
     * @param   byte  g       The green color value
     * @param   byte  b       The blue color value
     * @return  double hsv[]  The HSV representation
     */
    void rgbToHsv(byte r, byte g, byte b, double hsv[]);
    
    /**
     * Converts an HSV color value to RGB. Conversion formula
     * adapted from http://en.wikipedia.org/wiki/HSV_color_space.
     * Assumes h, s, and v are contained in the set [0, 1] and
     * returns r, g, and b in the set [0, 255].
     *
     * @param   double  h       The hue
     * @param   double  s       The saturation
     * @param   double  v       The value
     * @return  byte    rgb[]   The RGB representation
     */
    void hsvToRgb(double h, double s, double v, byte rgb[]);
     
private:
    double threeway_max(double a, double b, double c);
    double threeway_min(double a, double b, double c);
    double hue2rgb(double p, double q, double t);
};

#endif
