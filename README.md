# cub3d
This project is inspired by the world-famous **Wolfenstein 3D** game. The objective of this project is to create a simple 3D game using ray casting method. Read **cub3d.pdf** file to understand the task. 

Use **make** command to compile source files. To run the program use `./cub3D <map_name>` command line in the root of repository. For example `./cub3D maps/cub1.cub` 

This project is developed for **Linux**. **MiniLibX** for Linux requires ***xorg***, ***x11*** and ***zlib***, therefore you will need to install the following dependencies: ***xorg***, ***libxext-dev*** and ***zlib1g-dev***. Installing these dependencies on Ubuntu can be done as follows:  
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
```  
Now all thats left is to configure MLX, just run the `configure` script in the root of the `mlx_linux` folder, and you are good to go.
For more information about **MiniLibX** please refer to https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
