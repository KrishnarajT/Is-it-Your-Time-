# This is a makefile to make statically link all the needed usual libraries of SFML into an exe on Windows. 
# This template can be used for compiling and linking single files that use SFML. 

# The usual system here is that there will be an include folder, and a lib folder. The include folder will have all the header files
# and the lib folder will have all the library files and the dll folder will have the dlls if needed. The library files will have yet 
# another SFML folder, that contains only the SFML libraries. This is because those libraries need that to be in their relative path to 
# be called as SFML/___.lib and the same goes with the header files for SFML. This makes it necessary to have a folder inside the include
# folder, but is also convenient, as you can put your own files inside that folder, which may include files like custom header files, or 
# custom libraries. 


## STATIC LINKING ##

CXX := g++
# Enter the name of the cpp file without the extention
NAME := Source
LDFLAGS := -L$(CURDIR)/lib/SFML
LDLIBS := -lsfml-graphics-s \
	-lfreetype -lsfml-window-s -lopengl32 -lgdi32 \
	-lsfml-audio-s -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-lsfml-network-s -lws2_32 -lsfml-system-s -lwinmm \
	-lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d \
	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system \

IDIR := -I$(CURDIR)/include


# Target
$(NAME).exe: $(NAME).o
	$(CXX) $(NAME).o $(LDFLAGS) $(LDLIBS) -o $(NAME).exe

# Compiling object files. 
$(NAME).o: $(NAME).cpp
	$(CXX) -DSFML_STATIC -c $(NAME).cpp $(IDIR) 

all: $(NAME);

clean: 
	del *.o



## DYNAMIC  LINKING ##

# If you wanna dynamically link the SFML Files, this is the way to do it. You will have to include the dll files right besides the exe file
# in your directory if you want them to work, and you will also have to bundle them with the package in the same way. 



# CXX := g++
# # Enter the name of the cpp file without the extention
# NAME := Dino_Game
# LDFLAGS := -L$(CURDIR)/lib/SFML

# # Always link these in the GWANS format. Graphics comes first. system last. 
# # The ones ending with -d are debug libraries, and the ones without that are the release libraries. 
# # When using an IDE to compile and link make sure to add them to the settings accordingly in the right order. 

# LDLIBS := -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-network \
# -lsfml-system -lsfml-audio-d -lsfml-graphics-d -lsfml-window-d \
# -lsfml-network-d -lsfml-system-d

# IDIR := -I$(CURDIR)/include


# # Target
# $(NAME).exe: $(NAME).o
# 	$(CXX) $(NAME).o $(LDFLAGS) $(LDLIBS) -o $(NAME).exe

# # Compiling object files. 
# $(NAME).o: $(NAME).cpp
# 	$(CXX) -c $(NAME).cpp $(IDIR) 

# all: $(NAME);

# clean: 
# 	del *.o
