CXX        = c++
CXXFLAGS   = -Wall -Wextra -Og -g -std=c++14
LDFLAGS    = -lsfml-graphics -lsfml-window -lsfml-system
EXEC       = str
SRC_DIR    = src
OBJ_DIR    = obj
SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.cpp,obj/%.o,$(SRC))
RM         = rm -rf

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $$< -o $$@
endef

.PHONY: all clean mrproper

all: $(OBJ_DIR) str

str: $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

mrproper: clean
	$(RM) $(EXEC)

$(foreach odir,$(OBJ_DIR),$(eval $(call make-goal,$(odir))))
