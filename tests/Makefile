PUSH_SWAP_DIR=../push_swap
PUSH_SWAP=$(PUSH_SWAP_DIR)/push_swap

TESTS_DIR=tests
TESTS = under100.txt over100.txt only0.txt maxmin.txt

.PHONY: all clean fclean re $(basename $(TESTS))

all: $(basename $(TESTS))

$(basename $(TESTS)): $(PUSH_SWAP)
	@echo "Running test $@"
	./$(PUSH_SWAP) $(shell cat $(TESTS_DIR)/$@.txt)

$(PUSH_SWAP): 
	@echo "Building push_swap"
	$(MAKE) -C $(PUSH_SWAP_DIR)

clean:
	$(MAKE) -C $(PUSH_SWAP_DIR) clean

fclean:
	$(MAKE) -C $(PUSH_SWAP_DIR) fclean

re: fclean all
