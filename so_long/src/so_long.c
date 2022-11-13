//#include "./../include/so_long.h"

#include <stdio.h>
#include <mlx.h>

int main(void)
{
    void *mlx_ptr = mlx_init();

    if (!mlx_ptr)
        return puts("mlx_ptr");

    void *win_ptr = mlx_new_window(mlx_ptr, 200, 200, "Sharon");

    if (!win_ptr)
        return puts("win_ptr");

    mlx_loop(mlx_ptr);
}