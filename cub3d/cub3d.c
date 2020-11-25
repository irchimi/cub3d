#include <mlx.h>
#include "cub3d.h"
#include "types.h"

int main(int count, char *params[])
{
    if (valid_start_data(count, params) == -1)
        return (error_start_data());

    return (0);
}