#ifndef __TINYDRAW_IMAGE_H__
#define __TINYDRAW_IMAGE_H__

#include <stdint.h>

typedef uint16_t tinydraw_color_t;

#define RGB888_TO_RGB555(r,g,b)     (((((uint16_t)r) & 0b11111000) << 7) | ((((uint16_t)g) & 0b11111000) << 2) | (((uint16_t)b) >> 3))

#define BLACK_COLOR             0x0000
#define WHITE_COLOR             0xFFFF
#define RED_COLOR               0xF800
#define GREEN_COLOR             0x87E0
#define BLUE_COLOR              0x801F
#define CYAN_COLOR              0x87FF
#define YELLOW_COLOR            0xFFE0
#define PURPLE_COLOR            0xF81F
#define LIGHT_GREY_COLOR        (0x8000 | RGB888_TO_RGB555(168, 168, 168))
#define DARK_GREY_COLOR         (0x8000 | RGB888_TO_RGB555(96, 96, 96))


#define DEFALT_BG_COLOR         BLACK_COLOR
#define DEFALT_BRUSH_COLOR      WHITE_COLOR

typedef struct {
    uint32_t x;
    uint32_t y;
} tinydraw_point_t;

typedef struct {
    uint32_t x0;
    uint32_t y0;
    uint32_t x1;
    uint32_t y1;
} tinydraw_rect_t;


typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *buffer;
    unsigned sz_buffer;
    uint8_t bits_per_px;
    tinydraw_rect_t screen_bond;
    tinydraw_point_t cur;

    tinydraw_color_t color_bg;
    tinydraw_color_t color_brush;

    tinydraw_color_t font_draw_colors[4];
} tinydraw_renderer_ctx_t;

void tinydraw_renderer_ctx_init(tinydraw_renderer_ctx_t* ctx, uint32_t width, uint32_t height, uint8_t bits_per_px);
void tinydraw_renderer_ctx_done(tinydraw_renderer_ctx_t* ctx);

void tinydraw_renderer_save_bmp(tinydraw_renderer_ctx_t* ctx, const char* filename);

void tinydraw_renderer_clear_screen(tinydraw_renderer_ctx_t* ctx);
void tinydraw_renderer_draw_pixel(tinydraw_renderer_ctx_t* ctx, uint16_t x, uint16_t y, tinydraw_color_t color);

#endif // __TINYDRAW_IMAGE_H__

