CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -ggdb -Wall -Wextra -Wshadow -Wconversion

all: help

help:
	@echo "# PERDI #"
	@echo "        make new -- Agregar un problema y sus casos de test"
	@echo "        make run_<problema> -- Corre un problema en sus tests"
	@echo "        make <problema>.problema -- Compila un problema"
	@echo ""
	@echo "TODO: Poner un script para agregar casos de test"

new: data
	"$$(git rev-parse --show-toplevel)/scripts/new"

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

run_%: %.problema
	@for caso in data/$*_*.in; do \
		echo "[Nuestra] $$caso"; \
		./$^ < $$caso; \
		echo "[Esperado] $$caso"; \
		cat $${caso%.in}.out; \
	done;

data:
	@mkdir data

%.problema: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.problema

.PHONY: new clean all run_%
.PRECIOUS: %.problema
