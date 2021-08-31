.DEFAULT_GOAL := test

EXERCISE ?= ""
EXERCISES = $(shell find ./exercises/practice -maxdepth 1 -mindepth 1 -type d | cut -s -d '/' -f4 | sort)
OUTDIR ?= "tmp"

copy-exercise:
	if [ -f exercises/practice/$(EXERCISE)/src/*.res ]; then \
		echo "Copying $(EXERCISE)"; \
        	cp exercises/practice/$(EXERCISE)/.meta/*.res $(OUTDIR)/src/; \
        	cp exercises/practice/$(EXERCISE)/tests/*.res $(OUTDIR)/tests/; \
	fi

copy-exercises:
	@echo "Copying exercises for testing..."
	@mkdir -p $(OUTDIR)/src
	@mkdir -p $(OUTDIR)/tests
	@for exercise in $(EXERCISES); do EXERCISE=$$exercise $(MAKE) -s copy-exercise || exit 1; done

# Remove the OUTDIR
clean:
	@echo "Cleaning tmp directory..."
	@rm -rf $(OUTDIR)
