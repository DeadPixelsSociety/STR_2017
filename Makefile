CXX        = c++
CXXFLAGS   = -Wall -Wextra -Og -g -std=c++14
LDFLAGS    = -lsfml-graphics -lsfml-window -lsfml-system
BIN_DIR    = bin
SRC_DIR    = src
OBJ_DIR    = obj
SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.cpp,obj/%.o,$(SRC))
EXEC       = str
BIN       := $(BIN_DIR)/$(EXEC)
RM         = rm -rf

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $$< -o $$@
endef

.PHONY: all run clean mrproper

all: $(OBJ_DIR) $(BIN_DIR) $(BIN)

run: all
	@cd $(BIN_DIR) && ./$(EXEC)

$(BIN): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

mrproper: clean
	$(RM) $(BIN_DIR)

$(foreach odir,$(OBJ_DIR),$(eval $(call make-goal,$(odir))))
