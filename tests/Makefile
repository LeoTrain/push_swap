PUSH_SWAP_DIR=../push_swap
PUSH_SWAP=$(PUSH_SWAP_DIR)/push_swap

.PHONY: all clean fclean re

all: $(PUSH_SWAP)
	./test

$(PUSH_SWAP): 
	$(MAKE) -C $(PUSH_SWAP_DIR)

clean:
	$(MAKE) clean -C $(PUSH_SWAP_DIR)

fclean:
	$(MAKE) fclean -C $(PUSH_SWAP_DIR)

re: fclean $(PUSH_SWAP)
