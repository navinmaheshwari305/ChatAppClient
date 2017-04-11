CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS = $(SRC:.cpp=.o)

SRC = my_client.cpp clientsocket.cpp

INC = clientsocket.h
 
LIBS =

TARGET = client

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)


clean:
	rm -f $(OBJS) $(TARGET)

.cpp.o :
	$(CXX) -c $< -o $@  $(LIBS) $(INCS) $(FLGS)