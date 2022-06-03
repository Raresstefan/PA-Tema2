# Darius-Florentin Neatu <neatudarius@gmail.com>

# Exemplu de Makefile pentru tema

# tag-uri obligatorii (nume + comportament identic)
# build    => compileaza toata tema
#             (ATENTIE! E important - NU compilati in tag-urile de run. Sesizati?)
# run-p$ID => ruleaza problema cu ID-ul specificat (1, 2, 3, 4)
# clean    => sterge toate fisierele generate

# restul este la alegerea studentului
# TODO


# nume necesar (build)

# define targets
TARGETS=curatare beamdrone curse

build:
	g++ beamdrone.cpp -o beamdrone
	g++ curse.cpp -o curse
	g++ curatare.cpp -o curatare

run-p1:
	./curatare
run-p2:
run-p3:
	./beamdrone
run-p4:
	./curse
clean:
	rm -f $(TARGETS)

.PHONY: pack clean