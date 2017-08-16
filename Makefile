NAME = bomberman

CC = clang++
CCFLAGS = -Wall -Wextra -Werror -std=c++11

SRC_FOLDER = src
INCLUDE_FOLDER = include
LIB_FOLDER = lib

SRC = $(wildcard $(SRC_FOLDER)/*.cpp)
INCLUDE = $(wildcard $(INCLUDE_FOLDER)/*.hpp)

GLEW_LIB = -I $(LIB_FOLDER)/glew/include/GL -L $(LIB_FOLDER)/glew/lib/ -lglew
GLFW_LIB = -I $(LIB_FOLDER)/glfw/include/GLFW -L $(LIB_FOLDER)/glfw/lib/ -lglfw
SDL_LIB = -I $(LIB_FOLDER)/sdl2/include/SDL2 -L $(LIB_FOLDER)/sdl2/lib/ -lSDL2
SDL_MIXER_LIB = -I $(LIB_FOLDER)/sdl2_mixer/include/SDL2 -L $(LIB_FOLDER)/sdl2_mixer/lib/ -lSDL2_mixer

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@$(CC) $(CCFLAGS) -o $(NAME) $(SRC) -I $(INCLUDE_FOLDER) $(GLEW_LIB) $(GLFW_LIB) \
	$(SDL_LIB) $(SDL_MIXER_LIB) -framework OpenGL

clean:
	@rm -f $(NAME)

re: clean all

.PHONY: all clean re
