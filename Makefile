.DEFAULT_GOAL := test

EXERCISE ?= ""
IGNOREDIRS := "^(\.git|docs|bin|node_modules|.idea|.vscode)$$"
EXERCISES = $(shell find ./exercises -maxdepth 1 -mindepth 1 -type d | cut -d'/' -f3 | sort | grep -Ev $(IGNOREDIRS))

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

SOURCE_PKG_MD5 ?= "`./bin/md5-hash ./package.json`"
PKG_FILES= $(shell find ./exercises/*/* -maxdepth 1 -name package.json)
SOURCE_PKG_LOCK_MD5 ?= "`./bin/md5-hash ./package-lock.json`"
PKG_LOCK_FILES= $(shell find ./exercises/*/* -maxdepth 1 -name package-lock.json)

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

# copy package.json and package-lock.json for single exercise
copy-package-file:
	@cp package.json exercises/$(EXERCISE)/package.json
	@cp package-lock.json exercises/$(EXERCISE)/package-lock.json

# copy package files to all exercise directories
sync-package-files:
	@echo "Syncing package.json and package-lock.json..."
	@for exercise in $(EXERCISES); do EXERCISE=$$exercise $(MAKE) -s copy-package-file || exit 1; done

# check all package.json and package-lock.json are matching
check-package-files:
	@echo "Validation package.json files..."
	@for pkg in $(PKG_FILES); do \
		! ./bin/md5-hash $$pkg | grep -qv $(SOURCE_PKG_MD5) || { echo "$$pkg does not match main package.json.  Please run 'make sync-package-files' locally and commit the results."; exit 1; }; \
	done
	@echo "Validation package-lock.json files..."
	@for pkg in $(PKG_LOCK_FILES); do \
		! ./bin/md5-hash $$pkg | grep -qv $(SOURCE_PKG_LOCK_MD5) || { echo "$$pkg does not match main package.json.  Please run 'make sync-package-files' locally and commit the results."; exit 1; }; \
	done
	@echo "package-file check complete..."

test:
	$(MAKE) -s check-package-files
	$(MAKE) -s copy-all-exercises
	npm run build
	npm run test:ci

# Remove the OUTDIR
clean:
	@echo "Cleaning tmp directory..."
	@rm -rf $(OUTDIR)

.PHONY: clean
