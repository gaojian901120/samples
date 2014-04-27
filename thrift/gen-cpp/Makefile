GEN_SRC := Demo.cpp demo_php_constants.cpp demo_php_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))
 
THRIFT_DIR := /usr/local/include/thrift
BOOST_DIR := /usr/local/include
 
INC := -I$(THRIFT_DIR) -I$(BOOST_DIR)
 
.PHONY: all clean
 
all: demo_server
 
%.o: %.cpp
	$(CXX) -Wall $(INC) -c $< -o $@
 
demo_server: Demo_server.o $(GEN_OBJ)
	$(CXX) -L/usr/local/lib -lthrift $^ -o $@

clean:
	$(RM) *.o demo_server