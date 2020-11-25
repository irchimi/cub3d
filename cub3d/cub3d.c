#include <mlx.h>
#include "cub3d.h"
#include "types.h"

int main(int count, char *params[])
{
    if (valid_start_data(count, params) == -1)
    {
        printf("%s\n",  "error");
        exit(1);
    }
    return (0);
}