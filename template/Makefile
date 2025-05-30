DUNE = opam exec -- dune

.DEFAULT_GOAL := help

.PHONY: help
help: ## Print this help message
	@echo "List of available make commands";
	@echo "";
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2}';
	@echo "";

.PHONY: install
install: ## Install development and test dependencies
	opam update
	opam install . --with-test --deps-only

.PHONY: build
build: ## Build the project
	$(DUNE) build

.PHONY: test
test: ## Run built tests using node
	$(DUNE) build @runtest --no-buffer

.PHONY: run
run: ## Run the built JS script with node
	$(DUNE) build
	node _build/default/app/app.js

.PHONY: build_verbose
build_verbose: ## Build the project
	$(DUNE) build --verbose

.PHONY: clean
clean: ## Clean build artifacts and other generated files
	$(DUNE) clean

.PHONY: format
format: ## Format the codebase with ocamlformat
	$(DUNE) build @fmt --auto-promote

.PHONY: format-check
format-check: ## Checks if format is correct
	$(DUNE) build @fmt

.PHONY: watch
watch: ## Watch for the filesystem and rebuild on every change
	$(DUNE) build --watch
