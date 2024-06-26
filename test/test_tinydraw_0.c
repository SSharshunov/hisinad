#include <tinydraw/image.h>

int main(int argc, char** argv)
{
    tinydraw_renderer_ctx_t td_ctx;
    tinydraw_renderer_ctx_init(&td_ctx, 10, 10, 16);

    for (unsigned x = 0; x < 5; ++x)
        for (unsigned y = 0; y < 5; ++y) tinydraw_renderer_draw_pixel(&td_ctx, x, y, RED_COLOR);

    for (unsigned x = 0; x < 5; ++x)
        for (unsigned y = 5; y < 10; ++y) tinydraw_renderer_draw_pixel(&td_ctx, x, y, GREEN_COLOR);

    for (unsigned x = 8; x < 10; ++x)
        for (unsigned y = 3; y < 7; ++y) tinydraw_renderer_draw_pixel(&td_ctx, x, y, BLUE_COLOR);

    tinydraw_renderer_save_bmp(&td_ctx, "test.bmp");
    tinydraw_renderer_ctx_done(&td_ctx);

    return 0;
}

