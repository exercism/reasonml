EXERCISE ?= ""
IGNOREDIRS := "^(\.git|docs|bin|node_modules|.idea)$$"
EXERCISES = $(shell find ./exercises -maxdepth 1 -mindepth 1 -type d | cut -d'/' -f3 | sort | grep -Ev $(IGNOREDIRS))

default: testgenerator test

# output directories
OUTDIR ?= "tmp"

# language specific config (tweakable per language)
FILEEXT := "re"
SIGFILEEXT := "rei"
EXAMPLE := "Example.$(FILEEXT)"
SRCFILE := "$(shell echo $(EXERCISE) | sed -r 's/(^|-)([a-z])/\U\2/g')"
TSTFILE := "$(SRCFILE)_test.$(FILEEXT)"
SIGFILE := "$(SRCFILE).$(SIGFILEEXT)"
# Any additional arguments, such as -p for pretty output and others
ARGS ?= ""

# copy example, interface and test files for single exercise to OUTDIR
# Rename Example.re to ExerciseName.re in the process
copy-exercise:
	@cp exercises/$(EXERCISE)/src/$(EXAMPLE) $(OUTDIR)/src/$(SRCFILE).$(FILEEXT)
	@cp exercises/$(EXERCISE)/src/$(SIGFILE) $(OUTDIR)/src/
	@cp exercises/$(EXERCISE)/__tests__/$(TSTFILE) $(OUTDIR)/__tests__/

# copy source files for all exercises to OUTDIR - easier to compile from there
copy-all-exercises:
	@echo "Copying files..."
	@mkdir -p $(OUTDIR)/src
	@mkdir -p $(OUTDIR)/__tests__
	@for exercise in $(EXERCISES); do EXERCISE=$$exercise $(MAKE) -s copy-exercise || exit 1; done

# Remove the OUTDIR
clean:
	@rm -rf $(OUTDIR)

.PHONY: clean
