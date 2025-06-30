PUSH_SWAP_DIR=../push_swap
PUSH_SWAP=$(PUSH_SWAP_DIR)/push_swap

TESTS_DIR=tests
TESTS = under100.txt over100.txt only0.txt minmax.txt 100args.txt 500args.txt wrongargs.txt

.PHONY: all clean fclean re $(basename $(TESTS))

all: $(PUSH_SWAP)
	./test_mac

$(PUSH_SWAP): 
	$(MAKE) -C $(PUSH_SWAP_DIR)

clean:
	$(MAKE) clean -C $(PUSH_SWAP_DIR)

fclean:
	$(MAKE) fclean -C $(PUSH_SWAP_DIR)

re: fclean $(PUSH_SWAP)
