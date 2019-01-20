# flash_info
# Copyright (C) 2019 by WarOfDevil
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= flash_info


all: dep $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

dep:
	@$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -MM ./$(SRC)/*.cpp > .dependencies

clean:
	-rm -f $(EXECUTABLE) *.o .dependencies *~
